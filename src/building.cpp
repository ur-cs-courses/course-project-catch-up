#include "libclean/building.hpp"
#include "libclean/timer.hpp"

int currentTimeBuilding = Timer::getTime();

Building::Building(const std::string& filename)
    : building({})
    {
    currentTimeBuilding = Timer::getTime();
    this->filename = filename;
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Building object created at time " << currentTimeBuilding << std::endl; 
};

void Building::addRoom(Room* room){
    currentTimeBuilding = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Building addRoom() function was called at time " << currentTimeBuilding << std::endl; 
    building.push_back(room);
};


std::vector<Room*> Building::getBuilding(){
    currentTimeBuilding = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Building getBuilding() function was called at time " << currentTimeBuilding << std::endl; 
    return building;
};


std::vector<Room*> Building::getDirtyRooms(){
    currentTimeBuilding = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Building getDirtyRooms() function was called at time " << currentTimeBuilding << std::endl; 
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
    currentTimeBuilding = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Building getCleanRooms() function was called at time " << currentTimeBuilding << std::endl; 
    
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