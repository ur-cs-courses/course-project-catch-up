# Project tests

# Building Test : building_test.cpp
This tests all functions in the building class. Including: the constructor, addRoom(Room* room), getBuilding(), getDirtyRooms(), and getCleanRooms().

Section one makes sure a room is added to a building correctly. Section two tests all of the getter functions.

# Fleet Test : fleet_test.cpp
This tests all functions in the fleet class. Including: the constructor, updateVectors(Robot* robot), addToFleet(Robot* robot), getFleet(), getBusyRobots(), and getAvailableRobots().

Section one makes sure that updateVectors works and that things are put in the correct vectors. Section two tests all the getter functions.

# Manager Test : manager_test.cpp
This tests all functions in the manager class. Including: the constructor, viewRobotStatus(Robot* robot), viewLocation(Room* room), assignRobot(Robot* robot, Room* room), callTech(Robot* robot, Technician& tech), displayDirtyRooms(Building building), displayCleanRooms(Building building), displayAllRooms(Building building), displayBusyRobots(Fleet fleet), displayAvailableRobots(Fleet fleet), and displayFleet(Fleet fleet).

Section one makes sure that "view" functions work. Section two makes sure all the "display" functions work. Section three makes sure that calling the technician works. Section four makes sure assigning a robot works. Section five tests assigning a robot that will fail while cleaning.

# Robot Test : robot_test.cpp
This tests all functions in the robot class. Including: the constructor, operator==(const Robot& robot), getName(), getID(), getBattery(), getSize(), getLocation(), getBusy(), getFailed(), getJob(), move(Room* room), charge(), setLocation(Room* room), setName(std::string newname), setBattery(float percent), hasFailed(), setBusy(bool status), setFailed(bool status), isRoomClean(), and clean().

Section one makes sure that adding robots to the fleet works and tests all of the getters and setters. Section two tests moving a robot. Section three tests charging a robot. Section four makes sure that everything is completed correctly when a robot cleans a room. It also checks that if the room was initialized as false for any type of cleaning tasks, then those are all nan.

# Room Test : room_test.cpp
This tests all functions in the room class. Including: the constructor, getName(), getWidth(), getLength(), getSize(), getID(), operator==(const Room& room), getSweepable(), getMoppable(), getScrubbable(), getVacuumable(), getPercentSwept(), getPercentScrubbed(), getPercentMopped(), getPercentVacuumed(), setPercentSwept(), setPercentScrubbed(), setPercentMopped(), setPercentVacuumed(), and randomlyDirty().

Section one makes sure all the getters and setters work at intended. Section two checks that randomly dirty works as intended and that all of the attributes change as planned.

# Technician Test : technician_test.cpp
This tests all functions in the technician class. Including: the constructor, getRobotQueue(), addRobotToQueue(Robot* robot), technicianFixesRobot(), and isTechBusy().

Section one checks that all of these functions work as intended. 

# Timer Test : timer_test.cpp
This tests all functions in the timer class. Including: the constructor, addTime(), and getTime().

Section one checks that all of these functions work as intended. 