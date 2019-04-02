/**
 * @file behavior.h
 *
 * @copyright Angela Almquist
 */

#ifndef SRC_BEHAVIOR_H_
#define SRC_BEHAVIOR_H_

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
/* @brief BehaviorEntity class to represent a behaviors as objects 
 * a braitenberg vehcile can have.
 *
 *Five different behaviors can be implemented; each updates the wheel velocity of 
 * Braitenberg vehicle in different ways.
 */
class BehaviorEntity {
 public :
    BehaviorEntity() {}
    virtual ~BehaviorEntity() {}
    virtual void getWheelVelocity(double lsr, double rsr, double speed,
      WheelVelocity* wv_ptr) = 0;
     /**
     * @brief Under certain circumstance, the compiler requires that the
     * assignment operator is not defined. This `deletes` the default
     * assignment operator.
     */
    BehaviorEntity &operator=(const BehaviorEntity &other) = delete;

    /**
     * @brief Under certain circumstance, the compiler requires that the copy
     * constructor is not defined. This `deletes` the default copy constructor.
    */
    BehaviorEntity(const BehaviorEntity &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BEHAVIOR_H_



