#include <math.h>
#include <string>
#include <fstream>
#include <iostream>

#include "libclean/room.hpp"

// Constuctor for Room
Room::Room(std::string name, float width_, float length, bool sweepable, bool moppable, bool scrubbable,
 const std::string& filename) 
{
    this->filename = filename;
    std::ofstream file(filename);
    //if (!file.is_open()) {
        // Handle file opening error
      //  return;
    //}
    file << "Room object created" << std::endl; 

    this->name = name;
    this->width_ = width_;
    this->length_ = length;
    this->sweepable = sweepable;
    this->moppable = moppable;
    this->scrubbable = scrubbable;
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
    if (scrubbable) {
        percentScrubbed_ = 100;
    } else {
        percentScrubbed_ = NAN;
    }
};

std::string Room::getName() {
    std::ofstream file(filename);
    file << "Room getName() function was called" << std::endl; 
    return name;
};

float Room::getWidth() {
    std::ofstream file(filename);
    file << "Room getWidth() function was called" << std::endl; 

    return width_;
};

float Room::getLength() {
    std::ofstream file(filename);
    file << "Room getLength() function was called" << std::endl; 
    return length_;
};

float Room::getSize(){
    std::ofstream file(filename);
    file << "Room getSize() function was called" << std::endl; 
    return width_ * length_;
};

bool Room::getSweepable() {
    std::ofstream file(filename);
    file << "Room getSweepable() function was called" << std::endl; 
    return sweepable;
};

bool Room::getMoppable() {
    std::ofstream file(filename);
    file << "Room getMoppable() function was called" << std::endl; 
    return moppable;
};

bool Room::getScrubbable() {
    std::ofstream file(filename);
    file << "Room getScrubbable() function was called" << std::endl; 
    return scrubbable;
};

float Room::getPercentSwept() {
    std::ofstream file(filename);
    file << "Room getPercentSwept() function was called" << std::endl; 
    return percentSwept_;
};

float Room::getPercentMopped() {
    std::ofstream file(filename);
    file << "Room getPercentMopped() function was called" << std::endl; 
    return percentMopped_;
};

float Room::getPercentScrubbed() {
    std::ofstream file(filename);
    file << "Room getPercentScrubbed() function was called" << std::endl; 
    return percentScrubbed_;
};

void Room::setPercentSwept(float percent) {
    std::ofstream file(filename);
    file << "Room setPercentSwept() function was called" << std::endl; 
    if(sweepable && percentSwept_ <= 100 && percentSwept_ >= 0){
        percentSwept_ = percent;
    }
};

void Room::setPercentMopped(float percent) {
    std::ofstream file(filename);
    file << "Room setPercentMopped() function was called" << std::endl; 
    if(moppable && percentMopped_ <= 100 && percentMopped_ >= 0){
        percentMopped_ = percent;
    }
};

// can't go above 100
void Room::setPercentScrubbed(float percent) {
    std::ofstream file(filename);
    file << "Room setPercentScrubbed() function was called" << std::endl; 
    if(scrubbable && percentScrubbed_ <= 100 && percentScrubbed_ >= 0){
        percentScrubbed_ = percent;
    }
};

void Room::randomlyDirty() {
    std::ofstream file(filename);
    file << "Room randomlyDirty() function was called" << std::endl; 
    if (sweepable && percentSwept_ > 0.01) {
        percentSwept_ -= .01;
    }
    if (moppable && percentMopped_ > 0.01) {
        percentMopped_ -= .01;
    }
    if (scrubbable && percentScrubbed_ > 0.01) {
        percentScrubbed_ -= .01;
    }
};