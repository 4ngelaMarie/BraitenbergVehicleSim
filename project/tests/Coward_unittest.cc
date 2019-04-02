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
#include "src/coward.h"


 /******************************************************
* TEST FEATURE SetUp
*******************************************************/

class CowardBehaviortest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    bCoward = new csci3081::Coward();
  }

  virtual void TearDown() {
    delete bCoward;
  }
  csci3081::Coward * bCoward;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(CowardBehaviortest, CowardBehavior) {
  csci3081::WheelVelocity * wv_ptr = new csci3081::WheelVelocity();
  bCoward->getWheelVelocity(0, 0, 0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0)<< "FAIL: speed exceeds maximum\n";
  EXPECT_EQ(wv_ptr->right, 0)<< "FAIL: speed exceeds maximum\n";
  bCoward->getWheelVelocity(0, 0, 5.0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0)<< "FAIL: should be no change to zero speed\n";
  EXPECT_EQ(wv_ptr->right, 0)<< "FAIL: should be no change to zero speed\n";
  bCoward->getWheelVelocity(3.0, 4.0, 5.0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 3.0)<< "FAIL: velocities not updated correctly\n";
  EXPECT_EQ(wv_ptr->right, 4.0)<< "FAIL: velocities not updated correctly\n";
  bCoward->getWheelVelocity(40.0, 1.0, 50.0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 40.0)<< "FAIL: velocities not updated correctly\n";
  EXPECT_EQ(wv_ptr->right, 1.0)<< "FAIL: velocities not updated correctly\n";
  bCoward->getWheelVelocity(6.0, 7.0, 5.0, wv_ptr);
  EXPECT_EQ(wv_ptr->right, 5.0) << "FAIL: speed exceeds maximum\n";
  EXPECT_EQ(wv_ptr->left, 5.0) << "FAIL: speed exceeds maximum\n"; 
};

