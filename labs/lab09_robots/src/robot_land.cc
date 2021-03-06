/**
 * @file robot_land.cc
 *
 * @copyright 201 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_land.h"
#include "robot.h"
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
RobotLand::RobotLand(void) {
	robot0 = new Robot(0, get_robot_radius(), Point origin, 0.0); //origin may be different than (0,0)
	robot1 = new Robot(1, get_robot_radius(), Point origin, 0.0);
}
// Hard coded for now...
bool RobotLand::get_robot_pos(int id, double *x_pos, double *y_pos) {
  if (id == 0) {
    *x_pos = circle_x(sim_time_);
    *y_pos = circle_y(sim_time_);
    return true;
  } else if (id == 1) {
    // make this robot slower
    double t = 0.75 * sim_time_;
    *x_pos = circle_x(t);
    *y_pos = circle_y(t);
    return true;
  } else {
    return false;
  }
}

// Hard coded for now...
bool RobotLand::get_robot_vel(int id, double *x_vel, double *y_vel) {
  double xnow, ynow, xprev, yprev;
  double delta = 0.1;
  if (id == 0) {
    xnow = circle_x(sim_time_);
    ynow = circle_y(sim_time_);
    xprev = circle_x(sim_time_ - delta);
    yprev = circle_y(sim_time_ - delta);

    *x_vel = xnow - xprev;
    *y_vel = ynow - yprev;
    return true;
  } else if (id == 1) {
    // make this robot slower
    double t = 0.75 * sim_time_;
    xnow = circle_x(t);
    ynow = circle_y(t);
    xprev = circle_x(t - delta);
    yprev = circle_y(t - delta);

    *x_vel = xnow - xprev;
    *y_vel = ynow - yprev;
    return true;
  } else {
    return false;
  }
}

// Hard coded for now...
void RobotLand::get_obstacle_pos(double *x_pos, double *y_pos) {
  *x_pos = 200;
  *y_pos = 300;
}
RobotLand::~RobotLand(){
	delete robot0;
	delete robot1;
}
