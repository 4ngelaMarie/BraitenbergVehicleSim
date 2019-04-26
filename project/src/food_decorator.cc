/**
 * @file food_decorator.cc
 *
 * @copyright 2017 Angela Almquist.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/food_decorator.h"
#include "src/params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

int FoodDecorator::count = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
FoodDecorator::FoodDecorator() : Food(), rradius_(20), colour_(FOOD_COLOR),
  light_behavior_(kNone), food_behavior_(kNone), bv_behavior_(kNone) {
  Food::set_type(kFood);

  // Set ID
  count++;
  Food::set_id(count);
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

NAMESPACE_END(csci3081);
