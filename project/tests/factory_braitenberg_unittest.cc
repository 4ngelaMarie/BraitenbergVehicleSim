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
  }
  std::string json = "{\"type:\":\"Braitenberg\"\"x\":270,\"y\":270,\"r\":15,\"theta\":215,\"light_behavior\":\"None\",\"food_behavior\":\"Explore\"}";
  json_value* config_ = new json_value();
  std::string err = parse_json(*config_, json);
  csci3081::BraitenbergVehicle * bv = factory->Create(config_->get<json_object>());
  virtual void TearDown() {
    delete factory;
  }
  csci3081::FactoryBraitenberg * factory;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

/*TEST_F(FactoryBraitenbergtest, Constructor) {
  auto bv = new csci3081::FactoryBraitenberg(); //intialize a factory
  auto robot = bv->Create();
  
  csci3081::Pose position = robot->get_pose();
  int x = position.x;
  int y = position.y;
  int theta = position.theta;
  EXPECT_EQ(x, 500);
  EXPECT_EQ(y, 500);
  EXPECT_NEAR(theta, 0, .01);
  
  std::string name = "Braitenberg " + std::to_string(robot->get_id());
  EXPECT_EQ(robot->get_name(), name);
  
  //EXPECT_PRED_FORMAT1(robot->get_color(), BRAITENBERG_COLOR);
 
  EXPECT_EQ(robot->get_light_behavior(), csci3081::kNone);
  EXPECT_EQ(robot->get_food_behavior(), csci3081::kNone);
  
  EXPECT_NEAR(robot->get_sensor_reading_left(robot), .0001,.00001);
  EXPECT_NEAR(robot->get_sensor_reading_right(robot), .0001,.00001);
  
  EXPECT_EQ(robot->get_type(), csci3081::kBraitenberg);
  EXPECT_EQ(robot->get_radius(), 20);
  EXPECT_EQ(robot->get_id(), csci3081::BraitenbergVehicle::count);
  EXPECT_EQ(robot->is_mobile(), true);
  EXPECT_EQ(robot->get_speed(), 0.0);
};*/

TEST_F(FactoryBraitenbergtest, Create) {
  EXPECT_EQ(bv->get_pose().x, 270);
  EXPECT_EQ(bv->get_pose().y, 270);
};

