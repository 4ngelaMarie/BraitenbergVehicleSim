/**
 * @file braitenberg_vehicle.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <ctime>
#include "src/braitenberg_vehicle.h"
#include "src/params.h"
#include "src/love.h"
#include "src/none.h"
#include "src/aggressive.h"
#include "src/coward.h"
#include "src/explore.h"

class SensorLightLove;

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

int BraitenbergVehicle::count = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

BraitenbergVehicle::BraitenbergVehicle() :
  light_sensors_(), wheel_velocity_(), light_behavior_(kNone),
  food_behavior_(kNone), light_behavior_ptr_{new None()},      //  added here
  food_behavior_ptr_{new None()}, closest_light_entity_(NULL),
  closest_food_entity_(NULL), defaultSpeed_(5.0) {
  set_type(kBraitenberg);
  motion_behavior_ = new MotionBehaviorDifferential(this);
  light_sensors_.push_back(Pose());
  light_sensors_.push_back(Pose());
  set_color(BRAITENBERG_COLOR);
  set_pose(ROBOT_INIT_POS);

  wheel_velocity_ = WheelVelocity(0, 0);
  // Set ID
  count++;
  set_id(count);
}

void BraitenbergVehicle::TimestepUpdate(__unused unsigned int dt) {
  collision_counter++;
  if (collision_counter == 20) {
    set_heading(static_cast<int>((get_pose().theta - 45)) % 360);
  } else if (collision_counter == 100) {
    collision_counter--;
  }
  if (is_moving()) {
    motion_behavior_->UpdatePose(dt, wheel_velocity_);
  }
  UpdateLightSensors();
}

void BraitenbergVehicle::HandleCollision(__unused EntityType ent_type,
                                         __unused ArenaEntity * object) {
  set_heading(static_cast<int>((get_pose().theta + 180)) % 360);
  collision_counter = 1;
}

void BraitenbergVehicle::SenseEntity(const ArenaEntity& entity) {
  const ArenaEntity** closest_entity_ = NULL;
  if (entity.get_type() == kLight) {
    closest_entity_ = &closest_light_entity_;
  } else if (entity.get_type() == kFood) {
    closest_entity_ = &closest_food_entity_;
  }

  if (!closest_entity_) {
    return;
  }

  if (!*closest_entity_) {
    *closest_entity_ = &entity;
  }

  double distance = (this->get_pose()-entity.get_pose()).Length();
  double closest_distance =
  (this->get_pose()-(*closest_entity_)->get_pose()).Length();
  if (distance < closest_distance) {
    *closest_entity_ = &entity;
    closest_distance = distance;
  }
  if (closest_distance > 100.0) {
    *closest_entity_ = NULL;
  }
}

void BraitenbergVehicle::Update() {
  WheelVelocity* light_wv_ptr = new WheelVelocity();
  WheelVelocity* food_wv_ptr = new WheelVelocity();
  // WheelVelocity light_wheel_velocity = WheelVelocity(0, 0);
  food_behavior_ptr_->getWheelVelocity(
    get_sensor_reading_left(closest_food_entity_),
    get_sensor_reading_right(closest_food_entity_),
    defaultSpeed_, food_wv_ptr);

  light_behavior_ptr_->getWheelVelocity(
  get_sensor_reading_left(closest_food_entity_),
  get_sensor_reading_right(closest_food_entity_),
  defaultSpeed_, light_wv_ptr);


/*
  switch (light_behavior_) {
    case kExplore:
      set_color({255, 204, 51});
      light_wheel_velocity = WheelVelocity(
        1.0/get_sensor_reading_right(closest_light_entity_),
         1.0/get_sensor_reading_left(closest_light_entity_), defaultSpeed_);
      break;
    case kLove:
      set_color({255, 204, 51});
      light_wheel_velocity = WheelVelocity(
        1.0/get_sensor_reading_left(closest_light_entity_),
         1.0/get_sensor_reading_right(closest_light_entity_), defaultSpeed_);
      break;
    case kCoward:
      set_color({255, 204, 51});
      light_wheel_velocity = WheelVelocity(
        get_sensor_reading_left(closest_light_entity_),
         get_sensor_reading_right(closest_light_entity_), defaultSpeed_);
      break;
    case kAggressive:
      set_color({255, 204, 51});
      light_wheel_velocity = WheelVelocity(
        get_sensor_reading_right(closest_light_entity_),
         get_sensor_reading_left(closest_light_entity_), defaultSpeed_);
      break;
    case kNone:
    default:
      numBehaviors--;
      break;
  }
  WheelVelocity food_wheel_velocity = WheelVelocity(0, 0);

  switch (food_behavior_) {
    case kExplore:
      set_color({0, 0, 255});
      food_wheel_velocity = WheelVelocity(
        1.0/get_sensor_reading_right(closest_food_entity_),
        1.0/get_sensor_reading_left(closest_food_entity_), defaultSpeed_);
      break;
    case kLove:
      set_color({0, 0, 255});
      light_wheel_velocity = WheelVelocity(
        1.0/get_sensor_reading_left(closest_food_entity_),
         1.0/get_sensor_reading_right(closest_food_entity_), defaultSpeed_);
      break;
    case kCoward:
      set_color({0, 0, 255});
      light_wheel_velocity = WheelVelocity(
        get_sensor_reading_left(closest_food_entity_),
         get_sensor_reading_right(closest_food_entity_), defaultSpeed_);
      break;
    case kAggressive:
      set_color({0, 0, 255});
      light_wheel_velocity = WheelVelocity(
        get_sensor_reading_right(closest_food_entity_),
         get_sensor_reading_left(closest_food_entity_), defaultSpeed_);
      break;
    case kNone:
    default:
      numBehaviors--;
      break;
  } */

  int numBehaviors = 2;    // FIGURE THIS PART OUT
  if (numBehaviors) {
    if (food_behavior_ && light_behavior_) {
      set_color(BRAITENBERG_COLOR);
    }
    wheel_velocity_ = WheelVelocity(
      (light_wv_ptr->left + food_wv_ptr->left)/numBehaviors,
      (light_wv_ptr->right + food_wv_ptr->right)/numBehaviors,
      defaultSpeed_);
  } else {
    set_color(BRAITENBERG_COLOR);
    wheel_velocity_ = WheelVelocity(0, 0);
  }
  delete food_wv_ptr;    //  added here
  delete light_wv_ptr;	 //   added here
}

std::string BraitenbergVehicle::get_name() const {
  return "Braitenberg " + std::to_string(get_id());
}

std::vector<Pose> BraitenbergVehicle::get_light_sensors_const() const {
  return light_sensors_;
}

std::vector<Pose> BraitenbergVehicle::get_light_sensors() {
  return light_sensors_;
}

double BraitenbergVehicle::get_sensor_reading_left(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[0]).Length());
  }

  return 0.0001;
}

double BraitenbergVehicle::get_sensor_reading_right(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[1]).Length());
  }

  return 0.0001;
}

void BraitenbergVehicle::UpdateLightSensors() {
  for (unsigned int f = 0; f < light_sensors_.size(); f++) {
    Pose& pos = light_sensors_[f];
    if (f == 0) {
      pos.x = get_pose().x + get_radius() * cos(deg2rad(get_pose().theta - 40));
      pos.y = get_pose().y + get_radius() * sin(deg2rad(get_pose().theta - 40));
    } else {
      pos.x = get_pose().x + get_radius() * cos(deg2rad(get_pose().theta + 40));
      pos.y = get_pose().y + get_radius() * sin(deg2rad(get_pose().theta + 40));
    }
  }
}

void BraitenbergVehicle::LoadFromObject(json_object* entity_config_ptr) {
  json_object& entity_config = *entity_config_ptr;
  ArenaEntity::LoadFromObject(entity_config_ptr);
  if (entity_config.find("light_behavior") != entity_config.end()) {
      light_behavior_ = get_behavior_type(
        entity_config["light_behavior"].get<std::string>());
        set_light_behavior(light_behavior_);
  }
  if (entity_config.find("food_behavior") != entity_config.end()) {
      food_behavior_ = get_behavior_type(
        entity_config["food_behavior"].get<std::string>());
        set_food_behavior(food_behavior_);
  }

  UpdateLightSensors();
}

NAMESPACE_END(csci3081);
