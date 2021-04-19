/**
 * @file customer.h
 */
#ifndef BATTERY_H_
#define BATTERY_H_

#include <iostream>

namespace csci3081 {

  /*******************************************************************************
   * Class Definitions
   ******************************************************************************/
  /**
   * @brief This is class to represent batteries in the simulation.
   *
   *
   *
   */

class Battery {
 public:
   ///Destructor
  ~Battery() {}
  ///Default contructor: sets the max charge to 10000
  Battery() {}
  ///Constructor: sets the max charge to the passed in value
  Battery(float max_charge);
  ///returns true if the battery is dead, and false otherwise
  bool IsDead() { return dead_battery_; }
  ///returns the remaining charge left on the battery
  float ChargeLeft() { return remaining_battery_; }
  ///depletes the battery's charge by the passed in value
  void DepleteBattery(float dt);

 private:
  bool dead_battery_ = false;
  float max_charge_ = 10000;
  float remaining_battery_ = 10000;
};

}  // namespace csci3081

#endif  // SRC_BATTERY_H_
