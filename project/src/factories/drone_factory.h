/**
 *@file drone_factory.h
 */
#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include <EntityProject/entity_factory.h>
#include "entities/drone.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the factory class that creates drone instnaces
 *
 */

class DroneFactory : public IEntityFactory {
 public:
  DroneFactory();
  ~DroneFactory();

  /// Overriden from the composite, creates drones
  IEntity* CreateEntity(const picojson::object &val) override;
};

}

#endif  // SRC_DRONE_FACTORY_H_
