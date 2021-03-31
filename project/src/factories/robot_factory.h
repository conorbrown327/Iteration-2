#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include <string>

#include <EntityProject/entity_factory.h>
#include "entities/robot.h"

namespace csci3081 {

class RobotFactory : public IEntityFactory {
 public:
  RobotFactory();
  ~RobotFactory();
  IEntity* CreateEntity(const picojson::object &val) override;
};

}

#endif  // SRC_ROBOT_FACTORY_H_
