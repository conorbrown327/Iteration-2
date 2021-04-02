#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/entities/robot.h"
#include <EntityProject/entity.h>


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class RobotTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    robotjson = JsonHelper::CreateJsonObject();
  }
  virtual void TearDown() {}

  picojson::object robotjson;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(RobotTest, RobotConstructed) {
 JsonHelper::AddStringToJsonObject(robotjson, "name", "Robby");
 JsonHelper::AddFloatToJsonObject(robotjson, "radius", 1);

 std::vector<float> position_init;
 position_init.push_back(498.292);
 position_init.push_back(253.883);
 position_init.push_back(-228.623);
 JsonHelper::AddStdFloatVectorToJsonObject(robotjson, "position", position_init);

 std::vector<float> direction_init;
 direction_init.push_back(1);
 direction_init.push_back(2);
 direction_init.push_back(0);
 JsonHelper::AddStdFloatVectorToJsonObject(robotjson, "direction", direction_init);

 picojson::object config(robotjson);
 auto position = JsonHelper::GetStdFloatVector(config, "position");
 Robot robot(position);
 robot.SetDetails(robotjson);

 EXPECT_EQ(robot.GetId(), -98);
 EXPECT_EQ(robot.GetName(), "Robby");
 EXPECT_EQ(robot.GetPosition(), position_init);
 EXPECT_EQ(robot.GetDirection(), direction_init);
 EXPECT_EQ(robot.GetRadius(), 1);
 EXPECT_EQ(robot.GetVersion(), 0);
 EXPECT_EQ(robot.IsDynamic(), false);

}

}  // namespace csci3081
