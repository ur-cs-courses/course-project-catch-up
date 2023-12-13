# Libraries - Source

## building.cpp
This class contains members and functions to support rooms in a group.

Building(const std::string& filename) : This is the constructor for a building. It assigns the filename to the one specified.

addRoom(Room* room) : 

## fleet.cpp
This class contains members and functions to support robots in a group.

## manager.cpp
This class contains methods that support the user interface, i.e., the command line. 

assignRobot(Robot* robot, Room* room) : This function assigns a robot to clean a room and will move the robot to that location. If the robot cannot clean that type of room, the robot will not be moved and the command will be canceled with an output statement. If that robot can clean the room but does not have enough battery to clean the room on its own, it will prompt the user asking if they are sure they want this robot to clean the room on its own.

## robot.cpp
This class contains methods that support robots and their many different varieties. 

clean() : The robot has a chance of failing to clean. 

## room.cpp
This class contains methods that support rooms and their many different varieties.

## technician.cpp
This class contains methods that help handle robots when they fail.

## timer.cpp
This class contains methods that manage the time of the simulation.