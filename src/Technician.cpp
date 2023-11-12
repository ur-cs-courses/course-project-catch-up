#include <list>
#include "libclean/Technician.h"
#include <string> 
#include <math.h> 
#include <iostream>
#include <chrono>
#include <thread>


class Technician {
public:
    Technician() {}

    // Adds a robot to the busy queue if it's not already in the queue
    void addRobotToQueue(Robot& robot) {
        // Check if the robot is already in the queue

        for (auto& r : Busy_robot_queue) {
            if (r.getName() == robot.getName()) {
                return; // Robot already in the queue
            }
        }
        Busy_robot_queue.push_back(robot);
    }

    // Simulates fixing a robot
    bool isFixed(Robot& robot) {
        // Remove the robot from the busy queue
        Busy_robot_queue.remove_if([&robot](const Robot& r) { return r.getName() == robot.getName(); });
        return true; 
        // Assume the robot is fixed for now
    }

    // Checks if the technician is busy
    bool isTechBusy() const {
        return !Busy_robot_queue.empty();
    }

private:
    std::list<Robot> Busy_robot_queue;
};
