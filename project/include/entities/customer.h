/**
 * @file customer.h
 */
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "entity_base.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is class to represent customers in the simulation.
 *
 *
 *
 */
class Customer : public EntityBase {
 public:
  ///Constructor: sets initial position to the position passed in
  Customer(std::vector<float> position) { SetPosition(position); SetType(CUSTOMER); }
  virtual ~Customer() {}
};

}  // namespace csci3081

#endif  // SRC_CUSTOMER_H_
