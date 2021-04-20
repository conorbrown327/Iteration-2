#include "delivery_simulation.h"
#include "entity_base.h"
#include "factories/drone_factory.h"
#include "factories/customer_factory.h"
#include "factories/package_factory.h"
#include "factories/robot_factory.h"
#include "json_helper.h"
#include <limits>
#include "strategy/smart_route.h"

namespace csci3081 {

DeliverySimulation::DeliverySimulation() {
	entity_factory_ = new CompositeFactory();
	AddFactory(new DroneFactory());
	AddFactory(new CustomerFactory());
	AddFactory(new PackageFactory());
	AddFactory(new RobotFactory());
}

DeliverySimulation::~DeliverySimulation() {
	for (auto ent : entities_) {
		delete ent;
	}
	delete entity_factory_;
}

int DeliverySimulation::Uid() { id_++; return id_; }

IEntity* DeliverySimulation::CreateEntity(const picojson::object& val) {
    IEntity* ent = entity_factory_->CreateEntity(val);
    if (ent) {
	  	EntityBase* b = dynamic_cast<EntityBase*>(ent);
	  	b->SetId(this->Uid());
	  	b->Print();
      return ent;
    }
    return NULL;
}

void DeliverySimulation::AddFactory(IEntityFactory* factory) {
	entity_factory_->AddFactory(factory);
}

void DeliverySimulation::AddEntity(IEntity* entity) {
	// Add to entity vector
	if (entity) {
		entities_.push_back(entity);
	} else {
		std::cout << "Null entity attempted to be added" << std::endl;
		return;
	}
}

void DeliverySimulation::SetGraph(const IGraph* graph) {
	graph_ = graph;
}

void DeliverySimulation::ScheduleDelivery(IEntity* package, IEntity* dest) {
	scheduled_delivery_agent = nullptr;

	//determine if drone is available to deliver new package
	bool available_deliverer = false;
	DeliveryAgent* potential_deliverer;
	for (auto e : entities_){
		potential_deliverer = dynamic_cast<DeliveryAgent*>(e);
		if (potential_deliverer){
			if (potential_deliverer->ScheduledPackage() == false){ //drone doesn't have a scheduled package
				available_deliverer = true;
			}
		}
	}

	//if not available deliverer, add package to waiting_packages vector
	if(available_deliverer == false){
		waiting_packages.push_back(package);
		Package* waiting_package = dynamic_cast<Package*>(package);
		Customer* waiting_customer = dynamic_cast<Customer*>(dest);
		waiting_package->AssignCustomer(waiting_customer);
		return;
	}

	Package* p = dynamic_cast<Package*>(package);
	Customer* c = dynamic_cast<Customer*>(dest);
	float min = std::numeric_limits<float>::infinity();
	for (auto e : entities_) {
		DeliveryAgent* d = dynamic_cast<DeliveryAgent*>(e);
		if (d) {
			float score = (d->GetVPosition() - p->GetVPosition()).Magnitude(); //calculating distance from drone to package
			if (score < min){
				if (d->ScheduledPackage()==false && d->IsDynamic()==false){
					min = score;
					scheduled_delivery_agent = d;
				}
			}
		}
	}
	p->Notify(observers_, "scheduled");

   // Set the delivery agents strategy, if not specified or robot then it is a smart route
   if(JsonHelper::ContainsKey(scheduled_delivery_agent->GetDetails(), "path"))
   {
    std::string strategy = JsonHelper::GetString(scheduled_delivery_agent->GetDetails(), "path");
    scheduled_delivery_agent->DetermineStrategy(strategy);
   }

	auto path = scheduled_delivery_agent->GetStrategy()->DetermineRoute(graph_, scheduled_delivery_agent->GetPosition(),
				p->GetPosition());
	p->AssignCustomer(c);
	scheduled_delivery_agent->SetGraph(graph_);
	scheduled_delivery_agent->AssignPackage(p);
	scheduled_delivery_agent->SetRoute(Vector3D::BuildRoute(path));
	scheduled_delivery_agent->SetOriginalRoute(path);
	scheduled_delivery_agent->Notify(observers_, "moving");
}

void DeliverySimulation::AddObserver(IEntityObserver* observer) {
	observers_.push_back(observer);
}

void DeliverySimulation::RemoveObserver(IEntityObserver* observer) {
	observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
}

const std::vector<IEntity*>& DeliverySimulation::GetEntities() const { return entities_; }

void DeliverySimulation::RemoveEntity(IEntity* entity) {
  for (int i = 0; i < entities_.size(); i++) {
    if (entities_[i]->GetId() == entity->GetId()) {
      entities_.erase(entities_.begin() + i);
      return;
    }
  }
}

void DeliverySimulation::Update(float dt) {

	//determine if there is an available deliverer
	bool available_deliverer = false;
	DeliveryAgent* potential_deliverer;
	for (auto e : entities_){
		potential_deliverer = dynamic_cast<DeliveryAgent*>(e);
		if (potential_deliverer){
			if (potential_deliverer->ScheduledPackage() == false){ //drone doesn't have a scheduled package
				if (potential_deliverer->GetRemainingBattery() > 0) { // drone has battery left
					available_deliverer = true;
				}
			}
		}
	}

	//if there is an available deliverer, schedule a delivery for a waiting package
	if (available_deliverer){
		if (!waiting_packages.empty()){
			IEntity* e = waiting_packages[0];
			waiting_packages.erase(waiting_packages.begin());
			Package* p = dynamic_cast<Package*>(e);
			IEntity* customer = dynamic_cast<IEntity*>(p->GetCustomer());
			this->ScheduleDelivery(e, customer);
		}
	}

	for (auto e : entities_){
		DeliveryAgent* d = dynamic_cast<DeliveryAgent*>(e);
		if (d){
			d->Update(dt, observers_);
			if(d->GetRemainingBattery() <= 0) {
				Package* p = d->GetPackage();
				IEntity* e = dynamic_cast<IEntity*>(p);
				IEntity* c = dynamic_cast<IEntity*>(p->GetCustomer());
				this->ScheduleDelivery(e, c);
				
			}
		}
	}
}


// DO NOT MODIFY THE FOLLOWING UNLESS YOU REALLY KNOW WHAT YOU ARE DOING
void DeliverySimulation::RunScript(const picojson::array& script, IEntitySystem* system) const {
  JsonHelper::PrintArray(script);
  IDeliverySystem* deliverySystem = dynamic_cast<IDeliverySystem*>(system);
	if (deliverySystem) {

	    // To store the unadded entities_
	    std::vector<IEntity*> created_entities;

		for (unsigned int i=0; i < script.size(); i++) {
			const picojson::object& object = script[i].get<picojson::object>();
			const std::string cmd = object.find("command")->second.get<std::string>();
			const picojson::object& params = object.find("params")->second.get<picojson::object>();
			// May want to replace the next few if-statements with an enum
			if (cmd == "createEntity") {
				IEntity* entity = NULL;
				entity = deliverySystem->CreateEntity(params);
				if (entity) {
					created_entities.push_back(entity);
				} else {
					std::cout << "Null entity" << std::endl;
				}
			}
			else if (cmd == "addEntity") {
				int ent_index = static_cast<int>(params.find("index")->second.get<double>());
				if (ent_index >= 0 && ent_index < created_entities.size()) {
					deliverySystem->AddEntity(created_entities[ent_index]);
				}
			}
			else if (cmd == "scheduleDelivery" ) {
				int pkg_index = static_cast<int>(params.find("pkg_index")->second.get<double>());
				int dest_index = static_cast<int>(params.find("dest_index")->second.get<double>());
				if (pkg_index >= 0 && pkg_index < system->GetEntities().size()) {
					IEntity* pkg = deliverySystem->GetEntities()[pkg_index];
					if (dest_index >= 0 && pkg_index < system->GetEntities().size()) {
						IEntity* cst = system->GetEntities()[dest_index];
						if (pkg && cst) {
							deliverySystem->ScheduleDelivery(pkg, cst);
						}
					}
				}
				else {
					std::cout << "Failed to schedule delivery: invalid indexes" << std::endl;
				}
			}
		}
	}
}

}
