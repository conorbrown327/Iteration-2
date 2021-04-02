#include <stdexcept>
#include <fstream>
#include "factories/robot_factory.h"
#include "entities/robot.h"
#include "include/json_helper.h"

using std::string;

namespace csci3081 {

RobotFactory::RobotFactory() {}
RobotFactory::~RobotFactory() {}

IEntity* RobotFactory::CreateEntity(const picojson::object &val) {
  Robot* robot = NULL;
  picojson::object config(val);
  // Check type
  if (config["type"].get<std::string>() == "robot") {
    printf("In Robot Factory\n");
    auto init_pos = JsonHelper::GetStdFloatVector(config, "position");
    robot = new Robot(init_pos);
    robot->SetDetails(val);
  }
  return robot;
}

}  // namespace csci3081
