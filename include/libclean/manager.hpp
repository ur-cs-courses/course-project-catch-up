#ifndef LIBCLEAN_MANAGER_HPP
#define LIBCLEAN_MANAGER_HPP

#include "libclean/room.hpp"
#include "libclean/robot.hpp"

class Manager{

    public:
        void viewRobotStatus(Robot robot);
        void viewLocation(Room room);

        void assignRobot(Robot& robot, Room room);

        //void callTech(Robot robot);

        //void displayDirtyRooms();
        //void displayCleanRooms();
        //void displayAllRooms();
        //void displayBusyRobots()
        //void displayAvailableRobots()
        //void displayFleet(Fleet fleet)
};

#endif