#include <string> 
#include <math.h> 
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "libclean/robot.hpp"
#include "libclean/fleet.hpp"
#include "libclean/timer.hpp"

int currentTimeFleet = Timer::getTime();

Fleet::Fleet(const std::string& filename)
   : fleet({}), availableRobots({}),  busyRobots({})
   {
   currentTimeFleet = Timer::getTime();
    this->filename = filename;
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Fleet object created at time " << currentTimeFleet << std::endl; 
   };

void Fleet::updateVectors(Robot* robot){
   currentTimeFleet = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Fleet updateVectors() function was called at time " << currentTimeFleet << std::endl; 
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
            busyRobots.erase(busyRobots.begin() + i);
         }
      }
      availableRobots.push_back(robot);
    }
};

void Fleet::addToFleet(Robot* robot) {
   currentTimeFleet = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Fleet addToFleet() was called to add robot: " << robot->getName() << " to fleet at time " << currentTimeFleet << std::endl; 
   fleet.push_back(robot);
};

std::vector<Robot*> Fleet::getFleet() {
   currentTimeFleet = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Fleet getFleet() function was called at time " << currentTimeFleet << std::endl; 
   return fleet;
};

std::vector<Robot*> Fleet::getAvailableRobots() {
   currentTimeFleet = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Fleet getAvailableRobots() function was called at time " << currentTimeFleet << std::endl; 
   return availableRobots;
};

std::vector<Robot*> Fleet::getBusyRobots() {
   currentTimeFleet = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Fleet getBusyRobots() function was called at time " << currentTimeFleet << std::endl; 
   return busyRobots;
};