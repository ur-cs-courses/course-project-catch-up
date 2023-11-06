#include "libclean/manager.hpp"


void Manager::viewRobotStatus(Robot robot){
    std::cout << "Name: " << robot.name << std::endl;
    std::cout << "Size: " << robot.size << std::endl;
    std::cout << "Battery Level: " << robot.battery << std::endl;
    std::cout << "Room: " << robot.location << std::endl;
    if(robot.hasFailed()){
        std::cout << "Status: Failed" << std::endl;
    }else if(robot.busy){
        std::cout << "Status: Busy" << std::endl;
    }else:
        std::cout << "Status: Available" << std::endl;
};
void Manager::viewLocation(Room room){
    std::cout << "Name: " << room.name << std::endl;
    string roomProperties = "This room is "
    if(room.sweepable){
        roomProperties += "sweepable "
    }
    if(room.moppable){
        if(room.sweepable && room.scrubbable){
            roomProperties += ", moppable, and "
        }else if(room.sweepable && !room.scrubbable){
            roomProperties += "and moppable"
        }else if(!room.sweepable && room.scrubbable){
            roomProperties += "moppable and "
        }
    }
    if(room. scrubbable){
        if (room.sweepable && !room.moppable){
            roomProperties += "and scrubbable"
        }else{
            roomProperties += "scrubbable"
        }
    }
    std::cout << roomProperties << std::endl;
    std::cout << "Room Status: " << std::endl;
    if(room.sweepable){
        std::cout << "Percent Swept: " << room.percentSwept << std::endl;
    }
    if(room.moppable){
        std::cout << "Percent Mopped: " << room.percentMopped << std::endl;
    }
    if(room.scrubbable){
        std::cout << "Percent Scrubbed: " << room.percentScrubbed << std::endl;
    }
};

void Manager::assignRobot(Robot robot, Room room){
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
    }