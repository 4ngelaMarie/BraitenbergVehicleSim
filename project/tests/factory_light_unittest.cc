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
#include "src/factory_light.h"
#include "src/entity_type.h"
#include "src/params.h"
#include "src/arena.h"
#include "src/arena_entity.h"
#include "src/pose.h"
#include "src/light.h"

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/

class FactoryLighttest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    factory = new csci3081::FactoryLight();
    std::string json = "{\"type\":\"Light\", \"x\":500,\"y\":350,\"r\":29}";
    json_value* config_ = new json_value();
    std::string err = parse_json(*config_, json);
	json_object& entity_config = config_->get<json_object>();
	//json_object* entity_config_ptr = &entity_config;
	fl = factory->Create(entity_config);
  }

  virtual void TearDown() {
    delete factory;
  }
  csci3081::FactoryLight * factory;
  csci3081::Light * fl;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryLighttest, Create) {
  EXPECT_EQ(fl->get_pose().x, 500);
  EXPECT_EQ(fl->get_pose().y, 350);
  EXPECT_EQ(fl->get_type(), csci3081::kLight);
  EXPECT_EQ(fl->get_radius(), 29);
  EXPECT_EQ(fl->get_id(), csci3081::Light::count);
  EXPECT_EQ(fl->is_mobile(), true);
  EXPECT_EQ(fl->get_speed(), 3);
  
  csci3081::RgbColor color = fl->get_color();
  EXPECT_EQ(color.r, 255);
  EXPECT_EQ(color.g, 255);
  EXPECT_EQ(color.b, 255);
};



