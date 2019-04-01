/**
 * @file factory_food.h
 *
 * @copyright Angela Almquist
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <ctime>
#include "src/factory_food.h"
#include "src/food.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Food * FactoryFood::Create(json_object* config) {
  Food *bf = new Food();
  bf->LoadFromObject(config);  // no longer needed in arena.cc line 65
  return bf;
}

NAMESPACE_END(csci3081);

