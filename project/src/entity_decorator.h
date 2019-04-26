/**
 * @file entity_decorator.h
 *
 * @copyright 2017 Angela Almquist.
 */

#ifndef SRC_ENTITY_DECORATOR_H_
#define SRC_ENTITY_DECORATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <iostream>

#include "src/arena_entity.h"
#include "src/behavior_enum.h"
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A mobile entity in the Arena, capable of updating its own position
 * and/or velocity when asked by the simulation.
 *
 * All mobile entities must have a heading angle so that their orientation can
 * be properly drawn by the GraphicsArenaViewer.
 *
 * Since this is also a food class, many of its methods are intuitively
 * `virtual`.
 */
class EntityDecorator : public ArenaEntity {
 public:
  /**
   * @brief ArenaMobileEntity's constructor.
   */

  EntityDecorator()
    : colour_(DEFAULT_COLOR), rradius_(15),
      entity_ptr_(NULL), bv_behavior_(kNone), light_behavior_(kNone),
      food_behavior_(kNone), speed_(0),
      is_moving_(true) {
        set_mobility(true);
  }
  EntityDecorator(const EntityDecorator& other) = delete;
  EntityDecorator& operator=(const EntityDecorator& other) = delete;

  virtual Behavior get_bv_behavior() { return bv_behavior_; }
  virtual Behavior get_light_behavior() { return light_behavior_; }
  virtual Behavior get_food_behavior() { return food_behavior_; }

  virtual const RgbColor &get_colour() const { return colour_; }

  virtual double get_rradius() const { return rradius_; }

 private:
  RgbColor colour_;
  double rradius_;
  ArenaEntity* entity_ptr_;
  Behavior bv_behavior_;
  Behavior light_behavior_;
  Behavior food_behavior_;
  double speed_;
  bool is_moving_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_ENTITY_DECORATOR_H_
