#ifndef LIBCLEAN_ROBOT_HPP
#define LIBCLEAN_ROBOT_HPP

#include "libclean/room.hpp"

#include <string> 
#include <math.h> 
#include <iostream>
#include <chrono>
#include <thread>

enum class Size{SMALL, LARGE};

class Robot {
    private:
        std::string name;
        int id;
        float battery_;
        Size size;
        Room* location;
        bool busy;
        bool failed;
    public:
        static int numberOfRobots;

        Robot(std::string name, float battery, Size size, Room* location);

        bool operator==(const Robot& robot);

        std::string getName();
        int getID();
        float getBattery();
        Size getSize();
        Room* getLocation();
        bool getBusy();
        bool getFailed();

        void move(Room* room);
        void charge();
        void setName(std::string name);
        void setBattery(float percent);
        void setBusy(bool status);
        void setFailed(bool status);
        bool hasFailed();
        virtual bool isRoomClean();
};

class Sweeper : public Robot{
    public:
        using Robot::Robot;
        void sweep();
        virtual bool isRoomClean();
};

class Mopper : public Robot{
    public:
        using Robot::Robot;
        void mop();
        virtual bool isRoomClean();
};

class Scrubber : public Robot{
    public:
        using Robot::Robot;
        void scrub();
        virtual bool isRoomClean();
};

#endif