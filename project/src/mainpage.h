/**
 * @file mainpage.h
 *
 * @copyright 2017 Angela Almquist
 */
#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*! \mainpage My Personal Index Page
 *
 * \section Interface
 *
 * I have updated the code to include a factory interface. This interface allows for
 * light, food and braitenberg vehicle objects to be instantiated in the arena from 
 * a json file. The json file is submitted as the first paramater when exucuting
 * arenaviewer. 
 * 
 * I have also made changes to arena.cc to accomidate the factory interface. 
 * This was working and executing for awhile, but after making changes to meet google style compliance 
 * (sending json pointers instead of refs.,) I received the following error upon execution:
 * "Parse error: syntax error at line 1 near: 
 * libEGL warning: DRI2: failed to authenticate
 * Robot Simulation"
 * Otherwise it compiles with no errors or warnings. Maybe it's just my machine; 
 * hopefully it executes during TA testing. The unittests run fine.
 */
#endif /* SRC_MAINPAGE_H_ */
