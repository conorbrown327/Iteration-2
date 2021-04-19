/**
 * @file delivery_agent.h
 */

#ifndef DELIVERY_AGENT_H_
#define DELIVERY_AGENT_H_

#include <cmath>
#include <queue>
#include <iostream>
#include <vector>
#include <string>

#include <EntityProject/facade/delivery_system.h>
#include "entity_base.h"
#include "entities/package.h"
#include "entities/battery.h"
#include "strategy/I_Strategy.h"
#include "strategy/smart_route.h"
#include "strategy/beeline_route.h"
#include "strategy/parabolic_route.h"
#include "json_helper.h"

namespace csci3081 {

class DeliveryAgent : public EntityBase {
 public:
 DeliveryAgent() {}
  virtual ~DeliveryAgent() {
    delete battery_;
    delete strategy_;
  }

  void Update(float dt, std::vector<IEntityObserver*> observers);

  void AssignPackage(Package* p) { scheduled_package = p; }
  bool ScheduledPackage() { return (scheduled_package != nullptr); }
  bool HasPackage(Package* p) { return has_package; }
  Package* GetPackage() { return scheduled_package; }

  void SetGraph(const IGraph* graph) { graph_ = graph; }
  float GetRemainingBattery() const { return battery_->ChargeLeft(); };
  const std::vector<Vector3D>& GetRoute() const { return route_; }
  bool IsDynamic() const override { return is_moving; }
  void AssignBattery(Battery* b) { battery_ = b; }

  void SetRoute(std::vector<Vector3D> route) { route_ = route; routeTarget_ = 0; }

  void SetOriginalRoute(std::vector<std::vector<float>> route){original_route = route;}

  void Notify(std::vector<IEntityObserver*> observers, std::string value);

  void SetStrategy(IStrategy* strategy) { strategy_ = strategy; }
  IStrategy* GetStrategy() { return strategy_; }
  void DetermineStrategy(std::string strategy);

protected:
  std::vector<Vector3D> route_;
  std::vector<std::vector<float>> original_route;
  const IGraph* graph_;
  IStrategy* strategy_ = new Smart();
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

#endif  // SRC_DELIVERY_AGENT_H_
