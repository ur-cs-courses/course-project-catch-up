#include "libclean/manager.hpp"
#include "libclean/fleet.hpp"
#include "libclean/robot.hpp" 
#include "libclean/room.hpp"
#include "libclean/building.hpp"
#include "libclean/timer.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

std::vector<std::string> split(const std::string &s, const std::string &split_on) {
    //function for handling splitting a string into a vector, taken from project from CMSC 301
    std::vector<std::string> split_terms;
    int cur_pos = 0;
    while(cur_pos >= 0) {
        int new_pos = s.find_first_not_of(split_on, cur_pos);
        cur_pos = s.find_first_of(split_on, new_pos);
        if(new_pos == -1 && cur_pos == -1) break; 
        split_terms.push_back(s.substr(new_pos,cur_pos-new_pos));
    }
    return split_terms;
}


int main() {
    std::srand(std::time(0));
    Timer timer;
    Building building{"logfile.csv"};
    Fleet fleet{"logfile.csv"};
    Manager manager("logfile.csv");
    Technician technician{"logfile.csv"};

    Room baseObject {"Base", 0, 0, false, false, false, false, "logfile.csv"};
    Room* base = &baseObject;
    building.addRoom(base);

    std::ifstream infile("../../app/input.txt"); //where to grab
    if (!infile) { 
        std::cerr << "Error: could not open file: input.txt" << std::endl;
        exit(1);
    }

    const std::string WHITESPACE = " \n\r\t\f\v";

    std::string str;
    bool makeRooms = false;

    while(getline(infile, str)){
        if (str != ""){
            std::vector<std::string> terms = split(str, WHITESPACE+",()");
            if (terms[0] == "robots:"){
            }else if (terms[0] == "rooms:"){
                makeRooms = true;
            }else if(!makeRooms){
                Size size;
                Job job;
                if (terms[1] == "small"){
                    size = Size::SMALL;
                }else if (terms[1] == "large"){
                    size = Size::LARGE;
                }
                if (terms[2] == "sweeper"){
                    job = Job::SWEEPER;
                }else if (terms[2] == "mopper"){
                    job = Job::MOPPER;
                }else if (terms[2] == "scrubber"){
                    job = Job::SCRUBBER;
                } else if (terms[2] == "vacuumer") {
                    job = Job::VACUUMER;
                }
                Robot* robot = new Robot(terms[0], 100, size, base, "logfile.csv", job);
                fleet.addToFleet(robot);
                fleet.updateVectors(robot);
            }else{
                Room* room = new Room(terms[0], std::stof(terms[1]), std::stof(terms[2]), terms[3] == "true", terms[4] == "true", terms[5] == "true", terms[6] == "true", "logfile.csv");
                building.addRoom(room);
            }
        }
    }

    int wait = 0;

    Robot* waitingRobot;

    bool waitingOnRobot = false;
    
    while(true) {
        bool ongoingInstructions = true;

        std::cout << "Current Time: " << timer.getTime() << std::endl;

        while(ongoingInstructions && wait == 0 && !waitingOnRobot){
            std::string firstArg;
            std::string secondArg;
            std::string thirdArg;
            std::cin >> firstArg;
            if (firstArg == "help") {
                std::cout << std::endl;
                std::cout << "List of Commands: " << std::endl;

                std::cout << std::endl;
                std::cout << "assign - [assign] [robotName] [roomName]" << std::endl;
                std::cout << "Assigns [robotName] to clean [roomName]" << std::endl;

                std::cout << std::endl;
                std::cout << "display - [display] [dirty rooms] / [clean rooms] / [all rooms] / [busy robots] / [available robots] / [all robots]" << std::endl;
                std::cout << "Displays target specified" << std::endl;

                std::cout << std::endl;
                std::cout << "view - [view] [robotName] / [roomName]" << std::endl;
                std::cout << "Shows status of [robotName] or status of [roomName]" << std::endl;

                std::cout << std::endl;
                std::cout << "call technician - [call] [technician] [robotName]" << std::endl;
                std::cout << "Calls [technician] to fix [robotName]" << std::endl;

                std::cout << std::endl;
                std::cout << "time - [time] [time units you'd like to advance] / [until] [robotName]" << std::endl;
                std::cout << "Advances time forward either a specified number of time units, or until robotName completes its assigned task (or fails to do the task)" << std::endl;

                std::cout << std::endl;
                std::cout << "dirty - [dirty] [roomName]" << std::endl;
                std::cout << "Dirties the room specified" << std::endl;

                std::cout << std::endl;
                std::cout << "exit - [exit]" << std::endl;
                std::cout << "Terminate the program" << std::endl;

                std::cout << std::endl;

            } else if (firstArg == "time") {
                std::cin >> secondArg;
                bool isNotNum = false;
                for(int i = 0; i < secondArg.size(); i++){
                    if(!isdigit(secondArg[i])){
                        isNotNum = true;
                    }
                }
                if (!isNotNum){
                    int newTime = std::stoi(secondArg);
                    if (newTime > 0){
                        wait = newTime;
                        ongoingInstructions = false;
                    }else{
                        std::cout << "The integer specified by time needs to be positive.  Please try again." << std::endl;
                    }
                }else if(secondArg == "until"){
                    std::cin >> thirdArg;
                    for (Robot* robot : fleet.getFleet()) {
                        if (thirdArg == robot->getName()) {
                            waitingRobot = robot;
                            waitingOnRobot = true;
                            ongoingInstructions = false;
                        }
                    }
                }else{
                    std::cout << "Command not recognized. Type 'help' for list of valid commands." << std::endl;
                }
            } else if (firstArg == "assign") { // [assign] [robotName] [roomName]
                std::cin >> secondArg;
                std::cin >> thirdArg;
                bool foundRobot = false;
                bool foundRoom = false;
                for (Robot* robot : fleet.getFleet()) {
                    if (secondArg == robot->getName()) {
                        foundRobot = true;
                        for (Room* room : building.getBuilding()) {
                            if (thirdArg == room->getName()) {
                                foundRoom = true;
                                manager.assignRobot(robot, room);
                                fleet.updateVectors(robot);
                            }
                        }
                    }
                }
                if (!foundRobot || !foundRoom) {
                    std::cout << "Robot or Room not found. Please try again." << std::endl;
                }
            } else if (firstArg == "display") { // fix later
                std::cin >> secondArg;
                std::cin >> thirdArg;
                if (secondArg == "dirty" && thirdArg == "rooms") {
                    manager.displayDirtyRooms(building);
                } else if (secondArg == "clean" && thirdArg == "rooms") {
                    manager.displayCleanRooms(building);
                } else if (secondArg == "all" && thirdArg == "rooms") {
                    manager.displayAllRooms(building);
                } else if (secondArg == "busy" && thirdArg == "robots") {
                    manager.displayBusyRobots(fleet);
                } else if (secondArg == "available" && thirdArg == "robots") {
                    manager.displayAvailableRobots(fleet);
                } else if (secondArg == "all" && thirdArg == "robots") {
                    manager.displayFleet(fleet);
                } else {
                    std::cout << "Command not recognized. Type 'help' for list of valid commands." << std::endl;
                }
            } else if (firstArg == "view") {
                std::cin >> secondArg;
                bool foundObject = false;
                for (Robot* robot : fleet.getFleet()) {
                    if (secondArg == robot->getName()) {
                        foundObject = true;
                        manager.viewRobotStatus(robot);
                    }
                }
                for (Room* room : building.getBuilding()) {
                    if (secondArg == room->getName()) {
                        foundObject = true;
                        manager.viewLocation(room);
                    }
                }
                if (!foundObject) {
                    std::cout << "Robot or Room not found. Please try again." << std::endl;
                }
            } else if (firstArg == "call") {
                std::cin >> secondArg;
                std::cin >> thirdArg;
                bool foundRobot = false;
                if (secondArg == "technician") {
                    for (Robot* robot : fleet.getFleet()) {
                        if (thirdArg == robot->getName()) {
                            foundRobot = true;
                            manager.callTech(robot, technician);
                            robot->setLocation(base);
                        }
                    }
                    if (!foundRobot) {
                        std::cout << "Robot not found. Please try again." << std::endl;
                    }
                } else {
                    std::cout << "Command not recognized. Type 'help' for list of valid commands." << std::endl;
                }
            } else if (firstArg == "dirty") {
                std::cin >> secondArg;
                bool foundRoom = false;
                for (Room* room : building.getBuilding()) {
                    if (secondArg == room->getName()) {
                        foundRoom = true;
                        room->randomlyDirty();
                    }
                }
                if (!foundRoom) {
                    std::cout << "Room not found. Please try again." << std::endl;
                }
            } else if (firstArg == "exit") {
                return 0;
            } else {
                std::cout << "Command not recognized. Type 'help' for list of valid commands." << std::endl;
            }
        }
        for (Robot* r : fleet.getFleet()) {
            if (r->getLocation() == base) {
                //do something
                r->charge();
            } else {
                r->setFailed(r->hasFailed());
                r->clean();
                if (r->isRoomClean()) {
                    r->move(base);
                    r->setBusy(false);
                    fleet.updateVectors(r);
                }
            }
        }
        technician.technicianFixesRobot();
        timer.addTime();
        if (wait > 0){
            wait -= 1;
        }
        if(waitingRobot->hasFailed() || waitingRobot->getLocation() == base){
            waitingOnRobot = false;
        }
    }
};