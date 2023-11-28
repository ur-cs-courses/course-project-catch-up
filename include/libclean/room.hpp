#ifndef LIBCLEAN_ROOM_HPP
#define LIBCLEAN_ROOM_HPP

#include <string> 
#include <math.h> 
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>

class Room{
    private:
        std::string name;
        std::string filename = "default.csv";
        float width_;
        float length_;
        bool sweepable;
        bool moppable;
        bool scrubbable;

    public:
        Room(std::string name, float width, float length, bool sweepable, bool moppable, bool scrubbable,const std::string& filename);
        
        float percentSwept_;
        float percentMopped_;
        float percentScrubbed_;

        std::string getName();
        float getWidth();
        float getLength();
        float getSize();
        bool getSweepable();
        bool getMoppable();
        bool getScrubbable();
        float getPercentSwept();
        float getPercentMopped();
        float getPercentScrubbed();

        void setPercentSwept(float percent);
        void setPercentMopped(float percent);
        void setPercentScrubbed(float percent);

        void randomlyDirty();
};

#endif