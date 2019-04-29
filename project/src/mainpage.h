/**
 * @file mainpage.h
 *
 * @copyright 2017 Angela Almquist
 */
#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*! \mainpage CSCI3081 Project Documentation
 \tableofcontents
  \section title Braitenberg Vehicle Simulation
  \subsection intro Background
  
  There are many parts to this program. Within the arena there are arena 
  entities. These entities are comprised of braitenberg vehicles, lights,
  food, predators and braitenberg vehicle ghosts. A factory pattern is 
  used to develop arena entities and braitenberg vehicle behaviors. The 
  graphical interface searches through the arena entities and updates 
  their position in the arena. An observer pattern is used to keep the 
  graphical interface informed of a selected vehicle's current wheel velocity.
  
  https://en.wikipedia.org/wiki/Braitenberg_vehicle
 
 * 
 * 
 * \subsubsection executing Compiling and Executing
 * In order to start the Braitenberg Vehicle simulation, one must enter 
 * into the project directory, compile the code with make, and execute
 * by calling the arenaviewer object file and providing an .json or .txt 
 * input file. The .json and .txt files will specify the initial parameters
 * of the simulation, i.e. how many robots, predators, food and/or lights
 * should be present in the simulation as well as their behaviors. If an 
 * input file is not provided or if there is an error configuring the
 * input file, the simulation will start the simulation with default
 * parameters given in arena.cc.
 * \code{.sh}
 * cd <path>/project/
 * make
 * ./../build/bin/arenaviewer scenes/food_2lights_4bots_predator.json
 * \endcode
 * <table border="0">
 * <tr><td>\image html Simulation.png "Simulation" width=500 
 * </table>
 * A screenshot of the simulation in play. The colors of Braitenberg Vehicles
 * reflect what their wheel velocities are driven by.
 * <hr>
 * \subsection framework Code Framework
 * 
 * The code is loosely framed as Model-View-Controller.
 * UML diagrams of the class structure can be viewed by the following links.
 * <ul>
 * <li> GraphicsArenaViewer
 * <li> Arena
 * <li> Controller
 * <li> ArenaEntity
 * </ul>
 * \subsubsection classes Primary Classes
 * The primary classes used to develop the simulation are GraphicsArenaViewer,
 * Arena, Controller and ArenaEntity. The GraphicsArenaViewer is used to set 
 * up the graphics of the simulation, i.e the dimensions, text displayed and 
 * arena entities. The Controller class is used to parse .json or .txt file 
 * input of initial parameters to set up the arena. The Arena instantiates 
 * the entities and routinely calls the update functions of all entities in the 
 * arena. The ArenaEntity class is the base class for which all entities
 * derive.
 * 
 * 
 * \subsubsection structs Primary Data Structures in Arena
 * Of the ArenaEntities class, there are four primary entities that may exist 
 * within the arena. The following entities can be examined in further detail 
 * by the following links.
 * <ul>
 * <li> BraitenbergVehicle
 * <li> Food
 * <li> Light
 * <li> Predator
 * </ul>
 * 
 * \subsubsection instantiate Instantiating Arena Entities
 * To set up the simulation without a .json or .txt file input, one can
 * instantiate new arena entities in the Arena class. New entities can be created 
 * by the following C++ code.
 * \code{.cpp}
 * Arena::Arena(): x_dim_(X_DIM), y_dim_(Y_DIM),
 *  entities_(), mobile_entities_() {
 *   AddEntity(new Light());
 *   AddEntity(new Food());
 *   AddEntity(new BraitenbergVehicle());
 *   AddEntity(new Predator());
 * }
 * 
 * \endcode
 * <hr>
 * However with the input of a .json or .txt the entities are created by
 * the factory pattern as explained in the next section. Each arena entity
 * is instantiated by their Create() function which is inherited by the
 * FactoryEntity interface. Code for factory pattern instantiation looks 
 * like the following C++ code.
 * 
 * \code{.cpp}
     switch (etype) {
      case (kLight):
        entity = fl.Create(entity_config_ptr);
        break;
      case (kFood):
        entity = ff.Create(entity_config_ptr);
        break;
      case (kBraitenberg):
        entity = fb.Create(entity_config_ptr);
        break;
      case (kPredator):
        entity = fp.Create(entity_config_ptr);
        break;
      default:
        std::cout << "FATAL: Bad entity type on creation" << std::endl;
        assert(false);
    }

    if (entity) {
      AddEntity(entity);
    }
 * 
 * \endcode
 * \subsection factory Factory Pattern
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
 * <table border="0">
 * <tr><td>\image html FactoryEntity.png "ArenaEntities" width=600
 * </table>
 * The UML diagram of arena entities' inheritance.
 * <hr>
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
 * <table border="0">
 * <tr><td>\image html Behaviors.png "Behaviors" width=650
 * </table>
 * The UML diagram of behaviors' inheritance.
 * <hr>
 * \subsection observer Observer Pattern
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
 * <table border="0">
 * <tr><td>\image html Subject.png "ObserverPattern" width=250
 *
 * </table>
 * The UML diagram of Braitenberg vehicle as a Subject.
 *  <hr>
 * \subsection decorator Decorator Pattern
 * The decorator pattern allows for Predators to disguise themselves as
 * other arena entities. To be continued...
 * \subsection refs References
 * <ul>
 * <li> https://ivlab.github.io/MinGfx/api.html
 * <li> https://nanogui.readthedocs.io/en/latest/
 * <li> https://github.umn.edu/umn-csci-3081-S19/repo-almqu071/tree/master/project
 * </ul>
 */
 
#endif /* SRC_MAINPAGE_H_ */
