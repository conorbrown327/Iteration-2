#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include <vector>

#include <EntityProject/entity_factory.h>
#include "factories/drone_factory.h"
#include "entity_base.h"

namespace csci3081 {

class CompositeFactory : public IEntityFactory {
 public:
  CompositeFactory();
  ~CompositeFactory();
  IEntity* CreateEntity(const picojson::object &val) override;
  void AddFactory(IEntityFactory* factory);

 private:
  std::vector<IEntityFactory*> factories_;
};

}

#endif  // SRC_COMPOSITE_FACTORY_H_
