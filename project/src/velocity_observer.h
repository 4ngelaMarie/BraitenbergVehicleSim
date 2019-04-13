/**
 * @file velocity_observer.h
 *
 * @copyright 2017 Angela Almquist
 */

#ifndef SRC_VELOCITY_OBSERVER_H_
#define SRC_VELOCITY_OBSERVER_H_

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
/* @brief Observer Interface to for graphics_arena_viewer to inherit from
 *
 * The update method will be overriden.
 */
class VelocityObserver : public Observer {
 public:
    nanogui::TextBox* textboxes[6];
    VelocityObserver() {}
    ~VelocityObserver() {}
    void OnUpdate(WheelVelocity* light_wv_ptr,
    WheelVelocity* food_wv_ptr, WheelVelocity* bv_wv_ptr) override;
     /**
     * @brief Under certain circumstance, the compiler requires that the
     * assignment operator is not defined. This `deletes` the default
     * assignment operator.
     */
    VelocityObserver &operator=(const VelocityObserver &other) = delete;

    /**
     * @brief Under certain circumstance, the compiler requires that the copy
     * constructor is not defined. This `deletes` the default copy constructor.
    */
    VelocityObserver(const VelocityObserver &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_VELOCITY_OBSERVER_H_
