/**
 * @file predator.h
 *
 * @copyright 2017 Angela Almquist
 */

#ifndef SRC_PREDATOR_H_
#define SRC_PREDATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/common.h"
#include "src/arena_mobile_entity.h"
#include "src/motion_behavior_differential.h"
#include "src/wheel_velocity.h"
#include "src/behavior_enum.h"  // needed for arena_graphics buttons
#include "src/behavior.h"
#include "src/none.h"
#include "src/aggressive.h"
#include "src/coward.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/* @brief Entity class to represent a Predator
 *
 * A predator is a simple machine that is aggressive towards 
 * braitenberg vehicles, and turns them into ghosts upon collision.
 * Predators do not collide with light or food, but exhibit cowardice
 * behavior towards light.
 */

class Predator : public ArenaMobileEntity {
 public:
  /**
   * @brief Default constructor.
   */
  Predator();

  /**
   * Deleting the copy assignment and copy constructor. required now with
   *  inclusion of references to sensors and motion_handler/behavior
   */
  Predator(const Predator & rhs) = delete;

  Predator operator=(const Predator & rhs) = delete;

  /**
   * @brief Update the Predator's position and velocity after the
   * specified duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(unsigned int dt) override;

  void Update() override;

  /**
   * @brief Change the movement state of the predator
   * if it is colliding with a wall or another predator.
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

  Behavior get_food_behavior() { return food_behavior_; }

  Behavior get_bv_behavior() { return bv_behavior_; }

  void set_light_behavior(Behavior behavior) {
    light_behavior_ = behavior;
    delete light_behavior_ptr_;
    light_behavior_ptr_ = new Coward();
  }
  void set_food_behavior(Behavior behavior) {
    food_behavior_ = behavior;
    delete bv_behavior_ptr_;
    bv_behavior_ptr_ = new None();
  }
  void set_bv_behavior(Behavior behavior) {
    bv_behavior_ = behavior;
    delete bv_behavior_ptr_;
    bv_behavior_ptr_ = new Aggressive();
  }
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
  const ArenaEntity* closest_light_entity_;
  const ArenaEntity* closest_food_entity_;
  const ArenaEntity* closest_bv_entity_;
  double defaultSpeed_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_PREDATOR_H_
