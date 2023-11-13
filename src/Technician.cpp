#include <list>
#include <string> 
#include <iostream>
#include <chrono>
#include <thread>
#include "libclean/robot.hpp" 
#include "libclean/Technician.hpp"
 
class Technician {
public:
    Technician() {}

    // Adds a robot to the busy queue if it's not already in the queue and if the robot has failed
    void addRobotToQueue(Robot& robot) {
        if (robot.hasFailed()) {
            // Check if the robot is already in the queue
            auto it = std::find_if(Busy_robot_queue.begin(), Busy_robot_queue.end(), 
                                   [&robot](const Robot& r) { return r.getName() == robot.getName(); });

            if (it == Busy_robot_queue.end()) {
                // Robot not in the queue, add it
                Busy_robot_queue.push_back(robot);
            }
            // If the robot is already in the queue, no action is needed
        }
    }

    // Fixes the robot and removes it from the busy queue
    void technician_fixes_robot(Robot& robot){
        robot.battery = 100.0; // Set the battery to 100%
        isFixed(robot); // Remove the robot from the busy queue
    }

    // Simulates fixing a robot
    bool isFixed(Robot& robot) {
        // Remove the robot from the busy queue
        Busy_robot_queue.remove_if([&robot](const Robot& r) { return r.getName() == robot.getName(); });
        return true; // Assume the robot is fixed for now
    }

    // Checks if the technician is busy
    bool isTechBusy() const {
        return !Busy_robot_queue.empty();
    }

private:
    std::list<Robot> Busy_robot_queue;
};
