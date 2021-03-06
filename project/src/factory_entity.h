/**
 * @file factory_entity.h
 *
 * @copyright 2017 Angela Almquist
 */

#ifndef SRC_FACTORY_ENTITY_H_
#define SRC_FACTORY_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/arena_entity.h"
class ArenaEntity;

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/* @brief Entity class to represent a Braitenberg Vehicle
 *
 * A braitenberg vehicle is a simple machine that is used to show how simple
 * concepts (in this case wiring) can give way to complex looking behavior. In
 * this simulation, Braitenberg vehicles contain sensors, which can be hooked
 * up in four different ways, and thus they can exhibit four different behaviors
 */
class FactoryEntity {
 public :
    FactoryEntity() {}
    virtual ~FactoryEntity() {}
    virtual ArenaEntity * Create(json_object* config) = 0;
     /**
     * @brief Under certain circumstance, the compiler requires that the
     * assignment operator is not defined. This `deletes` the default
     * assignment operator.
     */
    FactoryEntity &operator=(const FactoryEntity &other) = delete;

    /**
     * @brief Under certain circumstance, the compiler requires that the copy
     * constructor is not defined. This `deletes` the default copy constructor.
    */
    FactoryEntity(const FactoryEntity &other) = delete;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_ENTITY_H_


