#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include <string>

#include <EntityProject/entity_factory.h>
#include "entities/drone.h"

namespace csci3081 {

class DroneFactory : public IEntityFactory {
 public:
  DroneFactory();
  ~DroneFactory();
  IEntity* CreateEntity(const picojson::object &val) override;

 private:
};

}

#endif  // SRC_DRONE_FACTORY_H_
