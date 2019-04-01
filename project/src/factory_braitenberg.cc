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
#include "src/factory_braitenberg.h"
#include "src/braitenberg_vehicle.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
BraitenbergVehicle * FactoryBraitenberg::Create(json_object* config) {
  BraitenbergVehicle *bv = new BraitenbergVehicle();
  bv->LoadFromObject(config);  // no longer needed in arena.cc line 65
  return bv;
}

NAMESPACE_END(csci3081);

