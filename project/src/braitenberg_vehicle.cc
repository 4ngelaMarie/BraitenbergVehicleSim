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
#include <cmath>
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
  food_behavior_(kNone), bv_behavior_(kNone),
  light_behavior_ptr_{new None()}, food_behavior_ptr_{new None()},
  bv_behavior_ptr_{new None()}, gav_observer(NULL),
  closest_light_entity_(NULL), closest_food_entity_(NULL),
  closest_bv_entity_(NULL), defaultSpeed_(5.0) {
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
  collision_counter_++;
  starvation_counter_++;
  if (collision_counter_ == 20) {
    set_heading(static_cast<int>((get_pose().theta - 45)) % 360);
  } else if (collision_counter_ == 100) {
    collision_counter_--;
  }
  if (starvation_counter_ == 600) {
    set_color({255, 200, 200});
    set_type(kGhost);
    wheel_velocity_ = WheelVelocity(0, 0);
    WheelVelocity* wv_ptr = &wheel_velocity_;
    if (gav_observer != NULL) {           // UPDATE VELOCITY_OBSERVER
    Notify(wv_ptr, wv_ptr, wv_ptr);
    }
  }
  if (is_moving()) {
    motion_behavior_->UpdatePose(dt, wheel_velocity_);
  }
  UpdateLightSensors();
}

void BraitenbergVehicle::HandleCollision(__unused EntityType ent_type,
                                         __unused ArenaEntity * object) {
  if (ent_type == kPredator) {
    starvation_counter_ = 0;
    set_color({255, 200, 200});
    set_type(kGhost);
    wheel_velocity_ = WheelVelocity(0, 0);
    WheelVelocity* wv_ptr = &wheel_velocity_;
    if (gav_observer != NULL) {           // UPDATE VELOCITY_OBSERVER
    Notify(wv_ptr, wv_ptr, wv_ptr);
    }
  } else if (ent_type == kFood) {
    starvation_counter_ = 0;
  } else {
  set_heading(static_cast<int>((get_pose().theta + 180)) % 360);
  collision_counter_ = 1;
  }
}
void BraitenbergVehicle::ConsumeFood(Food * fp) {
    starvation_counter_ = 0;
    double x = this->get_pose().x;
    double y = this->get_pose().y;
    if (x < 250) {
      x += 200;
    } else {
      x -= 200;
    }
    if (y < 250) {
     y += 220;
    } else {
     y -= 180;
    }
    fp->set_pose({x, y});
}
void BraitenbergVehicle::SenseEntity(const ArenaEntity& entity) {
  const ArenaEntity** closest_entity_ = NULL;
  if (entity.get_type() == kLight) {
    closest_entity_ = &closest_light_entity_;
  } else if (entity.get_type() == kFood) {
    closest_entity_ = &closest_food_entity_;
  } else if (entity.get_type() == kBraitenberg) {  // BV does not
      if (entity.get_id() != this->get_id()) {     // sense itself
        closest_entity_ = &closest_bv_entity_;
      }
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
/**** if BV is starving, it needs to sense food from far away ****/
  if (closest_distance > 100.0  && starvation_counter_ < 400) {
    *closest_entity_ = NULL;
  }
}
void BraitenbergVehicle::Subscribe(Observer *observer) {
  gav_observer = observer;    //  only 1 subscription at a time
}
void BraitenbergVehicle::Unsubscribe() {
  gav_observer = NULL;
}
void BraitenbergVehicle::Notify(WheelVelocity* light_wv_ptr,
  WheelVelocity* food_wv_ptr, WheelVelocity* bv_wv_ptr) {
    gav_observer->OnUpdate(light_wv_ptr, food_wv_ptr, bv_wv_ptr);
}
void BraitenbergVehicle::Update() {
  WheelVelocity* light_wv_ptr = new WheelVelocity();
  WheelVelocity* food_wv_ptr = new WheelVelocity();
  WheelVelocity* bv_wv_ptr = new WheelVelocity();

  int numBehaviors = 3;
  if (food_behavior_ == kNone) {
    numBehaviors--;
  } else {
    set_color({0, 0, 255});
  }
  if (light_behavior_ == kNone) {
    numBehaviors--;
  } else {
  set_color({255, 204, 51});
  }
  if (bv_behavior_ == kNone) {
    numBehaviors--;
  }
  food_behavior_ptr_->getWheelVelocity(
    get_sensor_reading_left(closest_food_entity_),
    get_sensor_reading_right(closest_food_entity_),
    defaultSpeed_, food_wv_ptr);
  light_behavior_ptr_->getWheelVelocity(
    get_sensor_reading_left(closest_light_entity_),
    get_sensor_reading_right(closest_light_entity_),
    defaultSpeed_, light_wv_ptr);
  bv_behavior_ptr_->getWheelVelocity(
    get_sensor_reading_left(closest_bv_entity_),
    get_sensor_reading_right(closest_bv_entity_),
    defaultSpeed_, bv_wv_ptr);
/*** Amplify its food detecting velocity ***/
  if (starvation_counter_ > 500) {
    set_color({ 0, 210, 240});
    if (food_behavior_ != kNone) {
      double ratio = get_sensor_reading_right(closest_food_entity_)/
        get_sensor_reading_left(closest_food_entity_);
      food_wv_ptr->right = 3.0/ratio;
      food_wv_ptr->left = 3.0*ratio;
    }
    double weight = 600 - static_cast<double>(starvation_counter_);
    double c1, c2, c3;
    c1 = 1.0/3.0 + (2.0/3.0)*(1.0/weight);
    c2 = 1.0/3.0 - (1.0/3.0)*(1.0/weight);
    c3 = 1.0/3.0 - (1.0/3.0)*(1.0/weight);
    food_wv_ptr->left *= c1;
    food_wv_ptr->right *= c1;
    light_wv_ptr->left *= c2;
    light_wv_ptr->right *= c2;
    bv_wv_ptr->left *= c3;
    bv_wv_ptr->right *= c3;
  } else {
/*** Average velocities here to maintain consistancy ***/
    light_wv_ptr->left /= numBehaviors;
    light_wv_ptr->right /= numBehaviors;
    food_wv_ptr->left /= numBehaviors;
    food_wv_ptr->right /= numBehaviors;
    bv_wv_ptr->left /= numBehaviors;
    bv_wv_ptr->right /= numBehaviors;
  }
  if (gav_observer != NULL) {               // UPDATE VELOCITY_OBSERVER
    Notify(light_wv_ptr, food_wv_ptr, bv_wv_ptr);
  }
  if (numBehaviors) {
    if (numBehaviors > 1 && starvation_counter_ < 400) {
      set_color(BRAITENBERG_COLOR);
    }
    wheel_velocity_ = WheelVelocity(
      (light_wv_ptr->left + food_wv_ptr->left + bv_wv_ptr->left),
      (light_wv_ptr->right + food_wv_ptr->right + bv_wv_ptr->right),
      defaultSpeed_);
  } else if (starvation_counter_ < 400) {
    set_color(BRAITENBERG_COLOR);
    wheel_velocity_ = WheelVelocity(0, 0);
  }
  delete food_wv_ptr;    //  added here
  delete light_wv_ptr;   //   added here
  delete bv_wv_ptr;      //   added here
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
  if (entity_config.find("bv_behavior") != entity_config.end()) {
      bv_behavior_ = get_behavior_type(
        entity_config["bv_behavior"].get<std::string>());
        set_bv_behavior(bv_behavior_);
  }
  UpdateLightSensors();
}

NAMESPACE_END(csci3081);
