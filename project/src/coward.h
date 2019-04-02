/**
 * @file coward.h
 *
 * @copyright Angela Almquist
 */

#ifndef SRC_COWARD_H_
#define SRC_COWARD_H_

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
/* @brief Coward class to represent an Coward behavior
 *
 * This behavior is an object a braitenberg vehicle may have. This behavior
 * affects the wheel velocity of a braitenberg vehicle that subscribes to it.
 */
class Coward: public BehaviorEntity {
 public:
  Coward() {}
  ~Coward() {}
  void getWheelVelocity(double lsr, double rsr, double speed,
    WheelVelocity* wv_ptr) override{
      *wv_ptr = WheelVelocity(1.0*lsr, 1.0*rsr, speed);
  };
   /**
   * @brief Under certain circumstance, the compiler requires that the
   * assignment operator is not defined. This `deletes` the default
   * assignment operator.
   */
  Coward &operator=(const Coward &other) = delete;

  /**
   * @brief Under certain circumstance, the compiler requires that the copy
   * constructor is not defined. This `deletes` the default copy constructor.
   */
  Coward(const Coward &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_COWARD_H_


