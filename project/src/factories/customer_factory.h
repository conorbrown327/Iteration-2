#ifndef CUSTOMER_FACTORY_H_
#define CUSTOMER_FACTORY_H_

#include <EntityProject/entity_factory.h>
#include "entities/customer.h"

namespace csci3081 {

class CustomerFactory : public IEntityFactory {
 public:
  CustomerFactory();
  ~CustomerFactory();
  IEntity* CreateEntity(const picojson::object &val) override;
};

}

#endif  // SRC_CUSTOMER_FACTORY_H_
