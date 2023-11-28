#include <string> 
#include <math.h> 
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <iostream>

#include "libclean/robot.hpp"
#include "libclean/room.hpp"

//should we use a timer? 
//if the time exist then we add conditions related to that
int Robot::numberOfRobots = 0;

Robot::Robot(std::string name, float battery_, Size size, Room *location, const std::string& filename) 
    :   name(name), id(numberOfRobots), battery_(battery_), size(size), location(location), busy(false), failed(false)
    {numberOfRobots++;
    this->filename = filename;
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot object created" << std::endl; 
};

bool Robot::operator==(const Robot& robot){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Checking Robot id" << std::endl;
    if(id == robot.id){
        return true;
    }else{
        return false;
    }
};

std::string Robot::getName() {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getName() function was  called" << std::endl;
    return name;
};

int Robot::getID(){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getID() function was called" << std::endl;
    return id;
};

float Robot::getBattery() {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getBattery() function was called" << std::endl;
    return battery_;
};

Size Robot::getSize() {
   std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getSize() function was called" << std::endl;
    return size;
};

Room* Robot::getLocation() {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getLocation() function was called" << std::endl;
    return location;
};

bool Robot::getBusy() {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getBusy() function was called" << std::endl;
    return busy;
};

bool Robot::getFailed() {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getFailed() function was called" << std::endl;
    return failed;
};

//assign a new condition for the battery_, so that the function would check if the battery_ is enough for a movemrnt 
//so if the battery_ is lower then like 20% then go to charge (call the charge function ) 
//if the batttry is greater then that then uou can move and decrement the charhe of the batttatry 

//add a decrement function for the battery_ here (maybe not necessry a function but a variable ot just call (battery_--))
void Robot::move(Room *room) {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot move() function was called" << std::endl;
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
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot charge() function was called" << std::endl;
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
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot setName() function was called" << std::endl;
    this->name = newname;
};

void Robot::setBattery(float percent){
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot setBattery() function was called" << std::endl;
    if(percent <= 100 && percent >= 0){
        this->battery_ = percent;
    }
};

bool Robot::hasFailed() {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot hasFailed() function was called" << std::endl;
    return battery_ == 0;
};

bool Robot::isRoomClean() {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot isRoomClean() function was called" << std::endl;
    return true;
};

void Robot::setBusy(bool status) {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot setBusy() function was called" << std::endl;
    this->busy = status;
}

void Robot::setFailed(bool status) {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot setFailed() function was called" << std::endl;
    this->failed = status;
}


// Sweeper
void Sweeper::sweep() {
    std::ofstream file;
    file.open("logfile.csv", std::ofstream::app);
    file << "Sweeper sweep() function was called" << std::endl;
    if (this->getLocation()->getSweepable()) {
        this->getLocation()->setPercentSwept(100);
        this->setBattery(0);
    }
};


bool Sweeper::isRoomClean() {
     std::ofstream file;
    file.open("logfile.csv", std::ofstream::app);
    file << "Sweeper isRoomClean() function was called" << std::endl;
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
    std::ofstream file;
    file.open("logfile.csv", std::ofstream::app);
    file << "Mopper mop() function was called" << std::endl;
    if (this->getLocation()->getMoppable()) {
        this->getLocation()->setPercentMopped(100);
        this->setBattery(0);
    }
};


bool Mopper::isRoomClean() {
    std::ofstream file;
    file.open("logfile.csv", std::ofstream::app);
    file << "Mopper isRoomClean() function was called" << std::endl;
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
    std::ofstream file;
    file.open("logfile.csv", std::ofstream::app);
    file << "Scrubber scrub() function was called" << std::endl;
    if (this->getLocation()->getScrubbable()) {
        this->getLocation()->setPercentScrubbed(100);
        this->setBattery(0);
    }
};


bool Scrubber::isRoomClean() {
    std::ofstream file;
    file.open("logfile.csv", std::ofstream::app);
    file << "Scrubber isRoomClean() function was called" << std::endl;
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