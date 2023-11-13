#include "libclean/manager.hpp"
#include <string>
#include <iostream>

void Manager::viewRobotStatus(Robot robot){
    std::cout << "Name: " << robot.getName() << std::endl;
    if (robot.getSize() == Size::SMALL) {
        std::cout << "Size: Small" << std::endl;
    } else if (robot.getSize() == Size::LARGE) {
        std::cout << "Size: Large" << std::endl;
    }
    std::cout << "Battery Level: " << robot.getBattery() << std::endl;
    std::cout << "Room: " << robot.getLocation().getName() << std::endl;
    if(robot.hasFailed()){
        std::cout << "Status: Failed" << std::endl;
    }else if(robot.getBusy()){
        std::cout << "Status: Busy" << std::endl;
    }else {
        std::cout << "Status: Available" << std::endl;
    }
};

void Manager::viewLocation(Room room) {
    std::cout << "Name: " << room.getName() << std::endl;
    std::string roomProperties = "This room is ";
    if (room.getSweepable()) {
        roomProperties += "sweepable ";
    }
    if (room.getMoppable()) {
        if(room.getSweepable() && room.getScrubbable()){
            roomProperties += ", moppable, and ";
        }else if(room.getSweepable() && !room.getScrubbable()){
            roomProperties += "and moppable";
        }else if(!room.getSweepable() && room.getScrubbable()){
            roomProperties += "moppable and ";
        }
    }
    if(room.getScrubbable()){
        if (room.getSweepable() && !room.getMoppable()){
            roomProperties += "and scrubbable";
        }else{
            roomProperties += "scrubbable";
        }
    }
    std::cout << roomProperties << std::endl;
    std::cout << "Room Status: " << std::endl;
    if(room.getSweepable()){
        std::cout << "Percent Swept: " << room.getPercentSwept() << std::endl;
    }
    if(room.getMoppable()){
        std::cout << "Percent Mopped: " << room.getPercentMopped() << std::endl;
    }
    if(room.getScrubbable()){
        std::cout << "Percent Scrubbed: " << room.getPercentScrubbed() << std::endl;
    }
};

void Manager::assignRobot(Robot &robot, Room room){
    //if (robot can clean room without running out of battery...){
    //
    //}
    robot.move(room);
};

        //void callTech(Robot robot);
        //void displayDirtyRooms();
        //void displayCleanRooms();
        //void displayAllRooms();
        //void displayBusyRobots()
        //void displayAvailableRobots()
        //void displayFleet(Fleet fleet)
    