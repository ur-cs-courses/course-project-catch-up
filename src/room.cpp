#include <math.h>
#include <string>
#include <iostream>

#include "libclean/room.hpp"

// Constuctor for Room
Room::Room(std::string name, float width_, float length, bool sweepable, bool moppable, bool scrubbable) {
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
    return name;
};

float Room::getWidth() {
    return width_;
};

float Room::getLength() {
    return length_;
};

float Room::getSize(){
    return width_ * length_;
};

bool Room::getSweepable() {
    return sweepable;
};

bool Room::getMoppable() {
    return moppable;
};

bool Room::getScrubbable() {
    return scrubbable;
};

float Room::getPercentSwept() {
    return percentSwept_;
};

float Room::getPercentMopped() {
    return percentMopped_;
};

float Room::getPercentScrubbed() {
    return percentScrubbed_;
};

void Room::setPercentSwept(float percent) {
    if(sweepable && percentSwept_ <= 100 && percentSwept_ >= 0){
        percentSwept_ = percent;
    }
};

void Room::setPercentMopped(float percent) {
    if(moppable && percentMopped_ <= 100 && percentMopped_ >= 0){
        percentMopped_ = percent;
    }
};

// can't go above 100
void Room::setPercentScrubbed(float percent) {
    if(scrubbable && percentScrubbed_ <= 100 && percentScrubbed_ >= 0){
        percentScrubbed_ = percent;
    }
};

void Room::randomlyDirty() {
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