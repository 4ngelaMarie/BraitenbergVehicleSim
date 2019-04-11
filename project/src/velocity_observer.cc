/**
 * @file velocity_observer.cc
 *
 * @copyright 2017 Angela Almquist
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <MinGfx-1.0/mingfx.h>

#include <ctime>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "src/velocity_observer.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/* @brief Observer Interface to for graphics_arena_viewer to inherit from
 *
 * The update method will be overriden.
 */

void VelocityObserver::OnUpdate(WheelVelocity* light_wv_ptr,
  WheelVelocity* food_wv_ptr, WheelVelocity* bv_wv_ptr) {
  int i = light_wv_ptr->left;
  std::cout << std::fixed << std::showpoint;
  std::cout << std::setprecision(2);
  
  std::string out_string;
  std::stringstream ss;
  ss << i;
  out_string = ss.str();
  textboxes[0]->setValue(out_string);
  i = light_wv_ptr->right;
  ss <<i;
  out_string == ss.str();
  textboxes[1]->setValue(out_string);
  i = food_wv_ptr->left;
  ss << i;
  out_string = ss.str();
  textboxes[2]->setValue(out_string);
  i = food_wv_ptr->right;
  ss <<i;
  out_string == ss.str();
  textboxes[3]->setValue(out_string);
  i = bv_wv_ptr->left;
  ss << i;
  out_string = ss.str();
  textboxes[4]->setValue(out_string);
  i = bv_wv_ptr->right;
  ss <<i;
  out_string == ss.str();
  textboxes[5]->setValue(out_string);
  //    screen()->performLayout();
	   };

NAMESPACE_END(csci3081);

