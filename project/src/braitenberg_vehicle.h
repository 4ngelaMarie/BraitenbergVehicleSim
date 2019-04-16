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
#include "src/behavior_enum.h"
#include "src/behavior.h"
#include "src/love.h"
#include "src/none.h"
#include "src/aggressive.h"
#include "src/coward.h"
#include "src/explore.h"
#include "src/food.h"


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

class BraitenbergVehicle : public ArenaMobileEntity, public Subject {
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
  /**
   * @brief Update the wheel velocities and color of the BraitenbergVehicle.
   * Notify any observers of the update if any are subscribed. Wheel
   * velocities are weighted differently if BraitenbergVehicle is nearing
   * starvation.
   */
  void Update() override;

  /**
   * @brief Change the movement state of the BraitenbergVehicle.
   */
  void HandleCollision(EntityType ent_type,
                       ArenaEntity * object = NULL) override;
  /**
   * @brief Sense other entities in arena other than itself.
   */
  void SenseEntity(const ArenaEntity& entity);
  /**
   * @brief Returns the ID of the BraitenbergVehicle.
   */
  std::string get_name() const override;

  std::vector<Pose> get_light_sensors_const() const;

  std::vector<Pose> get_light_sensors();

  void UpdateLightSensors();
  /**
   * @brief Create an instance of a BraitenbergVehicle based of
   * parameters given in a json file.
   */
  void LoadFromObject(json_object* entity_config) override;
  /**
   * @brief Returns BraitenbergVehicle's current light behavior.
   */
  Behavior get_light_behavior() { return light_behavior_; }

  /** 
   *@brief For each behavior: Create new behavior instances 
   * These behaviors uniquely affect the BV wheel velocity 
   */
  void set_light_behavior(Behavior behavior) {
    light_behavior_ = behavior;
    delete light_behavior_ptr_;
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
  /**
   * @brief Returns BraitenbergVehicle's current food behavior.
   */
  Behavior get_food_behavior() { return food_behavior_; }
  /** 
   *@brief For each behavior: Create new behavior instances 
   * These behaviors uniquely affect the BV wheel velocity 
   */
  void set_food_behavior(Behavior behavior) {
    food_behavior_ = behavior;
    delete food_behavior_ptr_;
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
  /**
   * @brief Returns BraitenbergVehicle's current robot behavior.
   */
  Behavior get_bv_behavior() { return bv_behavior_; }
  /** 
   *@brief For each behavior: Create new behavior instances 
   * These behaviors uniquely affect the BV wheel velocity 
   */
  void set_bv_behavior(Behavior behavior) {
    bv_behavior_ = behavior;
    delete bv_behavior_ptr_;
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
  /**
   * @brief BraitenbergVehicle's starvation counter is reset to zero.
   * Food's position is updated to a new location to inspire new 
   * robot trajectories. 
   */
  void ConsumeFood(Food * fp);
  /**
   * @brief Sets the BraitenbergVehicle's graphics_arena_pointer to
   * point to the velocity_observer. Observer is then notified of
   * updated wheel velocities upon BraitenbergVehicle::Update().
   */
  void Subscribe(Observer *observer) override;
  /**
   * @brief Sets BraitenbergVehicle's graphics_arena_pointer, more 
   * specifically, the velocity_observer, to NULL.
   */
  void Unsubscribe() override;
  /**
   * @brief Notifies any subscribers of the current wheel velocities
   * contributions from each behavior.
   */
  void Notify(WheelVelocity* light_wv_ptr,
    WheelVelocity* food_wv_ptr, WheelVelocity* bv_wv_ptr) override;
  /**
   * @brief Returns BraitenbergVehicle's left sensor readings for given
   * entity.
   */
  double get_sensor_reading_left(const ArenaEntity* entity);
  /**
   * @brief Returns BraitenbergVehicle's right sensor readings for given
   * entity.
   */
  double get_sensor_reading_right(const ArenaEntity* entity);
  /**
   * @brief The BraitenbergVehicle's ID.
   */
  static int count;
  /**
   * @brief Counter that changes the angle heading after collision.
   */
  int collision_counter_ = 20;
  /**
   * @brief Couner that keeps track if vehicle is nearing starvation.
   * Starvation occurs after 600 iterations.
   */
  int starvation_counter_ = 0;

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
