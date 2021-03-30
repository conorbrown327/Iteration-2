#ifndef DRONE_H_
#define DRONE_H_

#include <cmath>
#include <queue>
#include <iostream>
#include <vector>

#include <EntityProject/facade/delivery_system.h>
#include "delivery_agent.h"
#include "entities/package.h"
#include "entities/battery.h"

namespace csci3081 {

class Drone : public DeliveryAgent {
 public:
  Drone(std::vector<float> position) { SetPosition(position); battery_ = new Battery; SetType(DRONE); }

};
}  // namespace csci3081

#endif  // SRC_DRONE_H_
