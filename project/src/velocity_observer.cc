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
  std::string out_string;
  std::ostringstream ss;

  double i = light_wv_ptr->left;
  ss << i;
  out_string = ss.str();
  out_string.resize(5);
  if (i < .001) { textboxes[0]->setValue("0.0");} else {
    textboxes[0]->setValue(out_string); }
  ss.str("");

  i = light_wv_ptr->right;
  ss << i;
  out_string = ss.str();
  out_string.resize(5);
  if (i < .001) { textboxes[1]->setValue("0.0");} else {
    textboxes[1]->setValue(out_string); }
  ss.str("");

  i = food_wv_ptr->left;
  ss << i;
  out_string = ss.str();
  out_string.resize(5);
  if (i < .001) { textboxes[2]->setValue("0.0");} else {
    textboxes[2]->setValue(out_string); }
  ss.str("");

  i = food_wv_ptr->right;
  ss << i;
  out_string = ss.str();
  out_string.resize(5);
  if (i < .001) { textboxes[3]->setValue("0.0");} else {
    textboxes[3]->setValue(out_string); }
  ss.str("");

  i = bv_wv_ptr->left;
  ss << i;
  out_string = ss.str();
  out_string.resize(5);
  if (i < .001) { textboxes[4]->setValue("0.0");} else {
    textboxes[4]->setValue(out_string); }
  ss.str("");

  i = bv_wv_ptr->right;
  ss << i;
  out_string = ss.str();
  out_string.resize(5);
  if (i < .001) { textboxes[5]->setValue("0.0");} else {
    textboxes[5]->setValue(out_string); }
  ss.str("");
}

NAMESPACE_END(csci3081);

