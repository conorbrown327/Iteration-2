/**
 *@file robot_factory.h
 */
#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include <EntityProject/entity_factory.h>
#include "entities/robot.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the factory for creating robots
 *
 */

class RobotFactory : public IEntityFactory {
 public:
  RobotFactory();
  ~RobotFactory();

  /// Overriden from the composite, creates robots
  IEntity* CreateEntity(const picojson::object &val) override;
};

}

#endif  // SRC_ROBOT_FACTORY_H_
