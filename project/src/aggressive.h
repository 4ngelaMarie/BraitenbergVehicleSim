/**
 * @file aggressive.h
 *
 * @copyright Angela Almquist
 */

#ifndef SRC_AGGRESSIVE_H_
#define SRC_AGGRESSIVE_H_

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
/* @brief Aggressive class to represent an Aggressive behavior towards an
 * arena entity object
 *
 * This behavior is an object a braitenberg vehicle may have. This behavior
 * affects the wheel velocity of a braitenberg vehicle that subscribes to it.
 */
class Aggressive: public BehaviorEntity {
 public:
  Aggressive() {}
  virtual ~Aggressive() {}
  void getWheelVelocity(double rsr, double lsr, double speed,
   WheelVelocity* wv_ptr)override{
      *wv_ptr = WheelVelocity(1.0*rsr, 1.0*lsr, speed);
  };
   /**
   * @brief Under certain circumstance, the compiler requires that the
   * assignment operator is not defined. This `deletes` the default
   * assignment operator.
   */
  Aggressive &operator=(const Aggressive &other) = delete;

  /**
   * @brief Under certain circumstance, the compiler requires that the copy
   * constructor is not defined. This `deletes` the default copy constructor.
   */
  Aggressive(const Aggressive &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_AGGRESSIVE_H_


