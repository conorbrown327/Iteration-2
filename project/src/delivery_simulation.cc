#include "delivery_simulation.h"
#include "entity_base.h"
#include "factories/drone_factory.h"
#include "factories/customer_factory.h"
#include "factories/package_factory.h"
#include "json_helper.h"
#include <limits>

namespace csci3081 {

DeliverySimulation::DeliverySimulation() {
	entity_factory_ = new CompositeFactory();
	AddFactory(new DroneFactory());
	AddFactory(new CustomerFactory());
	AddFactory(new PackageFactory());
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
	Package* p = dynamic_cast<Package*>(package);
	Customer* c = dynamic_cast<Customer*>(dest);
	float min = std::numeric_limits<float>::infinity();
	for (auto e : entities_) {
		Drone* d = dynamic_cast<Drone*>(e);
		if (d) {
			float score = (d->GetVPosition() - p->GetVPosition()).Magnitude();
			if (score < min) min = score;
			scheduled_drone = d;
		}
	}
	auto path = graph_->GetPath(scheduled_drone->GetPosition(), p->GetPosition());
	p->AssignCustomer(c);
	scheduled_drone->SetGraph(graph_);
	scheduled_drone->AssignPackage(p);
	scheduled_drone->SetRoute(Vector3D::BuildRoute(path));
}

void DeliverySimulation::AddObserver(IEntityObserver* observer) {}

void DeliverySimulation::RemoveObserver(IEntityObserver* observer) {}

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
	if (scheduled_drone) {
		scheduled_drone->Update(dt); 
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
