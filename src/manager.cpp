#include "libclean/manager.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include "libclean/timer.hpp"

int currentTimeManager = Timer::getTime();

Manager::Manager(const std::string& filename){
    currentTimeManager = Timer::getTime();
    this->filename = filename;
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager object created at time " << currentTimeManager << std::endl; 
    }

void Manager::viewRobotStatus(Robot* robot){
    currentTimeManager = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager viewRobotStatus() was called for robot: " << robot->getName() << " at time " << currentTimeManager << std::endl; 

    std::cout << "Name: " << robot->getName() << std::endl;
    std::cout << "ID: " << robot->getID() << std::endl;
    if (robot->getJob() == Job::SWEEPER) {
        std::cout << "Type: Sweeper" << std::endl;
    } else if (robot->getJob() == Job::MOPPER) {
        std::cout << "Type: Mopper" << std::endl;
    } else if (robot->getJob() == Job::VACUUMER) {
        std::cout << "Type: Vacuumer" << std::endl;
    } else {
        std::cout << "Type: Scrubber" << std::endl;
    }
    if (robot->getSize() == Size::SMALL) {
        std::cout << "Size: Small" << std::endl;
    } else if (robot->getSize() == Size::LARGE) {
        std::cout << "Size: Large" << std::endl;
    }
    std::cout << "Battery Level: " << robot->getBattery() << std::endl;
    std::cout << "Room: " << robot->getLocation()->getName() << std::endl;
    if(robot->hasFailed()){
        std::cout << "Status: Failed" << std::endl;
    }else if(robot->getBusy()){
        std::cout << "Status: Busy" << std::endl;
    }else {
        std::cout << "Status: Available" << std::endl;
    }
};

void Manager::viewLocation(Room* room) {
    currentTimeManager = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager viewLocation() was called for room: " << room->getName() << " at time " << currentTimeManager << std::endl; 

    std::cout << "Name: " << room->getName() << std::endl;
    std::string roomProperties = "This room is: ";
    if (room->getSweepable()) {
        roomProperties += "sweepable ";
    }
    if (room->getMoppable()) {
        roomProperties += "moppable ";
    }
    if(room->getScrubbable()){
        roomProperties += "scrubbable ";
    }
    if(room->getVacuumable()) {
        roomProperties += "vacuumable ";
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
    if(room->getVacuumable()){
        std::cout << "Percent Vacuumed: " << room->getPercentVacuumed() << std::endl;
    }
};

void Manager::assignRobot(Robot *robot, Room *room){
    currentTimeManager = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager assignRobot() was called to assign robot: " << robot->getName() << " to room: " << room->getName() <<  " at time " << currentTimeManager << std::endl; 

    if (robot->getJob() == Job::SWEEPER) {
        if (!room->getSweepable()) {
            std::cout << robot->getName() << " cannot clean " << room->getName() << " because it is not sweepable." << std::endl;
        } else {
            if (robot->getSize() == Size::SMALL) {
                if (robot->getBattery() < (((100 - room->getPercentSwept()) * room->getSize()) / 500) + 5) {
                    std::cout << "Are you sure? " << robot->getName() << " does not have enough battery to sweep this entire room. (yes / no)" << std::endl;
                    std::string answer = "";
                    std::cin >> answer;
                    while (answer != "yes" && answer != "no") {
                        std::string answer = "";
                        std::cout << "Command not recognized. Please try again." << std::endl;
                        std::cin >> answer;
                    }
                    if (answer == "yes") {
                        robot->move(room);
                        robot->setBusy(true);
                    } else {
                        std::cout << "Assign Robot command aborted." << std::endl;
                    }
                } else {
                    robot->move(room);
                    robot->setBusy(true);
                }
            } else {
                if (robot->getBattery() < (((100 - room->getPercentSwept()) * room->getSize()) / 1200) + 5) {
                    std::cout << "Are you sure? " << robot->getName() << " does not have enough battery to sweep this entire room. (yes / no)" << std::endl;
                    std::string answer = "";
                    std::cin >> answer;
                    while (answer != "yes" && answer != "no") {
                        std::string answer = "";
                        std::cout << "Command not recognized. Please try again." << std::endl;
                        std::cin >> answer;
                    }
                    if (answer == "yes") {
                        robot->move(room);
                        robot->setBusy(true);
                    } else {
                        std::cout << "Assign Robot command aborted." << std::endl;
                    }
                } else {
                    robot->move(room);
                    robot->setBusy(true);
                }
            }
        }
    } else if (robot->getJob() == Job::MOPPER) {
        if (!room->getMoppable()) {
            std::cout << robot->getName() << " cannot clean " << room->getName() << " because it is not moppable." << std::endl;
        } else {
            if (robot->getSize() == Size::SMALL) {
                if (robot->getBattery() < (((100 - room->getPercentMopped()) * room->getSize()) / 500) + 5) {
                    std::cout << "Are you sure? " << robot->getName() << " does not have enough battery to mop this entire room. (yes / no)" << std::endl;
                    std::string answer = "";
                    std::cin >> answer;
                    while (answer != "yes" && answer != "no") {
                        std::string answer = "";
                        std::cout << "Command not recognized. Please try again." << std::endl;
                        std::cin >> answer;
                    }
                    if (answer == "yes") {
                        robot->move(room);
                        robot->setBusy(true);
                    } else {
                        std::cout << "Assign Robot command aborted." << std::endl;
                    }
                } else {
                    robot->move(room);
                    robot->setBusy(true);
                }
            } else {
                if (robot->getBattery() < (((100 - room->getPercentMopped()) * room->getSize()) / 1200) + 5) {
                    std::cout << "Are you sure? " << robot->getName() << " does not have enough battery to mop this entire room. (yes / no)" << std::endl;
                    std::string answer = "";
                    std::cin >> answer;
                    while (answer != "yes" && answer != "no") {
                        std::string answer = "";
                        std::cout << "Command not recognized. Please try again." << std::endl;
                        std::cin >> answer;
                    }
                    if (answer == "yes") {
                        robot->move(room);
                        robot->setBusy(true);
                    } else {
                        std::cout << "Assign Robot command aborted." << std::endl;
                    }
                } else {
                    robot->move(room);
                    robot->setBusy(true);
                }
            }
        }
    } else if (robot->getJob() == Job::SCRUBBER) {
        if (!room->getScrubbable()) {
            std::cout << robot->getName() << " cannot clean " << room->getName() << " because it is not scrubbable." << std::endl;
        } else {
            if (robot->getSize() == Size::SMALL) {
                if (robot->getBattery() < (((100 - room->getPercentScrubbed()) * room->getSize()) / 500) + 5) {
                    std::cout << "Are you sure? " << robot->getName() << " does not have enough battery to scrub this entire room. (yes / no)" << std::endl;
                    std::string answer = "";
                    std::cin >> answer;
                    while (answer != "yes" && answer != "no") {
                        std::string answer = "";
                        std::cout << "Command not recognized. Please try again." << std::endl;
                        std::cin >> answer;
                    }
                    if (answer == "yes") {
                        robot->move(room);
                        robot->setBusy(true);
                    } else {
                        std::cout << "Assign Robot command aborted." << std::endl;
                    }
                } else {
                    robot->move(room);
                    robot->setBusy(true);
                }
            } else {
                if (robot->getBattery() < (((100 - room->getPercentScrubbed()) * room->getSize()) / 1200) + 5) {
                    std::cout << "Are you sure? " << robot->getName() << " does not have enough battery to scrub this entire room. (yes / no)" << std::endl;
                    std::string answer = "";
                    std::cin >> answer;
                    while (answer != "yes" && answer != "no") {
                        std::string answer = "";
                        std::cout << "Command not recognized. Please try again." << std::endl;
                        std::cin >> answer;
                    }
                    if (answer == "yes") {
                        robot->move(room);
                        robot->setBusy(true);
                    } else {
                        std::cout << "Assign Robot command aborted." << std::endl;
                    }
                } else {
                    robot->move(room);
                    robot->setBusy(true);
                }
            }
        }
    } else if (robot->getJob() == Job::VACUUMER) {
        if (!room->getVacuumable()) {
            std::cout << robot->getName() << " cannot clean " << room->getName() << " because it is not vacuumable." << std::endl;
        } else {
            if (robot->getSize() == Size::SMALL) {
                if (robot->getBattery() < (((100 - room->getPercentVacuumed()) * room->getSize()) / 500) + 5) {
                    std::cout << "Are you sure? " << robot->getName() << " does not have enough battery to scrub this entire room. (yes / no)" << std::endl;
                    std::string answer = "";
                    std::cin >> answer;
                    while (answer != "yes" && answer != "no") {
                        std::string answer = "";
                        std::cout << "Command not recognized. Please try again." << std::endl;
                        std::cin >> answer;
                    }
                    if (answer == "yes") {
                        robot->move(room);
                        robot->setBusy(true);
                    } else {
                        std::cout << "Assign Robot command aborted." << std::endl;
                    }
                } else {
                    robot->move(room);
                    robot->setBusy(true);
                }
            } else {
                if (robot->getBattery() < (((100 - room->getPercentVacuumed()) * room->getSize()) / 1200) + 5) {
                    std::cout << "Are you sure? " << robot->getName() << " does not have enough battery to scrub this entire room. (yes / no)" << std::endl;
                    std::string answer = "";
                    std::cin >> answer;
                    while (answer != "yes" && answer != "no") {
                        std::string answer = "";
                        std::cout << "Command not recognized. Please try again." << std::endl;
                        std::cin >> answer;
                    }
                    if (answer == "yes") {
                        robot->move(room);
                        robot->setBusy(true);
                    } else {
                        std::cout << "Assign Robot command aborted." << std::endl;
                    }
                } else {
                    robot->move(room);
                    robot->setBusy(true);
                }
            }
        }
    }
};

bool Manager::callTech(Robot* robot, Technician& tech){
    currentTimeManager = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager callTech() was called for robot: " << robot->getName() <<  " at time " << currentTimeManager  << std::endl; 
    return (tech.addRobotToQueue(robot));
};


void Manager::displayDirtyRooms(Building building){
    currentTimeManager = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayDirtyRooms() was called at time " << currentTimeManager << std::endl; 
    if (building.getDirtyRooms().empty()) {
        std::cout << "There are no dirty rooms." << std::endl;
    } else {
        std::cout << "The dirty rooms in the building are: " << std::endl;
        for (Room* r : building.getDirtyRooms()){
            std::cout << r->getName() << std::endl;
        }
    }
};


void Manager::displayCleanRooms(Building building){
    currentTimeManager = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayCleanRooms() was called at time " << currentTimeManager << std::endl; 
    if (building.getCleanRooms().empty()) {
        std::cout << "There are no clean rooms." << std::endl;
    } else {
        std::cout << "The clean rooms in the building are: " << std::endl;
        for (Room* r : building.getCleanRooms()){
            std::cout << r->getName() << std::endl;
        }
    }
};


void Manager::displayAllRooms(Building building){
    currentTimeManager = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayAllRooms() was called at time " << currentTimeManager << std::endl; 

    std::cout << "The rooms in the building are: " << std::endl;
    for (Room* r : building.getBuilding()){
        std::cout << r->getName() << std::endl;
    }
};

void Manager::displayBusyRobots(Fleet fleet){
    currentTimeManager = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayBusyRobots() was called at time " << currentTimeManager << std::endl; 
    if (fleet.getBusyRobots().empty()) {
        std::cout << "There are no busy robots." << std::endl;
    } else {
        std::cout << "The robots that are currently busy are: " << std::endl;
        for (Robot* r : fleet.getBusyRobots()){
            std::cout << r->getName() << std::endl;
        }
    }
};

void Manager::displayAvailableRobots(Fleet fleet){
    currentTimeManager = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayAvailableRobots() was called at time " << currentTimeManager << std::endl; 
    if (fleet.getAvailableRobots().empty()) {
        std::cout << "There are no available robots." << std::endl;
    } else {
        std::cout << "The robots that are currently available are: " << std::endl;
        for (Robot* r : fleet.getAvailableRobots()){
            std::cout << r->getName() << std::endl;
        }
    }
};

void Manager::displayFleet(Fleet fleet){
    currentTimeManager = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Manager displayFleet() was called at time " << currentTimeManager << std::endl; 

    std::cout << "The robots in the fleet are: " << std::endl;
    for (Robot* r : fleet.getFleet()){
        std::cout << r->getName() << std::endl;
    }
};
    