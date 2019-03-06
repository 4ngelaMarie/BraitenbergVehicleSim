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

//class BraitenbergVehicle;

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
BraitenbergVehicle * FactoryBraitenberg::Create() {
	return new BraitenbergVehicle(); 
}

NAMESPACE_END(csci3081);

