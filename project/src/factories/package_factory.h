/**
 *@file package_factory.h
 */
#ifndef PACKAGE_FACTORY_H_
#define PACKAGE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/entity_factory.h>
#include "entities/package.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the factory for creating packages
 *
 */

class PackageFactory : public IEntityFactory {
 public:
  PackageFactory();
  ~PackageFactory();

  /// Overriden from the composite, creates packages
  IEntity* CreateEntity(const picojson::object &val) override;
};

}  // namespace csci3081

#endif  // SRC_PACKAGE_FACTORY_H_
