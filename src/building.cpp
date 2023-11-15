#include "libclean/building.hpp"




Building::Building()
    : building({})
    {};

void Building::addRoom(Room* room){
    building.push_back(room);
};


std::vector<Room*> Building::getBuilding(){
    return building;
};


std::vector<Room*> Building::getDirtyRooms(){
    std::vector<Room*> dirtyRooms;
    for (Room* r : building){
        bool clean = true;
        if(r->getSweepable()){
            if(r->getPercentSwept() != 100){
                clean = false;
            }
        }
        if(r->getMoppable()){
            if(r->getPercentMopped() != 100){
                clean = false;
            }
        }
        if(r->getScrubbable()){
            if(r->getPercentScrubbed() != 100){
                clean = false;
            }
        }
        if(!clean){
            dirtyRooms.push_back(r);
        }
    }
    return dirtyRooms;
};


std::vector<Room*> Building::getCleanRooms(){
    std::vector<Room*> cleanRooms;
    for (Room* r : building){
        bool clean = true;
        if(r->getSweepable()){
            if(r->getPercentSwept() != 100){
                clean = false;
            }
        }
        if(r->getMoppable()){
            if(r->getPercentMopped() != 100){
                clean = false;
            }
        }
        if(r->getScrubbable()){
            if(r->getPercentScrubbed() != 100){
                clean = false;
            }
        }
        if(clean){
            cleanRooms.push_back(r);
        }
    }
    return cleanRooms;
};