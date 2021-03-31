#include <vector>
#include "entities/delivery_agent.h"
#include "json_helper.h"

namespace csci3081 {

  void DeliveryAgent::PickUpPackage() {
    auto route = graph_->GetPath(scheduled_package->GetPosition(), scheduled_package->GetCustomer()->GetPosition());
    if (route.size() == 0) printf("There is no path from package to customer!\n");
    routeTarget_ = 0;
    route_ = Vector3D::BuildRoute(route);
    has_package = true;
  }

  void DeliveryAgent::DropOffPackage() {
    has_package = false;
    is_moving = false;
    scheduled_package->Deliver();
    this->SetPosition(scheduled_package->GetCustomer()->GetPosition());
    this->SetDirection({0, 1, 0});
  }


  void DeliveryAgent::Update(float dt) {
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
        } else if (has_package) {
          this->DropOffPackage();
          routeTarget_ = 0;
          route_.clear();
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

}
