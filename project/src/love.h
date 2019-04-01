/**
 * @file love.h
 *
 * @copyright Angela Almquist
 */

#ifndef SRC_LOVE_H_
#define SRC_LOVE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/behavior.h"
#include "src/behavior_enum.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/* @brief Love class to represent an Love behavior towards an
 * arena entity object
 *
 * This behavior is an object a braitenberg vehicle may have. This behavior
 * affects the wheel velocity of a braitenberg vehicle that subscribes to it.
 */
class Love: public BehaviorEntity {
 public:
  Love() {}
  virtual ~Love() {}
  void getWheelVelocity(double rsr, double lsr, double speed,
    WheelVelocity* wv_ptr) override{
      *wv_ptr = WheelVelocity(1.0/lsr, 1.0/rsr, speed);
  };
   /**
   * @brief Under certain circumstance, the compiler requires that the
   * assignment operator is not defined. This `deletes` the default
   * assignment operator.
   */
  Love &operator=(const Love &other) = delete;

  /**
   * @brief Under certain circumstance, the compiler requires that the copy
   * constructor is not defined. This `deletes` the default copy constructor.
   */
  Love(const Love &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_LOVE_H_


