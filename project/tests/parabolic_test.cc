#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/strategy/I_Strategy.h"
#include "../include/strategy/parabolic_route.h"
#include <EntityProject/entity.h>

#include <iostream>
#include <vector>

namespace csci3081 {

using entity_project::IEntity;

class ParabolicTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
      
  }
  virtual void TearDown() {
      delete para;
  }

  Parabolic* para = new Parabolic();
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(ParabolicTest, TestRoute) {

 std::vector<float> src;
 src.push_back(100);
 src.push_back(100);
 src.push_back(100);

 std::vector<float> dest;
 dest.push_back(0);
 dest.push_back(0);
 dest.push_back(0);

 //std::vector< std::vector<float> > path = para->DetermineRoute(new IGraph(), src, dest);

 //EXPECT_NE(path, nullptr);

}

}  // namespace csci3081
