#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/strategy/I_Strategy.h"
#include "../include/strategy/beeline_route.h"
#include <EntityProject/entity.h>

#include <iostream>
#include <vector>

namespace csci3081 {

using entity_project::IEntity;

class BeelineTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
      
  }
  virtual void TearDown() {
      delete bee;
  }

  Beeline* bee = new Beeline();
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(BeelineTest, TestRoute) {

 std::vector<float> src;
 src.push_back(100);
 src.push_back(100);
 src.push_back(100);

 std::vector<float> dest;
 dest.push_back(0);
 dest.push_back(0);
 dest.push_back(0);

 //std::vector< std::vector<float> > path = bee->DetermineRoute(new IGraph(), src, dest);

 //EXPECT_NE(path, nullptr);

}

}  // namespace csci3081
