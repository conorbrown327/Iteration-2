#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/entities/battery.h"
#include <EntityProject/entity.h>


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class BatteryTest : public ::testing::Test {
  protected:
   virtual void SetUp() {
     battery = Battery(100);
   }
   virtual void TearDown() {}

   Battery battery;
  };

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(BatteryTest, BatteryConstructed) {
  EXPECT_EQ(battery.IsDead(), false);
  EXPECT_EQ(battery.ChargeLeft(), 100);
}

TEST_F(BatteryTest, BatteryDepleted) {
  battery.DepleteBattery(10);

  EXPECT_EQ(battery.IsDead(), false);
  EXPECT_EQ(battery.ChargeLeft(), 90);

  battery.DepleteBattery(90);

  EXPECT_EQ(battery.IsDead(), true);
  EXPECT_EQ(battery.ChargeLeft(), 0);
}
}  // namespace csci3081
