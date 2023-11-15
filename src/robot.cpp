#include <string> 
#include <math.h> 
#include <iostream>
#include <chrono>
#include <thread>

#include "libclean/robot.hpp"
#include "libclean/room.hpp"

//should we use a timer? 
//if the time exist then we add conditions related to that
Robot::Robot(std::string name, float battery_, Size size, Room *location, bool busy) 
    :   name(name), battery_(battery_), size(size), location(location), busy(busy)
    {};

//add an ID to robot
bool Robot::operator==(const Robot& robot){
    if(name == robot.name){
        return true;
    }else{
        return false;
    }
};

std::string Robot::getName() {
    return name;
};

float Robot::getBattery() {
    return battery_;
};

Size Robot::getSize() {
    return size;
};

Room* Robot::getLocation() {
    return location;
};

bool Robot::getBusy() {
    return busy;
};

//assign a new condition for the battery_, so that the function would check if the battery_ is enough for a movemrnt 
//so if the battery_ is lower then like 20% then go to charge (call the charge function ) 
//if the batttry is greater then that then uou can move and decrement the charhe of the batttatry 

//add a decrement function for the battery_ here (maybe not necessry a function but a variable ot just call (battery_--))
void Robot::move(Room *room) {
    if (battery_ <= 0) {
        std::cout << "Battery_ is low, need to charge." << std::endl;
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
    std::cout << name << " with battery_: " << battery_ << " is moving to: " << location->getName() << std::endl;
    

    // Reduce battery_ by 5% to signal robot is moving and using its enery 
    this->battery_ -= 5;
    if (battery_ < 0) {
        this->battery_ = 0;
    }

    this->busy = false;
};

void Robot::charge() {
    if (battery_ >= 0.0 && battery_ < 100.0) {
        // Loop until the battery_ is fully charged
        while (battery_ < 100.0) {
            // charge the battery_  by 5%
            battery_ += 5.0;
            // if exceeded 100 stop at 100 
            if (battery_ > 100.0) {
                battery_ = 100.0;
            }
        std::cout << "Charging... battery_ is at " << battery_ << "%" << std::endl;
        // Wait for 2 seconds before the next charge -> we use thread becaosue we want the program to keep going while battery_ of robot is charging 
//        std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        std::cout << "The battery_ is 100%" << std::endl;
    } else {
        std::cout << "The battery_ is full so no need to charge robot." << std::endl;
    }
};


void Robot::setName(std::string newname) {
    this->name = newname;
};

void Robot::setBattery(float percent){
    if(percent <= 100 && percent >= 0){
        this->battery_ = percent;
    }
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
    if (this->getLocation()->getSweepable()) {
        this->getLocation()->setPercentSwept(100);
        this->setBattery(0);
    }
};


bool Sweeper::isRoomClean() {
    if (this->getLocation()->getSweepable()) {
        if (this->getLocation()->getPercentSwept() == 100) {
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
    if (this->getLocation()->getMoppable()) {
        this->getLocation()->setPercentMopped(100);
        this->setBattery(0);
    }
};


bool Mopper::isRoomClean() {
    if (this->getLocation()->getMoppable()) {
        if (this->getLocation()->getPercentMopped() == 100) {
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
    if (this->getLocation()->getScrubbable()) {
        this->getLocation()->setPercentScrubbed(100);
        this->setBattery(0);
    }
};


bool Scrubber::isRoomClean() {
    if (this->getLocation()->getScrubbable()) {
        if (this->getLocation()->getPercentScrubbed() == 100) {
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