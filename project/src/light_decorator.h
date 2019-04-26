/**
 * @file light_decorator.h
 *
 * @copyright 2017 Angela Almquist.
 */

#ifndef SRC_LIGHT_DECORATOR_H_
#define SRC_LIGHT_DECORATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <ctime>

#include "src/entity_decorator.h"
#include "src/common.h"
#include "src/entity_type.h"
#include "src/pose.h"
#include "src/light.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a mobile light within the Arena.
 *
 */
class LightDecorator : public EntityDecorator, public Light {
 public:
  /**
   * @brief Constructor.
   */
  LightDecorator();

  /**
   * @brief Get the name of the Light for visualization purposes, and to
   * aid in debugging.
   */
  /**
   * Deleting the copy assignment and copy constructor. required now with
   *  inclusion of references to sensors and motion_handler/behavior
   */
  LightDecorator(const LightDecorator & rhs) = delete;

  LightDecorator operator=(const LightDecorator & rhs) = delete;

  std::string get_name() const override {
    return "LightDecorator " + std::to_string(Light::get_id());
  }
  /**
   * @brief Returns Light's current light behavior.
   */
  Behavior get_light_behavior() override { return light_behavior_; }

  /**
   * @brief Returns Light's current food behavior.
   */
  Behavior get_food_behavior() override { return food_behavior_; }

  /**
   * @brief Returns Light's current robot behavior.
   */
  Behavior get_bv_behavior() override { return bv_behavior_; }

  /**
   * @brief The Light's ID.
   */
  static int count;

  const RgbColor &get_colour() const override { return colour_; }

  double get_rradius() const override { return rradius_; }

 private:
  double rradius_;
  RgbColor colour_;
  Behavior food_behavior_;
  Behavior light_behavior_;
  Behavior bv_behavior_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_LIGHT_DECORATOR_H_
