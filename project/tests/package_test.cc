#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/entities/package.h"
#include <EntityProject/entity.h>


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class PackageTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    packagejson = JsonHelper::CreateJsonObject();
  }
  virtual void TearDown() {}

  picojson::object packagejson;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(PackageTest, PackageConstructed) {
 JsonHelper::AddStringToJsonObject(packagejson, "name", "Parker");
 JsonHelper::AddFloatToJsonObject(packagejson, "radius", 1);

 std::vector<float> position_init;
 position_init.push_back(498.292);
 position_init.push_back(253.883);
 position_init.push_back(-228.623);
 JsonHelper::AddStdFloatVectorToJsonObject(packagejson, "position", position_init);

 std::vector<float> direction_init;
 direction_init.push_back(1);
 direction_init.push_back(2);
 direction_init.push_back(0);
 JsonHelper::AddStdFloatVectorToJsonObject(packagejson, "direction", direction_init);

 picojson::object config(packagejson);
 auto position = JsonHelper::GetStdFloatVector(config, "position");
 Package package(position);
 package.SetDetails(packagejson);

 EXPECT_EQ(package.GetId(), -98);
 EXPECT_EQ(package.GetName(), "Parker");
 EXPECT_EQ(package.GetPosition(), position_init);
 EXPECT_EQ(package.GetDirection(), direction_init);
 EXPECT_EQ(package.GetRadius(), 1);
 EXPECT_EQ(package.GetVersion(), 0);
 EXPECT_EQ(package.IsDynamic(), true);

}

}  // namespace csci3081
