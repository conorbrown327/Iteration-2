#ifndef ROBOT_H_
#define ROBOT_H_

#include <cmath>
#include <queue>
#include <iostream>
#include <vector>

#include <EntityProject/facade/delivery_system.h>
#include "delivery_agent.h"
#include "entities/package.h"
#include "entities/battery.h"

namespace csci3081 {

class Robot : public DeliveryAgent {
 public:
  Robot(std::vector<float> position) { SetPosition(position); battery_ = new Battery; SetType(ROBOT); }

};
}  // namespace csci3081

#endif  // SRC_ROBOT_H_
