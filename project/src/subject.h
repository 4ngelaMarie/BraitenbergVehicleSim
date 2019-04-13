/**
 * @file subject.h
 *
 * @copyright 2017 Angela Almquist
 */

#ifndef SRC_SUBJECT_H_
#define SRC_SUBJECT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/observer.h"
#include "src/wheel_velocity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/* @brief Subject class to implement the observer pattern. Subjects are watched
 * by subscribed observers. The observer will be the graphics_arena_viewer,
 * and the subjects will be 1 braitenberg vehicle at a time. This is used for
 * the velocity update textbox.
 */
class Subject {
 public:
  Subject() {}
  virtual ~Subject() {}
  virtual void Subscribe(Observer *observer) = 0;
  virtual void Unsubscribe() = 0;
  virtual void Notify(WheelVelocity* light_wv_ptr,
    WheelVelocity* food_wv_ptr, WheelVelocity* bv_wv_ptr) = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_SUBJECT_H_


