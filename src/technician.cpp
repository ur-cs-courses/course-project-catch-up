#include <list>
#include <string> 
#include <iostream>
#include <chrono>
#include <thread>
#include "libclean/robot.hpp" 
#include "libclean/technician.hpp"

Technician::Technician() 
    : brokenRobotQueue({})
    {};

// Adds a robot to the busy queue if it's not already in the queue and if the robot has failed
void Technician::addRobotToQueue(Robot* robot) {
    if (robot->hasFailed()) {
        for (Robot* r : brokenRobotQueue) {
            if (&r == &robot) {
                std::cout << "Robot already in Technicians queue." << std::endl;
                break;
            }
        }
        brokenRobotQueue.push_back(robot);
        robot->setBusy(true);
    //if robot in quueu no need to add it. this actually should not happen - but just in case 
    } else {
        std::cout << "Robot already fixed." << std::endl;
    }
};

// Fixes the robot and removes it from the busy queue
void Technician::technicianFixesRobot(){
    Robot* robot = brokenRobotQueue.front();
    robot->setBattery(100.0); // Set the battery to 100%
    brokenRobotQueue.pop_front();
};

// Checks if the technician is busy
bool Technician::isTechBusy() const {
    return !brokenRobotQueue.empty();
};