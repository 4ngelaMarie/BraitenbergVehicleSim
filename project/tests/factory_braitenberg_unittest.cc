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
#include "src/factory_braitenberg.h"
#include "src/entity_type.h"
#include "src/params.h"
#include "src/arena.h"
#include "src/arena_entity.h"
#include "src/pose.h"
#include "src/braitenberg_vehicle.h"

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/

class FactoryBraitenbergtest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    factory = new csci3081::FactoryBraitenberg();
    std::string json = "{\"type\":\"Braitenberg\", \"x\":270,\"y\":270,\"r\":15,\"theta\":215,\"light_behavior\":\"None\",\"food_behavior\":\"Explore\",\"bv_behavior\":\"None\"}";
    json_value* config_ = new json_value();
    std::string err = parse_json(config_, json);
	json_object& entity_config = config_->get<json_object>();
	json_object* entity_config_ptr = &entity_config;
	bv = factory->Create(entity_config_ptr);
  }

  virtual void TearDown() {
    delete factory;
  }
  csci3081::FactoryBraitenberg * factory;
  csci3081::BraitenbergVehicle * bv;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(FactoryBraitenbergtest, Create) {
  EXPECT_EQ(bv->get_pose().x, 270);
  EXPECT_EQ(bv->get_pose().y, 270);
  EXPECT_NEAR(bv->get_pose().theta, 215, 1);
  
  std::string name = "Braitenberg " + std::to_string(bv->get_id());
  EXPECT_EQ(bv->get_name(), name);
 
  EXPECT_EQ(bv->get_light_behavior(), csci3081::kNone);
  EXPECT_EQ(bv->get_food_behavior(), csci3081::kExplore);
  EXPECT_EQ(bv->get_bv_behavior(), csci3081::kNone);
  
  std::vector<csci3081::Pose> light_sensors = bv->get_light_sensors();
  double sensor_left = 1800.0/std::pow(
      1.08, (bv->get_pose()-light_sensors[0]).Length());
  double sensor_right = 1800.0/std::pow(
      1.08, (bv->get_pose()-light_sensors[1]).Length());
  EXPECT_NEAR(bv->get_sensor_reading_left(bv), sensor_left,.5);
  EXPECT_NEAR(bv->get_sensor_reading_right(bv), sensor_right,.5);
  
  EXPECT_EQ(bv->get_type(), csci3081::kBraitenberg);
  EXPECT_EQ(bv->get_radius(), 15);
  EXPECT_EQ(bv->get_id(), csci3081::BraitenbergVehicle::count);
  EXPECT_EQ(bv->is_mobile(), true);
  EXPECT_EQ(bv->get_speed(), 0.0);

  csci3081::RgbColor color = bv->get_color();
  EXPECT_EQ(color.r, 122);
  EXPECT_EQ(color.g, 0);
  EXPECT_EQ(color.b, 25);
};
