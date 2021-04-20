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
 * @brief This class represents a battery
 *
 * This class will store charge for a delivery agent.
 */


class Battery {
 public:
   ///Destructor
  ~Battery() {}
  ///Default contructor: sets the max charge to 10000
  Battery() {}
  ///Constructor: sets the max charge to the passed in value
  Battery(float max_charge);
  
  /// Returns true if the battery is dead, false otherwise
  bool IsDead() { return dead_battery_; }
  
  /// Returns the remaining charge
  float ChargeLeft() { return remaining_battery_; }
  
  /// Decreases the charge in the battery

  void DepleteBattery(float dt);

 private:
  bool dead_battery_ = false;
  float max_charge_ = 10000;
  float remaining_battery_ = 10000;
};

}  // namespace csci3081

#endif  // SRC_BATTERY_H_
