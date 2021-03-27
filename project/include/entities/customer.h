#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include "entity_base.h"

namespace csci3081 {

class Customer : public EntityBase {
 public:
  Customer(std::vector<float> position) { SetPosition(position); SetType(CUSTOMER); }
  virtual ~Customer() {}
};

}  // namespace csci3081

#endif  // SRC_CUSTOMER_H_
