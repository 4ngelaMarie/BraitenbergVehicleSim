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
#include <nanogui/nanogui.h>
#include <string>
#include <fstream>
#include <streambuf>
 
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
    factory = new csci3081::FactoryFood();
    std::string json = "{\"type\": \"Food\", \"x\":100, \"y\":100, \"r\":20, \"theta\": 0.0}";
	json_value* config_ = new json_value();
	std::string err = parse_json(config_, json);
	json_object& entity_config = config_->get<json_object>();
	json_object* entity_config_ptr = &entity_config;
	ff = factory->Create(entity_config_ptr);
  }
  
  virtual void TearDown() {
    delete factory;
  }
  csci3081::FactoryFood * factory;
  csci3081::Food * ff;
};
/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryFoodtest, Create) {
  EXPECT_EQ(ff->get_pose().x, 100);
  EXPECT_EQ(ff->get_pose().y, 100);
  EXPECT_EQ(ff->get_type(), csci3081::kFood);
  EXPECT_EQ(ff->get_radius(), 20);
  EXPECT_EQ(ff->get_id(), csci3081::Food::count);
  EXPECT_EQ(ff->is_mobile(), false);
  
  csci3081::RgbColor color = ff->get_color();
  EXPECT_EQ(color.r, 0);
  EXPECT_EQ(color.g, 255);
  EXPECT_EQ(color.b, 0);
};



