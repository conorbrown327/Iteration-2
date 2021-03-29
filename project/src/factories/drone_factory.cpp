#include <stdexcept>
#include <fstream>
#include "factories/drone_factory.h"
#include "entities/drone.h"
#include "include/json_helper.h"

using std::string;

namespace csci3081 {

DroneFactory::DroneFactory() {}
DroneFactory::~DroneFactory() {}

IEntity* DroneFactory::CreateEntity(const picojson::object &val) {
  Drone* drone = NULL;
  picojson::object config(val);
  // Check type
  if (config["type"].get<std::string>() == "drone") {
    printf("In Drone Factory\n");
    auto init_pos = JsonHelper::GetStdFloatVector(config, "position");
    drone = new Drone(init_pos);
    drone->SetDetails(val);
  }
  return drone;
}

}  // namespace csci3081
