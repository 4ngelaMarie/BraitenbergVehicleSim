/**
 * @file observer.h
 *
 * @copyright 2017 Angela Almquist
 */

#ifndef SRC_OBSERVER_H_
#define SRC_OBSERVER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/wheel_velocity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/* @brief Observer Interface to for graphics_arena_viewer to inherit from
 *
 * The update method will be overriden.
 */
class Observer {
 public:
  Observer() {}
  virtual ~Observer() {}
  virtual void OnUpdate(WheelVelocity* light_wv_ptr,
    WheelVelocity* food_wv_ptr, WheelVelocity* bv_wv_ptr) = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_OBSERVER_H_


