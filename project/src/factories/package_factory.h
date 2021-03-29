#ifndef PACKAGE_FACTORY_H_
#define PACKAGE_FACTORY_H_

#include <EntityProject/entity_factory.h>
#include "entities/package.h"

namespace csci3081 {

class PackageFactory : public IEntityFactory {
 public:
  PackageFactory();
  ~PackageFactory();
  IEntity* CreateEntity(const picojson::object &val) override;
};
}  // namespace csci3081

#endif  // SRC_PACKAGE_FACTORY_H_
