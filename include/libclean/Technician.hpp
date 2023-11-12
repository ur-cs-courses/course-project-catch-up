#ifndef LIBCLEAN_TECHNICIAN_H
#define LIBCLEAN_TECHNICIAN_H
#include <list>
#include "libclean/Technician.h" // Include the Robot class header
#include <iostream>

class Technician {

public:

    Technician();

    void addRobotToQueue(Robot& robot);
    bool isFixed(Robot& robot);
    bool isTechBusy() const;

private:
    std::list<Robot> Busy_robot_queue;
};

#endif // TECHNICIAN_H
