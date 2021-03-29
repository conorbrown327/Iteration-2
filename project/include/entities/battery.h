#ifndef BATTERY_H_
#define BATTERY_H_

#include <iostream>

namespace csci3081 {

class Battery {
 public:
  ~Battery() {}
  Battery() {}
  Battery(float max_charge);
  bool IsDead() { return dead_battery_; }
  float ChargeLeft() { return remaining_battery_; }
  void DepleteBattery(float dt);

 private:
  bool dead_battery_ = false;
  float max_charge_ = 10000;
  float remaining_battery_ = 10000;
};

}  // namespace csci3081

#endif  // SRC_BATTERY_H_
