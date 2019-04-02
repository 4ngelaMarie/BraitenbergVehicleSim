/**
 * @file none.h
 *
 * @copyright Angela Almquist
 */

#ifndef SRC_NONE_H_
#define SRC_NONE_H_

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
/* @brief None class to represent the absence of robot behavior towards an arena
 * entity.
 *
 * This behavior is an object a braitenberg vehicle may have. This behavior
 * affects the wheel velocity of a braitenberg vehicle that subscribes to it.
 */
class None: public BehaviorEntity {
 public:
  None() {}
  ~None() {}
  void getWheelVelocity(double lsr, double rsr, double speed,
    WheelVelocity* wv_ptr) override{
        rsr = 0.0;
        lsr = 0.0;
        *wv_ptr = WheelVelocity(lsr, rsr, speed);
  };
   /**
   * @brief Under certain circumstance, the compiler requires that the
   * assignment operator is not defined. This `deletes` the default
   * assignment operator.
   */
  None operator=(const None &other) = delete;

  /**
   * @brief Under certain circumstance, the compiler requires that the copy
   * constructor is not defined. This `deletes` the default copy constructor.
   */
  None(const None &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_NONE_H_


