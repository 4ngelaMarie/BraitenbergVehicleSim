/**
 * @file mainpage.h
 *
 * @copyright 2017 Angela Almquist
 */
#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*! \mainpage My Personal Index Page
 * \section Overview
 * 
 * There are many parts to this program. Within the arena there are arena 
 * entities. These entities are comprised of braitenberg vehicles, lights,
 * food, predators and braitenberg vehicle ghosts. A factory pattern is 
 * used to develop arena entities and braitenberg vehicle behaviors. The 
 * graphical interface searches through the arena entities and updates 
 * their position in the arena. An observer pattern is used to keep the 
 * graphical interface informed of a selected vehicle's current wheel velocity.
 * 
 * \section FactoryPattern
 *
 * New objects are made from a factory interface. This interface allows for
 * light, food, predators and braitenberg vehicle objects to be instantiated 
 * in the arena from a json file. The json file is submitted as the first 
 * paramater when exucuting arenaviewer. Robot behaviors towards lights, food 
 * and other braitenberg vehicles are initiated in the json value else the 
 * behaviors are prescribed a default value. Robots have no set behavior 
 * towards Predators however Predators are aggressive towards Braitenberg
 * vehicles and cowardice towards lights. The braitenberg vehicle class 
 * methods and variables can be viewed in the following link: 
 * file:///home/almqu071/CSCI3081/3081_S19/repo-almqu071/project/docs/html/classBraitenbergVehicle.html 
 * 
 * Braitenberg vehcile behaviors are also created with a behavior entity
 * interface. When a behavior is selected for a braitenberg vehicle, a 
 * new instance of a behavior is created after deleted of the old one.
 * The braitenberg vehicle class has member variable pointers that point
 * to behavior instances. These behaviors control how the robot moves,
 * more specifically: how the wheel velocities are updated. The five behaviors
 * a vehicle can exhibit towards lights, food and other braitenberg vehicles
 * are: Coward, Explore, Love, Aggressive or None.
 * 
 * \section ObserverPattern
 * 
 * The strategy pattern allows for the wheel velocities of a selected
 * robot to be viewed in real time as the simulation is running. This is
 * possbile using the observer pattern where the graphics_arena_viewer,
 * the observer, is informed of the robot's wheel velocities, the subject.
 * When a braitenberg vehicle is selected in the user control panel of the
 * simulation, the graphics_arena_viewer is "subscribed" to that robot. 
 * Once subscribed, when BraitenbergVehicle::Update() is called, the
 * graphics_arena_viewer is notified of the updated wheel velocities.
 * If a new robot is selected, the graphics_arena_viewer unsubscribes from
 * the previously selected robot so only wheel velocities of one robot are
 * shown at one time. 
 * 
 */
#endif /* SRC_MAINPAGE_H_ */
