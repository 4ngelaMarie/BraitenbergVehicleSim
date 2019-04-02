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
#include "src/love.h"


 /******************************************************
* TEST FEATURE SetUp
*******************************************************/

class LoveBehaviortest : public ::testing::Test {

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

TEST_F(LoveBehaviortest, LoveBehavior) {
  csci3081::WheelVelocity * wv_ptr = new csci3081::WheelVelocity();
  bLove->getWheelVelocity(0, 0, 0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0) << "FAIL: speed exceeds maximum\n";
  EXPECT_EQ(wv_ptr->right, 0)<< "FAIL: speed exceeds maximum\n";
  bLove->getWheelVelocity(0, 0, 5.0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 5.0) << "FAIL: speed exceeds maximum\n";
  EXPECT_EQ(wv_ptr->right, 5.0)<< "FAIL: speed exceeds maximum\n";
  bLove->getWheelVelocity(3.0, 4.0, 5.0, wv_ptr);
  EXPECT_NEAR(wv_ptr->left, .33, .01)<< "FAIL: speed not updated correctly\n";
  EXPECT_EQ(wv_ptr->right, .25)<< "FAIL: speed not updated correctly\n";
  bLove->getWheelVelocity(.01, 4.0, 50.0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 50.0)<<"FAIL: speed exceeds maximum\n";
  EXPECT_EQ(wv_ptr->right, .25)<< "FAIL: speed not updated correctly\n";
  bLove->getWheelVelocity(.1, .1, 5.0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 5.0)<<"FAIL: speed exceeds maximum\n";
  EXPECT_EQ(wv_ptr->right, 5.0)<<"FAIL: speed exceeds maximum\n";
};


