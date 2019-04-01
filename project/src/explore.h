/**
 * @file explore.h
 *
 * @copyright Angela Almquist
 */

#ifndef SRC_EXPLORE_H_
#define SRC_EXPLORE_H_

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
/* @brief Explore class to represent an Explore behavior
 *
 * This behavior is an object a braitenberg vehicle may have. This behavior
 * affects the wheel velocity of a braitenberg vehicle that subscribes to it.
 */
class Explore: public BehaviorEntity {
 public:
  Explore() {}
  virtual ~Explore() {}
  void getWheelVelocity(double rsr, double lsr, double speed,
    WheelVelocity* wv_ptr) override{
      *wv_ptr = WheelVelocity(1.0/rsr, 1.0/lsr, speed);
  };
   /**
   * @brief Under certain circumstance, the compiler requires that the
   * assignment operator is not defined. This `deletes` the default
   * assignment operator.
   */
  Explore &operator=(const Explore &other) = delete;

  /**
   * @brief Under certain circumstance, the compiler requires that the copy
   * constructor is not defined. This `deletes` the default copy constructor.
   */
  Explore(const Explore &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_EXPLORE_H_


