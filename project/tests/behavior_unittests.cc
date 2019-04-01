/*
 * This file is used by the CS3081W auto-grading system.
 *
 * Please note, the assessment tests for grading, will use the same include
 * files, class names, and function names for accessing students' code that you
 * find in this file.  So students, if you write your code so that it passes
 * these feedback tests, you can be assured that the auto-grader will at least
 * be able to properly link with your code.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <gtest/gtest.h>
#include "src/behavior.h"
#include "src/wheel_velocity.h"
#include "src/pose.h"
#include "src/love.h"


 /******************************************************
* TEST FEATURE SetUp
*******************************************************/

class Behaviortest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    bLove = new csci3081::Love();
  }

  virtual void TearDown() {
    delete bLove;
  }
  csci3081::Love * bLove;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(Behaviortest, LoveBehavior) {
  csci3081::WheelVelocity * wv_ptr = new csci3081::WheelVelocity();
  bLove->getWheelVelocity(0, 0, 0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0);
  EXPECT_EQ(wv_ptr->right, 0);
};
/*
TEST_F(Behaviortest, AggressiveBehavior) {
  csci3081::WheelVelocity * wv_ptr = new csci3081::WheelVelocity();
  bAggressive->getWheelVelocity(0, 0, 0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0);
  EXPECT_EQ(wv_ptr->right, 0);
};

TEST_F(Behaviortest, NoBehavior) {
  csci3081::WheelVelocity * wv_ptr = new csci3081::WheelVelocity();
  bNone->getWheelVelocity(0, 0, 0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0);
  EXPECT_EQ(wv_ptr->right, 0);
};
TEST_F(Behaviortest, CowardBehavior) {
  csci3081::WheelVelocity * wv_ptr = new csci3081::WheelVelocity();
  bCoward->getWheelVelocity(0, 0, 0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0);
  EXPECT_EQ(wv_ptr->right, 0);
};
TEST_F(Behaviortest, ExploreBehavior) {
  csci3081::WheelVelocity * wv_ptr = new csci3081::WheelVelocity();
  bExplore->getWheelVelocity(0, 0, 0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0);
  EXPECT_EQ(wv_ptr->right, 0);
}; */
