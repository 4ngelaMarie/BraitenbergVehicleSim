/**
 * @file food.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_FOOD_DECORATOR_H_
#define SRC_FOOD_DECORATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/entity_decorator.h"
#include "src/food.h"
#include "src/common.h"
#include "src/entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a immobile food within the Arena.
 *
 * Food can enhance a Robot. If a Robot touches the Food, it becomes
 * a super robot.
 *
 * Food have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events.
 *
 */
class FoodDecorator :  public EntityDecorator, public Food  {
 public:
  /**
   * @brief Constructor.
   *
   * @param params A food_params passed down from main.cc for the
   * initialization of the Food.
   */
  FoodDecorator();
  /**
   * Deleting the copy assignment and copy constructor. required now with
   *  inclusion of references to sensors and motion_handler/behavior
   */
  FoodDecorator(const FoodDecorator & rhs) = delete;

  FoodDecorator operator=(const FoodDecorator & rhs) = delete;

  /**
   * @brief Get the name of the Food for visualization purposes, and to
   * aid in debugging.
   *
   * @return Name of the Food.
   */
  std::string get_name() const override { return "FoodDecorator"; }
  /**
   * @brief Returns Food's current light behavior.
   */
  Behavior get_light_behavior() override { return light_behavior_; }

  /**
   * @brief Returns Food's current food behavior.
   */
  Behavior get_food_behavior() override { return food_behavior_; }

  /**
   * @brief Returns Food's current robot behavior.
   */
  Behavior get_bv_behavior() override { return bv_behavior_; }
  /**
   * @brief The Food's ID.
   */
  static int count;

  const RgbColor &get_colour() const override { return colour_; }

  double get_rradius() const override { return rradius_; }

 private:
  double rradius_;
  RgbColor colour_;
  Behavior light_behavior_;
  Behavior food_behavior_;
  Behavior bv_behavior_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FOOD_DECORATOR_H_
