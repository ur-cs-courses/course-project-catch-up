#include "libclean/timer.hpp"

Timer::Timer(){};

int Timer::time(0);

void Timer::addTime() {
    time += 1;
};

int Timer::getTime() {
    return time;
};