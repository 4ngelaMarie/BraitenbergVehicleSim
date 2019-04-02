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
#include "src/none.h"


 /******************************************************
* TEST FEATURE SetUp
*******************************************************/

class NoneBehaviortest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    bNone = new csci3081::None();
  }

  virtual void TearDown() {
    delete bNone;
  }
  csci3081::None * bNone;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(NoneBehaviortest, NoneBehavior) {
  csci3081::WheelVelocity * wv_ptr = new csci3081::WheelVelocity();
  bNone->getWheelVelocity(0, 0, 0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0)<< "FAIL: speed always equals zero for no behavior\n";
  EXPECT_EQ(wv_ptr->right, 0)<< "FAIL: speed always equals zero for no behavior\n";
  bNone->getWheelVelocity(1.0, 4.0, 5.0, wv_ptr);
  EXPECT_EQ(wv_ptr->left, 0) << "FAIL: speed always equals zero for no behavior\n";
  EXPECT_EQ(wv_ptr->right, 0) << "FAIL: speed always equals zero for no behavior\n";
};

