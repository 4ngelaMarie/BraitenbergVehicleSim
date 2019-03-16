/**
 * @file braitenberg_vehicle.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <ctime>
#include "src/factory_light.h"
#include "src/light.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Light * FactoryLight::Create(json_object& config) {
  Light *bl = new Light();
  bl->LoadFromObject(config);  // no longer needed in arena.cc line 65
  return bl;
}

NAMESPACE_END(csci3081);
