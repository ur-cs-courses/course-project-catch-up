#include "libclean/manager.hpp"
#include <string>
#include <iostream>
#include <fstream>

Manager::Manager(const std::string& filename){
    this->filename = filename;
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager object created" << std::endl; 
};

void Manager::viewRobotStatus(Robot robot){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager viewRobotStatus() was called" << std::endl; 

    std::cout << "Name: " << robot.getName() << std::endl;
    std::cout << "ID: " << robot.getID() << std::endl;
    if (robot.getSize() == Size::SMALL) {
        std::cout << "Size: Small" << std::endl;
    } else if (robot.getSize() == Size::LARGE) {
        std::cout << "Size: Large" << std::endl;
    }
    std::cout << "Battery Level: " << robot.getBattery() << std::endl;
    std::cout << "Room: " << robot.getLocation()->getName() << std::endl;
    if(robot.hasFailed()){
        std::cout << "Status: Failed" << std::endl;
    }else if(robot.getBusy()){
        std::cout << "Status: Busy" << std::endl;
    }else {
        std::cout << "Status: Available" << std::endl;
    }
};

void Manager::viewLocation(Room* room) {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager viewLocation() was called" << std::endl; 

    std::cout << "Name: " << room->getName() << std::endl;
    std::string roomProperties = "This room is ";
    if (room->getSweepable()) {
        roomProperties += "sweepable ";
    }
    if (room->getMoppable()) {
        if(room->getSweepable() && room->getScrubbable()){
            roomProperties += ", moppable, and ";
        }else if(room->getSweepable() && !room->getScrubbable()){
            roomProperties += "and moppable";
        }else if(!room->getSweepable() && room->getScrubbable()){
            roomProperties += "moppable and ";
        }
    }
    if(room->getScrubbable()){
        if (room->getSweepable() && !room->getMoppable()){
            roomProperties += "and scrubbable";
        }else{
            roomProperties += "scrubbable";
        }
    }
    std::cout << roomProperties << std::endl;
    std::cout << "Room Status: " << std::endl;
    if(room->getSweepable()){
        std::cout << "Percent Swept: " << room->getPercentSwept() << std::endl;
    }
    if(room->getMoppable()){
        std::cout << "Percent Mopped: " << room->getPercentMopped() << std::endl;
    }
    if(room->getScrubbable()){
        std::cout << "Percent Scrubbed: " << room->getPercentScrubbed() << std::endl;
    }
};

void Manager::assignRobot(Robot &robot, Room *room){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager assignRobot() was called" << std::endl; 
    //if (robot can clean room without running out of battery...){
    //
    //}
    robot.move(room);
};

void Manager::callTech(Robot* robot, Technician& tech){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager callTech() was called" << std::endl; 
    tech.addRobotToQueue(robot);
};


void Manager::displayDirtyRooms(Building building){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayDirtyRooms() was called" << std::endl; 
    std::cout << "The dirty rooms in the building are: " << std::endl;
    for (Room* r : building.getDirtyRooms()){
        std::cout << r->getName() << std::endl;
    }
};


void Manager::displayCleanRooms(Building building){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayCleanRooms() was called" << std::endl; 
    std::cout << "The clean rooms in the building are: " << std::endl;
    for (Room* r : building.getCleanRooms()){
        std::cout << r->getName() << std::endl;
    }
};


void Manager::displayAllRooms(Building building){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayAllRooms() was called" << std::endl; 

    std::cout << "The rooms in the building are: " << std::endl;
    for (Room* r : building.getBuilding()){
        std::cout << r->getName() << std::endl;
    }
};

void Manager::displayBusyRobots(Fleet fleet){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayBusyRobots() was called" << std::endl; 
    
    std::cout << "The robots that are currently busy are: " << std::endl;
    for (Robot* r : fleet.getBusyRobots()){
        std::cout << r->getName() << std::endl;
    }
};

void Manager::displayAvailableRobots(Fleet fleet){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayAvailableRobots() was called" << std::endl; 

    std::cout << "The robots that are currently available are: " << std::endl;
    for (Robot* r : fleet.getAvailableRobots()){
        std::cout << r->getName() << std::endl;
    }
};

void Manager::displayFleet(Fleet fleet){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayFleet() was called" << std::endl; 

    std::cout << "The robots in the fleet are: " << std::endl;
    for (Robot* r : fleet.getFleet()){
        std::cout << r->getName() << std::endl;
    }
};
    