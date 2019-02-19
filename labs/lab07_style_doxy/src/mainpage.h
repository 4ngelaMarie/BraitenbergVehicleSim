/**
 * @file mainpage.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
#ifndef LABS_LAB07_STYLE_DOXY_SRC_MAINPAGE_H_
#define LABS_LAB07_STYLE_DOXY_SRC_MAINPAGE_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
/*! \mainpage My Personal Index Page
 * @brief Use this this class to set up an obstacle
 * @brief Obstacle class includes a function that returns the position of obstacle
 *
 * @param Has parameters radius and position
 */
class Obstacle {
 public:
  Obstacle() : radius_(10), pos_(20.0, 20.0) {}
  int get_radius() {return radius_;}
  std::pair<double, double> get_pos() {return pos_;}
 private:
  int radius_;
  std::pair<double, double> pos_;
};
#endif /* LABS_LAB07_STYLE_DOXY_SRC_MAINPAGE_H_ */
