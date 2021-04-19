/**
 * @file package.h
 */
#ifndef PACKAGE_H_
#define PACKAGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <vector>
#include "entity_base.h"
#include "entities/customer.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is class to represent packages in the simulation.
 *
 *
 *
 */
class Package : public EntityBase {
 public:
  ///Constructor: sets initial position to the position passed in
  Package(std::vector<float> position) { SetPosition(position); SetType(PACKAGE); }

  virtual ~Package() {
    //delete customer_;
  }

  ///Assigns customer_ class variable to the Customer* passed in
  void AssignCustomer(Customer* customer) { customer_ = customer; }

  ///Returns customer entity assigned to this package
  Customer* GetCustomer() { return customer_; }

  ///Returns a bool variable representing if the package is moving or not
  bool IsDynamic() const override { return true; }

  ///Returns the weight of the package
  float GetWeight() const { return weight_; };

  ///Sets the weight_ class variable to the weight passed in
  void SetWeight(float weight) {weight_ = weight; }

  void Deliver();

  bool Delivered() { return delivered_; }

  ///Notifys all attached observers with the string passed in
  void Notify(std::vector<IEntityObserver*> observers, std::string value);

 private:
  Customer* customer_;
  float weight_ = 0;
  bool delivered_ = false;
};

}  // namespace csci3081

#endif  // SRC_PACKAGE_H_
