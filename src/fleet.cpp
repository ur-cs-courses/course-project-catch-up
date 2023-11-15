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
    if (robot->getBusy()) {
      for (int i = 0; i < availableRobots.size(); i++) {
         if (availableRobots[i] == robot) {
            busyRobots.push_back(robot);
            availableRobots.erase(availableRobots.begin() + i);
         }
      }
    }
    else
      for (int i = 0; i < busyRobots.size(); i++) {
         if (busyRobots[i] == robot) {
            availableRobots.push_back(robot);
            busyRobots.erase(availableRobots.begin() + i);
         }
      }
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