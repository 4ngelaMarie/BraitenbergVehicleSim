/**
 * @file light_decorator.cc
 *
 * @copyright 2017 Angela Almquist.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include "src/light_decorator.h"
#include "src/params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

int LightDecorator::count = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
LightDecorator::LightDecorator() : Light(), rradius_(30), colour_(LIGHT_COLOR),
  food_behavior_(kNone), light_behavior_(kNone), bv_behavior_(kNone) {
  Light::set_radius(LIGHT_RADIUS);
  Light::set_type(kLight);

  // Set ID
  count++;
  Light::set_id(count);
}

NAMESPACE_END(csci3081);
