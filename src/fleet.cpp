#include <string> 
#include <math.h> 
#include <iostream>
#include <chrono>
#include <thread>
#include "libclean/robot.hpp"
#include "libclean/fleet.hpp"

Fleet::Fleet(list<Robot> fleet, list<Robot> AvailableRobots, list<Robot> BusyRobots)
   : fleet (fleet), available (AvailableRobots),  busy (BusyRobots)
   {};

void Fleet::UpdateLists(Robot robot){
    if (Robot.busy):
       BusyRobots.push_back(Robot);
    else:
       AvailableRobots.push_back(Robot);
}