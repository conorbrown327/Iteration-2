/**
 * @file drone.h
 */
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

  /*******************************************************************************
   * Class Definitions
   ******************************************************************************/
  /**
   * @brief This is class to represent drones in the simulation.
   *
   *
   *
   */

class Drone : public DeliveryAgent {
 public:
  ///Constructor: sets initial position to the position passed in
  Drone(std::vector<float> position) { SetPosition(position); battery_ = new Battery; SetType(DRONE); }



};
}  // namespace csci3081

#endif  // SRC_DRONE_H_
