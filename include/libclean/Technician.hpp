#ifndef LIBCLEAN_TECHNICIAN_H
#define LIBCLEAN_TECHNICIAN_H
#include <list>
#include "libclean/Technician.h" // Include the Robot class header
#include <iostream>
using namespace std;
class Technician {

public:

    Technician();

    void addRobotToQueue(Robot& robot);
    bool isFixed(Robot& robot);
    bool isTechBusy() const;
    void Robot_isOkay(Robot& robot);
    list<Robot> Busy_robot_queue;
};

#endif // TECHNICIAN_H
