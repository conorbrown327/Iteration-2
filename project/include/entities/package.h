#ifndef PACKAGE_H_
#define PACKAGE_H_

#include <string>
#include <vector>
#include "entity_base.h"
#include "entities/customer.h"

namespace csci3081 {

class Package : public EntityBase {
 public:

  Package(std::vector<float> position) { SetPosition(position); SetType(PACKAGE); }
  virtual ~Package() { delete customer_; }
  
  void AssignCustomer(Customer* customer) { customer_ = customer; }

  const Customer* GetCustomer() { return customer_; }
  
  bool IsDynamic() const override { return true; }
  
  float GetWeight() const { return weight_; };
  
  void SetWeight(float weight) {weight_ = weight; }

  void Deliver();

  bool Delivered() { return delivered_; }

 private:
  Customer* customer_;
  float weight_ = 0;
  bool delivered_ = false;
};

}  // namespace csci3081

#endif  // SRC_PACKAGE_H_
