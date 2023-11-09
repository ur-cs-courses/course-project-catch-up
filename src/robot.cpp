#include <string> 
#include <math.h> 
#include <iostream>
#include <chrono>
#include <thread>

#include "libclean/robot.hpp"
#include "libclean/room.hpp"

//should we use a timer? 
//if the time exisst then we add conditions related to that
Robot::Robot(std::string name, float battery, Size size, Room &location, bool busy) 
    :   name(name), battery(battery), size(size), location(location), busy(busy)
    {};

 

//assign a new condition for the battery, so that the function would check if the battery is enough for a movemrnt 
//so if the battery is lower then like 20% then go to charge (call the charge function ) 
//if the batttry is greater then that then uou can move and decrement the charhe of the batttatry 

//add a decrement function for the battery here (maybe not necessry a function but a variable ot just call (battery--))
void Robot::move(Room room) {
    if (battery <= 0) {
        std::cout << "Battery is low, need to charge." << std::endl;
        return;
    }

    if (busy) {
        std::cout << "Robot is busy and cannot move right now." << std::endl;
        return;
    }

//    std::this_thread::sleep_for(std::chrono::minutes(0.5)); //robot takes half a min to move 

    this->location = room;
    // Since robot is moving to new location its busy 
    this->busy = true;
    // Display the new location coordinate
    std::cout << name << " with battery: " << battery << " is moving to: " << location.name << std::endl;
    

    // Reduce battery by 5% to signal robot is moving and using its enery 
    this->battery -= 5;
    if (battery < 0) {
        this->battery = 0;
    }

    this->busy = false;
};

void Robot::charge() {
    if (battery >= 0.0 && battery < 100.0) {
        // Loop until the battery is fully charged
        while (battery < 100.0) {
            // charge the battery  by 5%
            battery += 5.0;
            // if exceeded 100 stop at 100 
            if (battery > 100.0) {
                battery = 100.0;
            }
        std::cout << "Charging... Battery is at " << battery << "%" << std::endl;
        // Wait for 2 seconds before the next charge -> we use thread becaosue we want the program to keep going while battery of robot is charging 
//        std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        std::cout << "The battery is 100%" << std::endl;
    } else {
        std::cout << "The battery is full so no need to charge robot." << std::endl;
    }
};


void Robot::setName(std::string newname) {
    this->name = newname;
};

bool Robot::hasFailed() {
    // Return true if the robot has encountered a failure condition, not implemented yet
    return false; 
};

bool Robot::isRoomClean() {
    return true;
};

// Sweeper
void Sweeper::sweep() {
    if (location.sweepable) {
        location.percentSwept = 100;
        this->battery = 0;
    }
};


bool Sweeper::isRoomClean() {
    if (location.sweepable) {
        if (location.percentSwept == 100) {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
};

// Mopper

void Mopper::mop() {
    if (location.moppable) {
        location.percentMopped = 100;
        this->battery = 0;
    }
};


bool Mopper::isRoomClean() {
    if (location.moppable) {
        if (location.percentMopped == 100) {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
};

// Scrubber

void Scrubber::scrub() {
    if (location.scrubbable) {
        location.percentScrubbed = 100;
        this->battery = 0;
    }
};


bool Scrubber::isRoomClean() {
    if (location.scrubbable) {
        if (location.percentScrubbed == 100) {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
};














// //for location in room (x, y) coordinates 
// struct Point {
//     int x;
//     int y;
// //constructor 
//     Point(int x_0 = 0, int y_0 = 0) : 
//     x(x_0), 
//     y(y_0) 
//     {}
    

//     // Method to set the coordinates
//     void set(int X_n, int Y_n) {
//         x = X_n;
//         y = Y_n;
//     }

//     // display coordinates
//     void display() const {
//         cout << "(" << x << ", " << y << ")" << endl;
//     }

// };