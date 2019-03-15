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
/*class FactoryLighttest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    arena = new csci3081::Arena();
  }
  virtual void TearDown() {
    delete arena;
  }
  csci3081::Arena * arena;
};*/
class FactoryLighttest : public ::testing::Test {

 protected:
  virtual void SetUp() {
    factory = new csci3081::FactoryLight();
  }
  std::string json = "{\"type:\":\"Light\"\"x\":500,\"y\":350,\"r\":30}";
  json_value* config_ = new json_value();
  std::string err = parse_json(*config_, json);
  csci3081::Light * fl = factory->Create(config_->get<json_object>());

  virtual void TearDown() {
    delete factory;
  }
  csci3081::FactoryLight * factory;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

/*TEST_F(FactoryLighttest, Constructor) {
  auto bv = new csci3081::FactoryLight(); //intialize a factory
  auto light = bv->Create();
  
  csci3081::Pose position = light->get_pose();
  int x = position.x;
  int y = position.y;
  EXPECT_EQ(x, 200);
  EXPECT_EQ(y, 200);
  
  //EXPECT_EQ(light->get_color(), csci3081::kGreen);
  EXPECT_EQ(light->get_type(), csci3081::kLight);
  EXPECT_EQ(light->get_radius(), 30);
  EXPECT_EQ(light->get_id(), csci3081::Light::count);
  EXPECT_EQ(light->is_mobile(), true);
  EXPECT_EQ(light->get_speed(), 3);
};*/
TEST_F(FactoryLighttest, Create) {
  EXPECT_EQ(fl->get_pose().x, 500);
  EXPECT_EQ(fl->get_pose().y, 350);
};



