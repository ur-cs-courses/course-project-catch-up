#include <list>
#include <string> 
#include <iostream>
#include <chrono>
#include <thread>
#include "libclean/robot.hpp" 
#include "libclean/Technician.hpp"
 using namespace std;

class Technician {
public:

    Technician() {}

    list<Robot> Busy_robot_queue; //the queue of robots 

    // Adds a robot to the busy queue if it's not already in the queue and if the robot has failed
    void addRobotToQueue(Robot& robot) {
        if (robot.hasFailed()) {
        
            auto it = find_if(Busy_robot_queue.begin(), Busy_robot_queue.end(), 
                                   [&robot](const Robot& r) { return r.getName() == robot.getName(); });

            if (it == Busy_robot_queue.end()) { 
                // Robot not in the queu then add it
                Busy_robot_queue.push_back(robot);
            }
        //if robot in quueu no need to add it. this actually should not happen - but just in case 
        }
    }

    // Fixes the robot and removes it from the busy queue
    void technician_fixes_robot(Robot& robot){
        robot.battery = 100.0; // Set the battery to 100%
        isFixed(robot); // Remove the robot from the busy queue
    }

    bool isFixed(Robot& robot) { 
        // Remove the robot from the busy queue and return true that the robot is fixed 
        Busy_robot_queue.remove_if([&robot](const Robot& r) { return r.getName() == robot.getName(); });
        return true; 
    }

    void Robot_isOkay(Robot& robot){

    if (robot.battary != 0.0) {
       cout << "Robot is Okay don't bother me until the battary is 0.0" << endl;
    } else {
       cout << "Ok i will fix it"<< endl;
    }

    }

    // Checks if the technician is busy
    bool isTechBusy() const {
        return !Busy_robot_queue.empty();
    }


};
