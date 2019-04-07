/**
 * @file predator.h
 *
 * @copyright 2017 Angela Almquist
 */

#ifndef SRC_FACTORY_PREDATOR_H_
#define SRC_FACTORY_PREDATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/arena_entity.h"
#include "src/factory_entity.h"
#include "src/predator.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/* @brief Factory to create Predator entities
 *
 * A predator is a simple machine that is aggressive towards 
 * braitenberg vehicles, and turns them into ghosts upon collision.
 * Predators do not collide with light or food, but exhibit cowardice
 * behavior towards light.
 */
class FactoryPredator: public FactoryEntity {
 public:
  FactoryPredator() {}
  virtual ~FactoryPredator() {}
  Predator * Create(json_object* config) override;
	  /**
   * @brief Under certain circumstance, the compiler requires that the
   * assignment operator is not defined. This `deletes` the default
   * assignment operator.
   */
  FactoryPredator &operator=(const FactoryPredator &other) = delete;

  /**
   * @brief Under certain circumstance, the compiler requires that the copy
   * constructor is not defined. This `deletes` the default copy constructor.
   */
  FactoryPredator(const FactoryPredator &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_PREDATOR_H_

