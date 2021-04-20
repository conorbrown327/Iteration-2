/*
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
 *****************************************************************************

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

TEST_F(BatteryTest, DefaultValueTest) {
    Battery b;
    //int x = b.GetCharge();
    bool y = b.IsDead();
    EXPECT_EQ(x, 10000);
    EXPECT_EQ(y, false);
}

TEST_F(BatteryTest, ChangeChargeTest) {
    Battery b;
    //b.ChangeCharge(-1000);
    //EXPECT_EQ(b.GetCharge(), 9000);
    //b.ChangeCharge(500);
    //EXPECT_EQ(b.GetCharge(), 9500);
}

TEST_F(BatteryTest, ChargeOutsideOfRangeTest) {
    Battery b;
    //EXPECT_EQ(b.GetCharge(), 10000);
    //b.ChangeCharge(1000);
    //EXPECT_EQ(b.GetCharge(), 10000);
    //b.ChangeCharge(-12000);
    EXPECT_EQ(b.GetCharge(), 0);
}

TEST_F(BatteryTest, DeadTest) {
    Battery b;
    EXPECT_EQ(b.IsDead(), false);
    //b.ChangeCharge(-5000);
    EXPECT_EQ(b.IsDead(), false);
    //b.ChangeCharge(-5000);
    EXPECT_EQ(b.IsDead(), true);
    //b.ChangeCharge(1);
    EXPECT_EQ(b.IsDead(), false);
}
} // namespace csci3081

*/
