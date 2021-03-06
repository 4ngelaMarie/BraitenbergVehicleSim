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
#include "src/aggressive.h"

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/

class AggressiveBehaviortest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    bAggressive = new csci3081::Aggressive();
  }

  virtual void TearDown() {
    delete bAggressive;
  }
  csci3081::Aggressive * bAggressive;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(AggressiveBehaviortest, AggressiveBehavior) {
  csci3081::WheelVelocity * wv_ptr = new csci3081::WheelVelocity();
  bAggressive->getWheelVelocity(0, 0, 0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0)<< "FAIL: speed exceeds maximum\n";
  EXPECT_EQ(wv_ptr->right, 0)<< "FAIL: speed exceeds maximum\n";
  bAggressive->getWheelVelocity(0, 0, 5.0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0)<< "FAIL: should be no change with zero speed\n";
  EXPECT_EQ(wv_ptr->right, 0)<< "FAIL: should be no change with zero speed\n";
  bAggressive->getWheelVelocity(3.0, 4.0, 5.0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 4.0)<< "FAIL: velocity not updated correctly\n";
  EXPECT_EQ(wv_ptr->right, 3.0)<< "FAIL: velocity not updated correctly\n";
  bAggressive->getWheelVelocity(1.0, 50.0, 60.0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 50.0)<< "FAIL: velocity not updated correctly\n";
  EXPECT_EQ(wv_ptr->right, 1.0)<< "FAIL: velocity not updated correctly\n";
  bAggressive->getWheelVelocity(6.0, 7.0, 5.0, wv_ptr);
  EXPECT_EQ(wv_ptr->right, 5.0) << "FAIL: speed exceeds maximum\n";
  EXPECT_EQ(wv_ptr->left, 5.0) << "FAIL: speed exceeds maximum\n";
};



