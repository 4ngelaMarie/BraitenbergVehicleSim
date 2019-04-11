/**
 * @file braitenberg_vehicle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_BRAITENBERG_VEHICLE_H_
#define SRC_BRAITENBERG_VEHICLE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/common.h"
#include "src/arena_mobile_entity.h"
#include "src/motion_behavior_differential.h"
#include "src/subject.h"

#include "src/wheel_velocity.h"
#include "src/behavior_enum.h"  // needed for arena_graphics buttons
#include "src/behavior.h"
#include "src/love.h"
#include "src/none.h"
#include "src/aggressive.h"
#include "src/coward.h"
#include "src/explore.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/* @brief Entity class to represent a Braitenberg Vehicle
 *
 * A braitenberg vehicle is a simple machine that is used to show how simple
 * concepts (in this case wiring) can give way to complex looking behavior. In
 * this simulation, Braitenberg vehicles contain sensors, which can be hooked
 * up in four different ways, and thus they can exhibit four different behaviors
 */

class BraitenbergVehicle : public ArenaMobileEntity, public Subject {    // CHANGED HERE
 public:
  /**
   * @brief Default constructor.
   */
  BraitenbergVehicle();

  /**
   * Deleting the copy assignment and copy constructor. required now with
   *  inclusion of references to sensors and motion_handler/behavior
   */
  BraitenbergVehicle(const BraitenbergVehicle & rhs) = delete;

  BraitenbergVehicle operator=(const BraitenbergVehicle & rhs) = delete;

  /**
   * @brief Update the BraitenbergVehicle's position and velocity after the
   * specified duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(unsigned int dt) override;

  void Update() override;

  /**
   * @brief Change the movement state of the BraitenbergVehicle.
   */
  void HandleCollision(EntityType ent_type,
                       ArenaEntity * object = NULL) override;

  void SenseEntity(const ArenaEntity& entity);

  std::string get_name() const override;

  std::vector<Pose> get_light_sensors_const() const;

  std::vector<Pose> get_light_sensors();

  void UpdateLightSensors();

  void LoadFromObject(json_object* entity_config) override;

  Behavior get_light_behavior() { return light_behavior_; }

  void set_light_behavior(Behavior behavior) {
    light_behavior_ = behavior;
    delete light_behavior_ptr_;   // is this correct?
    switch (light_behavior_) {
      case kExplore:
        light_behavior_ptr_ = new Explore();
      break;
      case kLove:
        light_behavior_ptr_ = new Love();
      break;
      case kAggressive:
        light_behavior_ptr_ = new Aggressive();
      break;
      case kNone:
        light_behavior_ptr_ = new None();
      break;
      case kCoward:
        light_behavior_ptr_ = new Coward();
      break;
      default:
        light_behavior_ptr_ = new None();
      break;
    }
  }

  Behavior get_food_behavior() { return food_behavior_; }

  void set_food_behavior(Behavior behavior) {
    food_behavior_ = behavior;
    delete food_behavior_ptr_;    // is this correct?
    switch (food_behavior_) {
      case kExplore:
        food_behavior_ptr_ = new Explore();
      break;
      case kLove:
        food_behavior_ptr_ = new Love();
      break;
      case kAggressive:
        food_behavior_ptr_ = new Aggressive();
      break;
      case kNone:
        food_behavior_ptr_ = new None();
      break;
      case kCoward:
        food_behavior_ptr_ = new Coward();
      break;
      default:
        food_behavior_ptr_ = new None();
      break;
    }
  }

  Behavior get_bv_behavior() { return bv_behavior_; }

  void set_bv_behavior(Behavior behavior) {
    bv_behavior_ = behavior;
    delete bv_behavior_ptr_;    // is this correct?
    switch (bv_behavior_) {
      case kExplore:
        bv_behavior_ptr_ = new Explore();
      break;
      case kLove:
        bv_behavior_ptr_ = new Love();
      break;
      case kAggressive:
        bv_behavior_ptr_ = new Aggressive();
      break;
      case kNone:
        bv_behavior_ptr_ = new None();
      break;
      case kCoward:
        bv_behavior_ptr_ = new Coward();
      break;
      default:
        bv_behavior_ptr_ = new None();
      break;
    }
  }
 void Subscribe(Observer *observer) override;
 void Unsubscribe() override;
 void Notify(WheelVelocity* light_wv_ptr, 
    WheelVelocity* food_wv_ptr, WheelVelocity* bv_wv_ptr) override;
  double get_sensor_reading_left(const ArenaEntity* entity);

  double get_sensor_reading_right(const ArenaEntity* entity);

  static int count;

  int collision_counter = 1;

 private:
  std::vector<Pose> light_sensors_;
  MotionBehaviorDifferential * motion_behavior_{nullptr};
  WheelVelocity wheel_velocity_;
  Behavior light_behavior_;
  Behavior food_behavior_;
  Behavior bv_behavior_;
  BehaviorEntity* light_behavior_ptr_;  // added
  BehaviorEntity* food_behavior_ptr_;   // added
  BehaviorEntity* bv_behavior_ptr_;     // added
  Observer* gav_observer;
  const ArenaEntity* closest_light_entity_;
  const ArenaEntity* closest_food_entity_;
  const ArenaEntity* closest_bv_entity_;
  double defaultSpeed_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_VEHICLE_H_
