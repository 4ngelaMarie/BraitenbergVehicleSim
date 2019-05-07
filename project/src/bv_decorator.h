/**
 * @file bv_decorator.h
 *
 * @copyright 2017 Angela Almquist.
 */

#ifndef SRC_BV_DECORATOR_H_
#define SRC_BV_DECORATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/common.h"
#include "src/entity_decorator.h"
#include "src/motion_behavior_differential.h"
#include "src/braitenberg_vehicle.h"

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
/* @brief Entity class to represent a Braitenberg Vehicle Decorator
 *
 * A braitenberg vehicle is a simple machine that is used to show how simple
 * concepts (in this case wiring) can give way to complex looking behavior. In
 * this simulation, Braitenberg vehicles contain sensors, which can be hooked
 * up in four different ways, and thus they can exhibit four different behaviors
 */

class BVDecorator : public BraitenbergVehicle, public EntityDecorator {
 public:
  /**
   * @brief Default constructor.
   */
  BVDecorator();

  /**
   * Deleting the copy assignment and copy constructor. required now with
   *  inclusion of references to sensors and motion_handler/behavior
   */
  BVDecorator(const BVDecorator & rhs) = delete;

  BVDecorator operator=(const BVDecorator & rhs) = delete;

  /**
   * @brief Returns the ID of the BraitenbergVehicle.
   */
  std::string get_name() const override;

  /**
   * @brief Returns BraitenbergVehicle's current light behavior.
   */
  Behavior get_light_behavior() override { return light_behavior_; }

  /** 
   *@brief For each behavior: Create new behavior instances 
   * These behaviors uniquely affect the BV wheel velocity 
   */
  void set_light_behavior(Behavior behavior) {
    light_behavior_ = behavior;
  }
  /**
   * @brief Returns BraitenbergVehicle's current food behavior.
   */
  Behavior get_food_behavior() override { return food_behavior_; }
  /** 
   *@brief For each behavior: Create new behavior instances 
   * These behaviors uniquely affect the BV wheel velocity 
   */
  void set_food_behavior(Behavior behavior) {
    food_behavior_ = behavior;
  }
  /**
   * @brief Returns BraitenbergVehicle's current robot behavior.
   */
  Behavior get_bv_behavior() override { return bv_behavior_; }
  /** 
   *@brief For each behavior: Create new behavior instances 
   * These behaviors uniquely affect the BV wheel velocity 
   */
  void set_bv_behavior(Behavior behavior) {
    bv_behavior_ = behavior;
  }
  const RgbColor &get_colour() const override { return colour_; }

  double get_rradius() const override { return rradius_; }
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
  double rradius_;
  RgbColor colour_;
  std::vector<Pose> light_sensors_;
  MotionBehaviorDifferential * motion_behavior_{nullptr};
  WheelVelocity wheel_velocity_;
  Behavior light_behavior_;
  Behavior food_behavior_;
  Behavior bv_behavior_;
  double defaultSpeed_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BV_DECORATOR_H_
