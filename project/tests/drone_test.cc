#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/entities/drone.h"
#include <EntityProject/entity.h>

#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class DroneTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    dronejson = JsonHelper::CreateJsonObject();
  }
  virtual void TearDown() {}

  picojson::object dronejson;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(DroneTest, DroneConstructed) {
 JsonHelper::AddStringToJsonObject(dronejson, "name", "Drew");
 JsonHelper::AddFloatToJsonObject(dronejson, "radius", 1);

 std::vector<float> position_init;
 position_init.push_back(498.292);
 position_init.push_back(253.883);
 position_init.push_back(-228.623);
 JsonHelper::AddStdFloatVectorToJsonObject(dronejson, "position", position_init);

 std::vector<float> direction_init;
 direction_init.push_back(1);
 direction_init.push_back(2);
 direction_init.push_back(0);
 JsonHelper::AddStdFloatVectorToJsonObject(dronejson, "direction", direction_init);

 picojson::object config(dronejson);
 auto position = JsonHelper::GetStdFloatVector(config, "position");
 Drone drone(position);
 drone.SetDetails(dronejson);

 EXPECT_EQ(drone.GetId(), -98);
 EXPECT_EQ(drone.GetName(), "Drew");
 EXPECT_EQ(drone.GetPosition(), position_init);
 EXPECT_EQ(drone.GetDirection(), direction_init);
 EXPECT_EQ(drone.GetRadius(), 1);
 EXPECT_EQ(drone.GetVersion(), 0);
 EXPECT_EQ(drone.IsDynamic(), false);

}

}  // namespace csci3081
