#include "gtest/gtest.h"
#include "json_helper.h"
#include "../include/lib/vector3d.h"
#include <EntityProject/entity.h>


#include <iostream>

namespace csci3081 {

using entity_project::IEntity;

class Vector3DTest : public ::testing::Test {
  protected:
   virtual void SetUp() {
     vector3d_1 = Vector3D(1, 2, 3);
     vector3d_2 = Vector3D(0, 0, 0);

     std::vector<float> v;
     v.push_back(1);
     v.push_back(1);
     v.push_back(1);
   }
   virtual void TearDown() {}

   Vector3D vector3d_1;
   Vector3D vector3d_2;
   std::vector<float> v;
  };

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

 TEST_F(Vector3DTest, Vector3DEqualsEquals) {
   EXPECT_EQ(vector3d_1==vector3d_2, false);

   std::vector<float> equal;
   equal.push_back(1);
   equal.push_back(2);
   equal.push_back(3);

   EXPECT_EQ(vector3d_1==equal, true);
 }

 TEST_F(Vector3DTest, Vector3DEquals) {
  vector3d_2 = vector3d_1;

  EXPECT_EQ(vector3d_2==vector3d_1, true);
}

TEST_F(Vector3DTest, Vector3DPlus) {
  std::vector<float> expected;
  expected.push_back(2);
  expected.push_back(3);
  expected.push_back(4);

  EXPECT_EQ(vector3d_1 + v == expected, true);
}

/*TEST_F(Vector3DTest, Vector3DMinus) {
  std::vector<float> expected;
  expected.push_back(1);
  expected.push_back(2);
  expected.push_back(3);

  EXPECT_EQ(vector3d_1 - v == expected, true);
}

TEST_F(Vector3DTest, Vector3DTimes) {
  std::vector<float> expected;
  expected.push_back(1);
  expected.push_back(4);
  expected.push_back(9);

  EXPECT_EQ(vector3d_1 * 2 == expected, true);
}

TEST_F(Vector3DTest, Vector3DDividedBy) {
  std::vector<float> expected;
  expected.push_back(0.5);
  expected.push_back(1);
  expected.push_back(1.5);

  EXPECT_EQ(vector3d_1 / 2 == expected, true);
}

TEST_F(Vector3DTest, Vector3DPlusEquals) {
  std::vector<float> expected;
  expected.push_back(2);
  expected.push_back(3);
  expected.push_back(4);

  vector3d_1 += v;

  EXPECT_EQ(vector3d_1 == expected, true);
}

TEST_F(Vector3DTest, Vector3DMinusEquals) {
  std::vector<float> expected;
  expected.push_back(1);
  expected.push_back(2);
  expected.push_back(3);

  vector3d_1 -= v;

  EXPECT_EQ(vector3d_1 == expected, true);
}

TEST_F(Vector3DTest, Vector3DTimesEquals) {
  std::vector<float> expected;
  expected.push_back(1);
  expected.push_back(4);
  expected.push_back(9);

  vector3d_1 *= 2;

  EXPECT_EQ(vector3d_1 == expected, true);
}*/

}  // namespace csci3081
