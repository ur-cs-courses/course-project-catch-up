#include <math.h>
#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include "libclean/timer.hpp"
#include "libclean/room.hpp"

// need to change rooms names to always be unique - constructor

int Room::numberOfRooms = 0;
int currentTime = Timer::getTime();
// Constuctor for Room
Room::Room(std::string name, float width_, float length_, bool sweepable, bool moppable, bool scrubbable, bool vacuumable,
 const std::string& filename) 
 : name(name), id(numberOfRooms), width_(width_), length_(length_), sweepable(sweepable), moppable(moppable), scrubbable(scrubbable), vacuumable(vacuumable)
{
    currentTime = Timer::getTime();
    numberOfRooms++;
    this->filename = filename;
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room " <<  name << " object created at " << currentTime << std::endl; 

    if (sweepable) {
        percentSwept_ = 100;
    } else {
        percentSwept_ = NAN;
    }
    if (moppable) {
        percentMopped_  = 100;
    } else {
        percentMopped_ = NAN;
    }
    if (vacuumable) {
        percentVacuumed_  = 100;
    } else {
        percentVacuumed_ = NAN;
    }
    if (scrubbable) {
        percentScrubbed_ = 100;
    } else {
        percentScrubbed_ = NAN;
    }
};

std::string Room::getName() {
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getName() function was called at time " << currentTime << " for room " << name << std::endl; 
    return name;
};

float Room::getWidth() {
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getWidth() function was called  at time " << currentTime  << " for room"  << name << std::endl; 

    return width_;
};

float Room::getLength() {
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getLength() function was called at time " << currentTime  << " for room " << name << std::endl; 
    return length_;
};

float Room::getSize(){
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getSize() function was called at time " << currentTime << " for room " << name << std::endl; 
    return width_ * length_;
};

int Room::getID() {
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getID() function was called at time " << currentTime << " for room " << name << std::endl; 
    return id;
};

bool Room::operator==(const Room& room){
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Checking Room id at time " << currentTime << " for room " << name << std::endl;
    if(id == room.id){
        return true;
    }else{
        return false;
    }
};

bool Room::getSweepable() {
    currentTime = Timer::getTime();
     std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getSweepable() function was called at time " << currentTime << " for room " << name << std::endl; 
    return sweepable;
};

bool Room::getVacuumable() {
     std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getVacuumable() function was called" << std::endl; 
    return vacuumable;
};

bool Room::getMoppable() {
    currentTime = Timer::getTime();
     std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getMoppable() function was called at time " << currentTime << " for room " << name << std::endl; 
    return moppable;
};

bool Room::getScrubbable() {
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getScrubbable() function was called at time " << currentTime  << " for room " << name << std::endl; 
    return scrubbable;
};

float Room::getPercentSwept() {
    currentTime = Timer::getTime();
     std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getPercentSwept() function was called at time " << currentTime << " for room " << name << std::endl; 
    return percentSwept_;
};

float Room::getPercentMopped() {
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getPercentMopped() function was called at time " << currentTime << " for room " << name << std::endl; 
    return percentMopped_;
};

float Room::getPercentScrubbed() {
    currentTime = Timer::getTime();
   std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getPercentScrubbed() function was called at time " << currentTime << " for room " << name << std::endl; 
    return percentScrubbed_;
};

float Room::getPercentVacuumed() {
   std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room getPercentVacuumed() function was called" << std::endl; 
    return percentVacuumed_;
};

void Room::setPercentSwept(float percent) {
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room setPercentSwept() function was called at time " << currentTime << " for room " << name << std::endl; 
    if(sweepable && percentSwept_ <= 100 && percentSwept_ >= 0){
        percentSwept_ = percent;
    }
};

void Room::setPercentMopped(float percent) {
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room setPercentMopped() function was called at time " << currentTime << " for room " << name << std::endl; 
    if(moppable && percentMopped_ <= 100 && percentMopped_ >= 0){
        percentMopped_ = percent;
    }
};
void Room::setPercentVacuumed(float percent) {
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room setPercentVacuumed() function was called" << std::endl; 
    if(vacuumable && percentVacuumed_ <= 100 && percentVacuumed_ >= 0){
        percentVacuumed_ = percent;
    }
};

void Room::setPercentScrubbed(float percent) {
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room setPercentScrubbed() function was called at time " << currentTime << " for room " << name << std::endl; 
    if(scrubbable && percentScrubbed_ <= 100 && percentScrubbed_ >= 0){
        percentScrubbed_ = percent;
    }
};

void Room::randomlyDirty() { 
    currentTime = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Room randomlyDirty() function was called at time " << currentTime << " for room " << name << std::endl; 
    if (sweepable) {
        std::srand(std::time(0));
        double percentRandDirty = (((double)std::rand()) / RAND_MAX) * 100;
        percentSwept_ = percentRandDirty;
    }
    if (moppable) {
        std::srand(std::time(0));
        double percentRandDirty = (((double)std::rand()) / RAND_MAX) * 100;
        percentMopped_ = percentRandDirty;
    }
    if (vacuumable) {
        std::srand(std::time(0));
        double percentRandDirty = (((double)std::rand()) / RAND_MAX) * 100;
        percentVacuumed_ = percentRandDirty;
    }
    if (scrubbable) {
        std::srand(std::time(0));
        double percentRandDirty = (((double)std::rand()) / RAND_MAX) * 100;
        percentScrubbed_ = percentRandDirty;
    }
};