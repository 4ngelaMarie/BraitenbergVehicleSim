/**
 * @file bv_decorator.cc
 *
 * @copyright 2017 Angela Almquist.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <ctime>
#include <cmath>
#include "src/bv_decorator.h"
#include "src/params.h"

class SensorLightLove;

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

int BVDecorator::count = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

BVDecorator::BVDecorator() : rradius_(15), colour_(BRAITENBERG_COLOR),
  light_sensors_(), wheel_velocity_(), light_behavior_(kNone),
  food_behavior_(kNone), bv_behavior_(kNone), defaultSpeed_(5.0) {
  BraitenbergVehicle::set_type(kBraitenberg);
  motion_behavior_ = new MotionBehaviorDifferential(this);
  light_sensors_.push_back(Pose());
  light_sensors_.push_back(Pose());
  BraitenbergVehicle::set_radius(15);
  wheel_velocity_ = WheelVelocity(0, 0);
  // Set ID
  count++;
  BraitenbergVehicle::set_id(count);
  set_bv_behavior(kAggressive);
  // Set Other Behaviors Randomly
  unsigned int globalseed;
  int behav_num1 = rand_r(&globalseed) % 5;
  int behav_num2 = rand_r(&globalseed) % 5;
    switch (behav_num1) {
      case 0:
        set_light_behavior(kNone);
      break;
      case 1:
        set_light_behavior(kExplore);
      break;
      case 2:
        set_light_behavior(kLove);
      break;
      case 3:
        set_light_behavior(kCoward);
      break;
      case 4:
        set_light_behavior(kAggressive);
      break;
      default:
        set_light_behavior(kNone);
      break;
    }
    switch (behav_num2) {
      case 0:
        set_food_behavior(kNone);
      break;
      case 1:
        set_food_behavior(kExplore);
      break;
      case 2:
        set_food_behavior(kLove);
      break;
      case 3:
        set_food_behavior(kCoward);
      break;
      case 4:
        set_food_behavior(kAggressive);
      break;
      default:
        set_food_behavior(kNone);
      break;
    }
}

std::string BVDecorator::get_name() const {
  return "BVDecorator " + std::to_string(BraitenbergVehicle::get_id());
}

NAMESPACE_END(csci3081);
