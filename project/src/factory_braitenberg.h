/**
 * @file factory_braitenberg.h
 *
 * @copyright 2017 Angela Almquist
 */

#ifndef SRC_FACTORY_BRAITENBERG_H_
#define SRC_FACTORY_BRAITENBERG_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/arena_entity.h"
#include "src/factory_entity.h"
#include "src/braitenberg_vehicle.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/* @brief Factory that produces Braiteberg Vehicle entities
 *
 * A braitenberg vehicle is a simple machine that is used to show how simple
 * concepts (in this case wiring) can give way to complex looking behavior. In
 * this simulation, Braitenberg vehicles contain sensors, which can be hooked
 * up in four different ways, and thus they can exhibit four different behaviors
 */
class FactoryBraitenberg: public FactoryEntity {
 public:
  FactoryBraitenberg() {}
  virtual ~FactoryBraitenberg() {}
  BraitenbergVehicle * Create(json_object* config) override;
	  /**
   * @brief Under certain circumstance, the compiler requires that the
   * assignment operator is not defined. This `deletes` the default
   * assignment operator.
   */
  FactoryBraitenberg &operator=(const FactoryBraitenberg &other) = delete;

  /**
   * @brief Under certain circumstance, the compiler requires that the copy
   * constructor is not defined. This `deletes` the default copy constructor.
   */
  FactoryBraitenberg(const FactoryBraitenberg &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_BRAITENBERG_H_

