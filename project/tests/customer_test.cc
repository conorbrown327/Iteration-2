#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/entities/customer.h"
#include <EntityProject/entity.h>


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class CustomerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    customerjson = JsonHelper::CreateJsonObject();
  }
  virtual void TearDown() {}

  picojson::object customerjson;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(CustomerTest, CustomerConstructed) {
 JsonHelper::AddStringToJsonObject(customerjson, "name", "Carl");
 JsonHelper::AddFloatToJsonObject(customerjson, "radius", 1);

 std::vector<float> position_init;
 position_init.push_back(498.292);
 position_init.push_back(253.883);
 position_init.push_back(-228.623);
 JsonHelper::AddStdFloatVectorToJsonObject(customerjson, "position", position_init);

 std::vector<float> direction_init;
 direction_init.push_back(1);
 direction_init.push_back(2);
 direction_init.push_back(0);
 JsonHelper::AddStdFloatVectorToJsonObject(customerjson, "direction", direction_init);

 picojson::object config(customerjson);
 auto position = JsonHelper::GetStdFloatVector(config, "position");
 Customer customer(position);
 customer.SetDetails(customerjson);

 EXPECT_EQ(customer.GetId(), -98);
 EXPECT_EQ(customer.GetName(), "Carl");
 EXPECT_EQ(customer.GetPosition(), position_init);
 EXPECT_EQ(customer.GetDirection(), direction_init);
 EXPECT_EQ(customer.GetRadius(), 1);
 EXPECT_EQ(customer.GetVersion(), 0);
 EXPECT_EQ(customer.IsDynamic(), false);

}

}  // namespace csci3081
