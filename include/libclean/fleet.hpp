#ifndef LIBCLEAN_FLEET_HPP
#define LIBCLEAN_FLEET_HPP

#include "libclean/robot.hpp"
#include <string> 
#include <math.h> 
#include <iostream>
#include <chrono>
#include <thread>

class Fleet{
    public:
      list<Robot> fleet;
      list<Robot> AvailableRobots;
      list<Robot> BusyRobots;
      void updateLists(Robot robot);
}

#endif