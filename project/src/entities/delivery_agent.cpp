#include "entities/delivery_agent.h"

namespace csci3081 {

  void DeliveryAgent::DetermineStrategy(std::string strategy){
    std::cout << "COMPARE: " << strategy.compare("beeline") << std::endl;
    if(!strategy.compare("beeline"))
      strategy_ = new Beeline();
    else if(!strategy.compare("parabolic"))
      strategy_ = new Parabolic();
    else
      strategy_ = new Smart();
  }

  void DeliveryAgent::PickUpPackage() {
    auto route = this->GetStrategy()->DetermineRoute(graph_, scheduled_package->GetPosition(),
				scheduled_package->GetCustomer()->GetPosition());
    //auto route = graph_->GetPath(scheduled_package->GetPosition(), scheduled_package->GetCustomer()->GetPosition());
    if (route.size() == 0) printf("There is no path from package to customer!\n");
    routeTarget_ = 0;
    route_ = Vector3D::BuildRoute(route);
    original_route = route;
    has_package = true;
  }

  void DeliveryAgent::DropOffPackage() {
    has_package = false;
    is_moving = false;
    scheduled_package->Deliver();
    this->SetPosition(scheduled_package->GetCustomer()->GetPosition());
    this->SetDirection({0, 1, 0});
  }


  void DeliveryAgent::Update(float dt, std::vector<IEntityObserver*> observers) {
    if(scheduled_package == nullptr){ //if there is no scheduled_package, do not move DeliveryAgent
      return;
    }
    if(battery_->IsDead()) {
      //this->Notify(observers, "idle");
      return;
    }
    if (routeTarget_ >= route_.size()) {
      routeTarget_ = 0;
      route_.clear();
      is_moving = false;
    }
    if (!scheduled_package->Delivered() && !is_moving) { is_moving = true; }

    Vector3D target_position = route_[routeTarget_];
    Vector3D position = Vector3D(this->GetPosition());
    if ((position -target_position).Magnitude() <= this->GetRadius()) {
      if (routeTarget_ == route_.size() - 1) {
        printf("Reached last node\n");
        if (!has_package && this->ScheduledPackage()) {
          this->PickUpPackage();
          this->Notify(observers, "moving");
          scheduled_package->Notify(observers, "en route");
        } else if (has_package) {
          this->DropOffPackage();
          scheduled_package->Notify(observers, "delivered");
          this->Notify(observers, "idle");
          routeTarget_ = 0;
          route_.clear();
          scheduled_package = nullptr;
        } else {
          printf("DeliveryAgent likely did not receive proper route");
        }
      }
      if (routeTarget_ < route_.size()) {
        printf("incrementing routeTarget_: %i of %i\n", routeTarget_, (int) route_.size() - 1);
        routeTarget_ += 1;
      }
    }
    if (is_moving) {
      Vector3D direction = (target_position - position).Normalize();
      Vector3D next = position += (direction.Normalize() *= dt);
      this->SetPosition(next.ToVector());
      this->UpdateScheduledPackage();
      battery_->DepleteBattery(dt); // Deplete Battery
    }
  }

  void DeliveryAgent::Notify(std::vector<IEntityObserver*> observers, std::string value){
    if (value.compare("idle") == 0){
      picojson::object notification = JsonHelper::CreateJsonNotification();
      JsonHelper::AddStringToJsonObject(notification, "value", value);
      picojson::value delivery_agent_value = JsonHelper::ConvertPicojsonObjectToValue(notification);
      for (IEntityObserver* observer : observers){
        observer->OnEvent(delivery_agent_value, *this);
      }
    }
    else if(value.compare("moving") == 0){
      picojson::object notification = JsonHelper::CreateJsonNotification();
      JsonHelper::AddStringToJsonObject(notification, "value", value);
      JsonHelper::AddStdVectorVectorFloatToJsonObject(notification, "path", original_route);
      picojson::value delivery_agent_value = JsonHelper::ConvertPicojsonObjectToValue(notification);
      for (IEntityObserver* observer : observers){
        observer->OnEvent(delivery_agent_value, *this);
      }
    }

  }

}
