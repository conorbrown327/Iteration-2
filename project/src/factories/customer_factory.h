/**
 *@file customer_factory.h
 */
 #ifndef CUSTOMER_FACTORY_H_
#define CUSTOMER_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/entity_factory.h>
#include "entities/customer.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This factory class for creating customers
 *
 */

class CustomerFactory : public IEntityFactory {
 public:
  CustomerFactory();
  ~CustomerFactory();

  /// Overriden from the composite, creates customers
  IEntity* CreateEntity(const picojson::object &val) override;
};

}

#endif  // SRC_CUSTOMER_FACTORY_H_
