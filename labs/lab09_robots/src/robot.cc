/**
 * @file robot_land.cc
 *
 * @copyright 201 3081 Staff & Angela Almquist, All rights reserved.
 */
 
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot.h"
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Robot::Robot(int id, double radius, Point origin, double speed){
	id_=id;
	radius_=radius;
	origin_ = origin;
	position_ = origin;
	speed_=speed;
}
void Update(double time){
// save the position
// calculate the new position
// calculate the velocity using those values
// calculate the direction
 double xnow, ynow, xprev, yprev;
  double delta = 0.1;
  if (id == 0) {
    xnow = circle_x(sim_time_);
    ynow = circle_y(sim_time_);
    xprev = circle_x(sim_time_ - delta);
    yprev = circle_y(sim_time_ - delta);

    *x_vel = xnow - xprev;
    *y_vel = ynow - yprev;
    position_.x_ = xnow;
    position_.y_ = ynow;
  } else if (id == 1) {
    // make this robot slower
    double t = 0.75 * sim_time_;
    xnow = circle_x(t);
    ynow = circle_y(t);
    xprev = circle_x(t - delta);
    yprev = circle_y(t - delta);

    *x_vel = xnow - xprev;
    *y_vel = ynow - yprev;
    position_.x_ = xnow;
    position_.y_ = ynow;
  } else {
    return;
  }
  return;
}
	 

  bool get_color(){
	  return false;
  }
  void set_color(bool color){
	  if (color == true){
			nvgFillColor(ctx, nvgRGBA(200, 200, 200, 255));
	  }
	  return;
  }
  int get_id(){
	  return id_;
  }
  double get_radius(){
	  return radius_;
  }
  Point get_position(){
	  return position_;
  }
  double get_direction(){
	  return direction_;
  }
  double get_sensor_angle(){
	  return sensor_angle_;
  }
  double get_sensor_range(){
	  return sensor_range_;
  }
  double get_speed(){
	  return speed_;
  }
