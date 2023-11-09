#include <math.h>
#include <string>
#include <iostream>

#include "libclean/room.hpp"

// Constuctor for Room
Room::Room(std::string name, float width, float length, bool sweepable, bool moppable, bool scrubbable) {
    this->name = name;
    this->width = width;
    this->length = length;
    this->sweepable = sweepable;
    this->moppable = moppable;
    this->scrubbable = scrubbable;
    if (sweepable) {
        percentSwept = 0;
    } else {
        percentSwept = NAN;
    }
    if (moppable) {
        percentMopped  = 0;
    } else {
        percentMopped = NAN;
    }
    if (scrubbable) {
        percentScrubbed = 0;
    } else {
        percentScrubbed = NAN;
    }
};

float Room::getSize(){
    return width * length;
};

void Room::setPercentSwept(float percent) {
    if(sweepable && percentSwept <= 100 && percentSwept >= 0){
        percentSwept = percent;
    }
};

void Room::setPercentMopped(float percent) {
    if(moppable && percentMopped <= 100 && percentMopped >= 0){
        percentMopped = percent;
    }
};

// can't go above 100
void Room::setPercentScrubbed(float percent) {
    if(scrubbable && percentScrubbed <= 100 && percentScrubbed >= 0){
        percentScrubbed = percent;
    }
};

void Room::randomlyDirty() {
    if (sweepable && percentSwept > 0.01) {
        percentSwept -= .01;
    }
    if (moppable && percentMopped > 0.01) {
        percentMopped -= .01;
    }
    if (scrubbable && percentScrubbed > 0.01) {
        percentScrubbed -= .01;
    }
};