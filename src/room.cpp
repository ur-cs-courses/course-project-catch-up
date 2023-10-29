#include <math.h>

#include "libclean/room.hpp"

// Constuctor for Room
Room::Room(string name, float width, float length, bool sweepable, bool moppable, bool scrubbable) {
    Name = name;
    width = width;
    length = length;
    sweepable = sweepable;
    moppable = moppable;
    scrubbable = scrubbable;
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

float Room::setPercentSwept(float percent) {
    percentSwept = percent;
};

float Room::setPercentMopped(float percent) {
    percentMopped = percent;
};

float Room::setPercentScrubbed(float percent) {
    percentScrubbed = percent;
};

void Room::randomlyDirty() {
    if (sweepable) {
        percentSwept += .01;
    }
    if (moppable) {
        percentMopped += .01;
    }
    if (scrubbable) {
        percentScrubbed += .01;
    }
};