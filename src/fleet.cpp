#include <string> 
#include <math.h> 
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "libclean/robot.hpp"
#include "libclean/fleet.hpp"

Fleet::Fleet()
   : fleet({}), availableRobots({}),  busyRobots({})
   {};

void Fleet::updateVectors(Robot* robot){
    if (robot->getBusy()) { // will run if robot is busy
      for (int i = 0; i < availableRobots.size(); i++) {
         if (availableRobots[i] == robot) {
            availableRobots.erase(availableRobots.begin() + i);
         }
      }
      busyRobots.push_back(robot);
    }
    else { // if robot is not busy
      for (int i = 0; i < busyRobots.size(); i++) {
         if (busyRobots[i] == robot) {
            busyRobots.erase(availableRobots.begin() + i);
         }
      }
      availableRobots.push_back(robot);
    }
};

void Fleet::addToFleet(Robot* robot) {
   fleet.push_back(robot);
};

std::vector<Robot*> Fleet::getFleet() {
   return fleet;
};

std::vector<Robot*> Fleet::getAvailableRobots() {
   return availableRobots;
};

std::vector<Robot*> Fleet::getBusyRobots() {
   return busyRobots;
};