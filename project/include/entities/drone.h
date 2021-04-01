#ifndef DRONE_H_
#define DRONE_H_

#include <cmath>
#include <queue>
#include <iostream>
#include <vector>

#include <EntityProject/facade/delivery_system.h>
#include "entity_base.h"
#include "entities/package.h"
#include "entities/battery.h"

namespace csci3081 {

class Drone : public EntityBase {
 public:
  virtual ~Drone() {
    delete battery_;
  }
  Drone(std::vector<float> position) { SetPosition(position); battery_ = new Battery; SetType(DRONE); }

  void Update(float dt);

  void AssignPackage(Package* p) { scheduled_package = p; }
  bool ScheduledPackage() { return (scheduled_package != nullptr); }
  bool HasPackage(Package* p) { return has_package; }

  void SetGraph(const IGraph* graph) { graph_ = graph; }
  float GetRemainingBattery() const { return battery_->ChargeLeft(); };
  const std::vector<Vector3D>& GetRoute() const { return route_; }
  bool IsDynamic() const override { return is_moving; } //changed "return true" to "return is_moving"

  void SetRoute(std::vector<Vector3D> route) { route_ = route; routeTarget_ = 0; }

 private:
  std::vector<Vector3D> route_;
  const IGraph* graph_;
  int routeTarget_ = -1;
  bool has_package = false;
  Battery* battery_ = nullptr;
  bool is_moving = false;
  Package* scheduled_package = nullptr;
  void DropOffPackage();
  void PickUpPackage();
  void UpdateScheduledPackage() { if (has_package) scheduled_package->SetPosition(position_);  }

};
}  // namespace csci3081

#endif  // SRC_DRONE_H_
