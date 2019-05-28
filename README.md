# Braitenberg Vehicle Documentation
### @copyright 2017 Angela Almquist
## Background
The Braitenberg vehicle simulation is the product of a thought experiment
Valentino Braitenberg of how autonomous machines would respond to stimuli
if driven by four different behaviors. Within the program, the four behaviors
are Love, Aggressive, Explore and Coward. There is also the option to exhibit
no behavior at all. These behaviors are set for other entities within the 
arena. Once behaviors are set, if a robot senses a nearby entity to which is has a behavior
for, it's wheel velocities will be adjusted reflecting the specific behavior. Entities within the arena are comprised of braitenberg vehicles, lights, food, predators and braitenberg vehicle ghosts. For further information
about Braitenberg Vehicles, visit the link: <br />
 https://en.wikipedia.org/wiki/Braitenberg_vehicle <br />
 
 A factory pattern is used to create arena entities and braitenberg vehicle behaviors. 
 The graphical interface searches through the arena entities and updates their position in the arena. An observer pattern is used to keep the graphical interface informed of a selected vehicle's current wheel velocity. The
decorator pattern is used to disguise predators when they are starving.
Predators can look and act like other arena entities when starving, but if a 
Braitenberg vehicle collides with a disguise predator, the robot is consumed.

This program has many different classes. The primary classes used are 
Arena, Controller, GraphicsArenaViewer and ArenaEntity. The nanogui 
library is used generate the layout requested by GraphicsArenaViewer.
Further description of these program objects can be found under section, 
Primary Classes.
 
## Compiling and Executing
In order to start the Braitenberg Vehicle simulation, one must enter 
into the project directory, compile the code with make, and execute
by calling the arenaviewer object file and providing the x and
y dimensions of the arean and a .json 
input file. If arena dimensions are not specified, the arena will be 
initialized with default dimensions, and the json will still be used. 
The json file should specify the initial parameters
of the simulation, i.e. how many robots, predators, food and/or lights
should be present in the simulation as well as their behaviors. If an 
input file is not provided or if there is an error configuring the
input file, the simulation will start the simulation with default
parameters given in arena.cc.
 - cd <path>/project/
 - make
 - ./../build/bin/arenaviewer 600 600 scenes/food_2lights_4bots_predator.json

Where the x-dimension should be the first integer given and the y-dimension is
the second integer.
![alt text](https://github.com/4ngelaMarie/BraitenbergVehicleSim/blob/master/project/docs/images/Simulation.png)
 A screenshot of the simulation in play. The colors of Braitenberg Vehicles
 reflect what their wheel velocities are driven by.

## Primary Classes
The primary classes used to develop the simulation are GraphicsArenaViewer, Arena, Controller and ArenaEntity. The Controller instantiates the Arena and GraphicsArenaViewer. It does so by parsing through a given
.json for requested initial parameters. If no parameters are given,
the Arena is instantiated to a default value of one Braitenberg vehicle,
one food, one light and one predator. The Arena routinely calls the update functions of 
all entities in the arena. <br />

The GraphicsArenaViewer, or GAV, inherits 
from ArenaViewer. The GAV is used to set up the graphics of the simulation, 
i.e the dimensions, text displayed and arena entities. The MinGfx library
allows for 3D graphic displays. The built in nanogui interface allows for
on screen 2D graphics. <br />
The ArenaEntity class is the base class for which all entities derive. Entities can be classified as either mobile or immobile. This seperation allows for fewer function calls to update position of immobile arena entities.

## Primary Data Structures in Arena
There are four primary entities that may exist within the arena. The Braitenberg vehicle class is a mobile entity that can
exhibit behaviors towards other entities within the arena. When a Braitenberg
vehicle, or BV, collides with predator, another vehicle or a wall, a handle collision method is called
in arena to update the positions of colliding entities. Braitenberg vehicles die
and turn into an immobile ghost if they don't consume after 600 iterations. 
Upon reaching 450 iterations, they're behaviors are dynamically altered to 
drive their wheel velocities towards food. If a BV collides
with food, a consume_food method is called, the vehicle reverts back to its
user defined behaviors and the food is rellocated in a different section of the arena. <br />

The predator data structure is very similar to a Braitenberg vehicle. It however 
exhibits behaviors only towards lights and BVs, therefore a 
predator's motion is not affected by the position of food and other predators
in the arena. Similar to a BV, a predator starves after 600 iterations without 
consuming food, i.e. a robot. Starvation mode starts afer 150 iterations, where
the predator begins to disguise itself as other arena entities. After each
successive 150 iterations, the predator transforms at random into a different 
arena entity. This decoration of the predator into different entities is covered
more thoroughly in section, Decorator Pattern. <br />
Lights and food make up the last of the primary data structures found in 
the arena. Lights are mobile while food is immobile. Neither have set
behaviors towards other entities. The creation of primary data structures 
and behaviors are covered in section, Factory Pattern. These structures can be 
examined in further detail by the following links.

## Factory Pattern
New objects are made from a factory interface. This interface allows for
light, food, predators and braitenberg vehicle objects to be instantiated 
in the arena. Robot behaviors towards lights, food 
and other braitenberg vehicles are intialized to reflect the
json or csv input else the behaviors are prescribed a default value. 
Robots have no set behavior towards predators. Predators are aggressive towards Braitenberg
vehicles and cowardice towards lights. Lights and food exhibit no behaviors
towards other arena entities. 

![alt text](https://github.com/4ngelaMarie/BraitenbergVehicleSim/blob/master/project/docs/images/FactoryEntity.png)
 
Behaviors are also created with a behavior entity interface. When a behavior is selected for a braitenberg vehicle, a 
new instance of a behavior is created after deleted of the old one.
The Braitenberg vehicle class has member variable pointers that point
to behavior instances. These behaviors control how the robot moves,
more specifically: how the wheel velocities are updated. The five behaviors
a vehicle can exhibit towards lights, food and other braitenberg vehicles
are: Coward, Explore, Love, Aggressive or None. Similar behavior instances
are made for the predator class however predator behaviors cannot be adjusted by the user.

![alt text](https://github.com/4ngelaMarie/BraitenbergVehicleSim/blob/master/project/docs/images/Behaviors.png)

 ## Observer Pattern
The observer pattern allows for the wheel velocities of a selected
robot to be viewed in real time as the simulation is running. This is
possbile using the observer pattern where the graphics_arena_viewer,
the observer, is informed of the robot's wheel velocities, the subject.
When a Braitenberg vehicle is selected in the user control panel of the
simulation, the graphics_arena_viewer is "subscribed" to that robot. 
Once subscribed, when BraitenbergVehicle::Update() is called, the
graphics_arena_viewer is notified of the updated wheel velocities.
If a new robot is selected, the graphics_arena_viewer unsubscribes from the previously selected robot so only 
wheel velocities of one robot are shown at one time. 
![alt text](https://github.com/4ngelaMarie/BraitenbergVehicleSim/blob/master/project/docs/images/Subject.png)
The UML diagram of Braitenberg vehicle as a Subject.

## Decorator Pattern
The decorator pattern allows for predators to disguise themselves as
other arena entities. A predator will disguise itself into a different
arena entity at 150 iterations, 300 iterations and 450 iterations if it
hasn't consumed a Braitenberg vehicle by those timestamps. If the predator
does consume a BV, then its starvation counter is reset to zero. If the
predator has not eaten by 600 iterations, it turns into an immobile ghost.
While a predator is disguised, Braitenberg vehicles sense the entity type
the predator is disguised as rather than the predator itself. <br />

When a predator is disguised, its wheel velocities, color, radius and behaviors may
change depending what entity it is disguised as. If the predator is mimicking 
a light or food, it matches the default colors of light
and food respectively and exhibits no behaviors toward other entities. 
If the the predator is disguised as a Braitenberg vehicle, its 
behaviors are randomly selected towards lights and food, but the predator's
behavior remains Aggressive towards BVs. <br />

The decorator pattern allows for Braitenberg vehicles to be stimulated by the
disguise of the predator but maintain the predator's functionality. To accomplish
this, a new line of classes: BVDecorator, LightDecorator and FoodDecorator were 
introduced to program. An EntityDecorator interface was created by which all the 
decorators inherit from. The predator class was then modified so each predator
has an instance of an EntityDecorator. This instance is updated upon each
starvation level. When the EntityDecorator is set to a new BV, light or food
decorator, the Predator then updates its appearance and behaviors to mimic
that of its entity decorator pointer. In this simulation, BVs do not sense
predators, i.e. they do not have behaviors set towards predators. 
One last modification for the decorator pattern was made in the BraitenbergVehicle's 
sense_entity method. In the sense_entity method, a case for
sensing a predator was introduced. If the predator's entity decorator pointer, was
set to NULL, then no change occured however if the entity decorator pointer pointed to
for instance, a light decorator, the BV then sensed a light at the position of the
predator. The BV may or may not be stimulated by the decorator; the change in 
wheel velocities would depend on the BV's user defined behaviors or starvation counter.

## References
https://ivlab.github.io/MinGfx/api.html <br />
https://nanogui.readthedocs.io/en/latest/ <br />
https://github.umn.edu/umn-csci-3081-S19/repo-almqu071/tree/master/project
