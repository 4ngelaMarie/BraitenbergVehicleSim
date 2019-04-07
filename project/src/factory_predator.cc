/**
 * @file factory_predator.cc
 *
 * @copyright 2017 Angela Almquist
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <ctime>
#include "src/factory_predator.h"
#include "src/predator.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Predator * FactoryPredator::Create(json_object* config) {
  Predator *p = new Predator();
  p->LoadFromObject(config);  // no longer needed in arena.cc line 65
  return p;
}

NAMESPACE_END(csci3081);

