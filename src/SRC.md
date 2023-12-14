# Libraries - Source

To go back to the README click [here](../docs/README.md).

## building.cpp
This class contains members and functions to support rooms in a group.

Building(const std::string& filename) : This is the constructor for a building. It assigns the filename to the one specified.

addRoom(Room* room) : This function adds a room to the building vector within the building class.

getBuilding() : This function returns the building vector within the building class

getDirtyRooms() : This function creates and returns a vector of all of the "dirty" rooms (rooms that are not 100 percent clean) within the building class.

getCleanRooms(): This function creates and returns a vector of all of the "clean" rooms (rooms that are 100 percent clean) within the building class.

## fleet.cpp
This class contains members and functions to support robots in a group.

Fleet(const std::string& filename) : This is a constructor for a fleet.  It assigns the filename to the one specified.

updateVectors(Robot* robot) : This function updates the busyRobots and availableRobots vectors within fleet with whatever robot was passed to the function.

addToFleet(Robot* robot) : This function adds a robot to the fleet vector within the fleet class.

getFleet() : This function returns the fleet vector within the fleet class.

getAvailableRobots() : This function returns the availableRobots vector within the fleet class.

getBusyRobots(): This function returns the busyRobots vector within the fleet class.

## manager.cpp
This class contains methods that support the user interface, i.e., the command line. 

Manager(const std::string& filename) : This is a constructor for a manager.  It assigns the filename to the one specified.

viewRobotStatus(Robot* robot) : This function prints out information about a given Robot.

viewLocation(Room* room) : This function prints out information about a given room.

assignRobot(Robot* robot, Room* room) : This function assigns a robot to clean a room and will move the robot to that location. If the robot cannot clean that type of room, the robot will not be moved and the command will be canceled with an output statement. If that robot can clean the room but does not have enough battery to clean the room on its own, it will prompt the user asking if they are sure they want this robot to clean the room on its own.

callTech(Robot* robot, Technician& tech) : This function calls a technician to fix a robot, it will return true if the robot should be fixed and added to the technicians deque of robots it needs to fix.

displayDirtyRooms(Building building) : This function prints out the dirty rooms in a given building.

displayCleanRooms(Building building) : This function prints out the clean rooms in a given building.

displayAllRooms(Building building) : This function prints out all the rooms in a given building.

displayBusyRobots(Fleet fleet) : This function prints out all of the busy robots within a given fleet.

displayAvailableRobots(Fleet fleet) : This function prints out all of the available robots within a given fleet.

displayFleet(Fleet fleet) : This function prints out all of the robots within a given fleet.

## robot.cpp
This class contains methods that support robots and their many different varieties. 

Robot(std::string name, float battery_, Size size, Room *location, const std::string& filename, Job job) : This is a constructor for a robot, given a name, battery level, location, and job.  Robots start available and still working.  It assigns the filename to the one specified.

operator==(const Robot& robot) : This overloads the == operator for robots, it checks to make sure that the unique IDs of the robots match.

getName() : This function returns the name of the robot.

getID() : This function returns the ID of the robot.

getBattery() : This function returns the battery level of the robot.

getSize() : This function returns the size of the robot.

getLocation() : This function returns the location of the robot.

getBusy() : This function returns true if the robot is busy.

getFailed() : This function returns true if the robot has failed (not including battery level).

getJob() : This function returns the location of the robot.

move(Room *room) : This function moves a robot to a given room if it has enough battery. Requires 5 battery level to move.

charge() : This function charges the robot, increasing its battery level by 5.

setLocation(Room* room) : This function sets the location of the robot to the given room.

setName(std::string newname) : This function sets the name of the robot to the given name.

setBattery(float percent) : This function sets the battery level of the robot to the given percent, if it is a valid value.

hasFailed() : This function checks if the robot has failed (failed is true or battery level is 0)

setBusy(bool status) : This function sets the busy status of the robot to the given boolean.

setFailed(bool status) : This function sets the failed status of the robot to the given boolean.

isRoomClean() : This function checks if the robot's current location is clean based on what the robot's job is.

clean() : This function has the robot clean a percentage of the room proportional to the robot and room's size.  It cleans the room based on what job it has.  The robot has a chance of failing to clean everytime it cleans.

## room.cpp
This class contains methods that support rooms and their many different varieties.

Room(std::string name, float width_, float length_, bool sweepable, bool moppable, bool scrubbable, bool vacuumable, const std::string& filename) : A constructor for rooms, given a name, width, length, and booleans for sweepable, scrubbable, moppable, and vacuumable. PercentCleaned values are intialized based on the aforementioned booleans, but the room is always set to be completely clean from the start.  It assigns the filename to the one specified.  

getName() : This function returns the name of a room.

getWidth() : This function returns the width of a room.

getLength() : This function returns the length of a room.

getSize() : This function returns the size of a room.

getID() : This function returns the ID of a room.

operator==(const Room& room) : This function overloads the == operator, comparing the unique IDs of two rooms.

getSweepable() : This function returns the sweepable boolean of a room.

getMoppable() : This function returns the moppable boolean of a room.

getScrubbable() : This function returns the scrubbable boolean of a room.

getVacuumable() : This function returns the vacuumable boolean of a room.

getPercentSwept() : This function returns the percentSwept of a room.

getPercentMopped() : This function returns the percentMopped of a room.

getPercentScrubbed() : This function returns the percentScrubbed of a room.

getPercentVacuumed() : This function returns the percentVacuumed of a room.

setPercentSwept(float percent) : This function sets the percentSwept of a room to the given percent.

setPercentMopped(float percent) : This function sets the percentMopped of a room to the given percent.

setPercentScrubbed(float percent) : This function sets the percentScrubbed of a room to the given percent.

setPercentVacuumed(float percent) : This function sets the percentVacuumed of a room to the given percent.

randomlyDirty() : Sets the percentCleaned values of a room to random values.

## technician.cpp
This class contains methods that help handle robots when they fail.

Technician(const std::string& filename) : This is a constructor for a technician.  It assigns the filename to the one specified.

getRobotQueue() : This function returns the robots that are in the brokenRobotQueue of robots the technician needs to fix.

addRobotToQueue(Robot* robot) : This function adds a robot to the broken robot queue if it is not already in the queue, and if it actually needs to be fixed.

technicianFixesRobot() : This function has the technician fix the next robot in the broken robot queue.

isTechBusy() : This function returns true if there are robots in the brokenRobotQueue.

## timer.cpp
This class contains methods that manage the time of the simulation.

addTime() : This function adds 1 to the time member within the timer class.

getTime() : This functions returns the time of the timer class.