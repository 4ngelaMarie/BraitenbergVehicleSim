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
#include "src/factory_food.h"
#include "src/entity_type.h"
#include "src/params.h"
#include "src/arena.h"
#include "src/arena_entity.h"
#include "src/pose.h"
#include "src/food.h"
#include "src/rgb_color.h"

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class FactoryFoodtest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    arena = new csci3081::Arena();
  }
  virtual void TearDown() {
    delete arena;
  }
  csci3081::Arena * arena;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryFoodtest, Constructor) {
  auto bv = new csci3081::FactoryFood(); //intialize a factory
  auto food = bv->Create();
  
  csci3081::Pose position = food->get_pose();
  int x = position.x;
  int y = position.y;
  EXPECT_EQ(x, 400);
  EXPECT_EQ(y, 400);
  
  //EXPECT_PRED_FORMAT1(food->get_color(), csci3081::RgbColorEnum::kGreen);
  
  EXPECT_EQ(food->get_type(), csci3081::kFood);
  EXPECT_EQ(food->get_radius(), 20);
  EXPECT_EQ(food->get_id(), csci3081::Food::count);
  EXPECT_EQ(food->is_mobile(), false);
};



