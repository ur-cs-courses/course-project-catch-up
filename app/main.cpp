#include "libclean/manager.hpp"
#include "libclean/fleet.hpp"
#include "libclean/robot.hpp" 
#include "libclean/room.hpp"
#include "libclean/building.hpp"
#include "libclean/timer.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    Timer timer;
    Building building{"logfile.csv"};

    Room officeObject {"Office", 16.0, 12.5, true, true, true, "logfile.csv"};
    Room* office = &officeObject;
    building.addRoom(office);

    Room baseObject {"Base", 0, 0, false, false, false, "logfile.csv"};
    Room* base = &baseObject;
    building.addRoom(base);

    Room atriumObject {"Atrium", 16.0, 12.5, false, true, true, "logfile.csv"};
    Room* atrium = &atriumObject;
    building.addRoom(atrium);

    Room csMajorLabObject {"CSMajorLab", 20.0, 10.0, true, false, false, "logfile.csv"};
    Room* csMajorLab = &csMajorLabObject;
    building.addRoom(csMajorLab);

    Fleet fleet{"logfile.csv"};

    Robot Robot1Object {"Robot1", 100, Size::SMALL, base, "logfile.csv", Job::SCRUBBER};
    Robot* robot1 = &Robot1Object;
    fleet.addToFleet(robot1);
    fleet.updateVectors(robot1);

    Robot Robot2Object {"Robot2", 100, Size::LARGE, base, "logfile.csv", Job::SWEEPER};
    Robot* robot2 = &Robot2Object;
    fleet.addToFleet(robot2);
    fleet.updateVectors(robot2);

    Robot Robot3Object {"Robot3", 100, Size::LARGE, base, "logfile.csv", Job::MOPPER};
    Robot* robot3 = &Robot3Object;
    fleet.addToFleet(robot3);
    fleet.updateVectors(robot3);

    Manager manager("logfile.csv");

    Technician technician{"logfile.csv"};

    while(true) {
        bool ongoingInstructions = true;
        while(ongoingInstructions){
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
                std::cout << "call - [call] [technician] [robotName]" << std::endl;
                std::cout << "Calls [technician] to fix [robotName]" << std::endl;

                std::cout << std::endl;
                std::cout << "time - [time]" << std::endl;
                std::cout << "Advances time forward" << std::endl;

                std::cout << std::endl;
                std::cout << "dirty - [dirty] [roomName]" << std::endl;
                std::cout << "Dirties the room specified" << std::endl;

                std::cout << std::endl;
                std::cout << "exit - [exit]" << std::endl;
                std::cout << "Terminate the program." << std::endl;

                std::cout << std::endl;

            } else if (firstArg == "time") {
                ongoingInstructions = false;
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
    }
//     if (argc != 4) {
//         std::cerr << "The command line should be in formate: " << argv[0] << " <robot> <action> <room>" << std::endl;
//         return 1;
//     }

//     std::string robotName = argv[1];
//     std::string action = argv[2];
//     std::string roomName = argv[3];

//     // make building and room and robot objects
//     Building building;
//     Room office("Office", 16.0, 12.5, true, true, true);
//     Room atrium("Atrium", 160, 120.5, false, true, true);
//     building.addRoom(&office);
//     building.addRoom(&atrium);

//     Sweeper sweeperRobot("Sweeper", 100, Size::SMALL, &office);
//     Mopper mopperRobot("Mopper", 100, Size::LARGE, &atrium);

// Robot* findrobot(const std::string& name) {
//     if (name == "Sweeper") return &sweeperRobot;
//     if (name == "Mopper") return &mopperRobot;
//     return nullptr; // Return nullptr if robot not found
// }

// Room* findroom(const std::string& name) {
//     if (name == "Office") return &office;
//     if (name == "Atrium") return &atrium;
//     // Add more rooms here
//     return nullptr; 
// }

//     Robot* robot = findrobot(robotName); //map robotname to robot
//     Room* room = findroom(roomName); //same here

//     if (!robot || !room) {
//         std::cerr << "room name or robot name doesnt exist" << std::endl;
//         return 1;
//     }


//     // Perform the action  -- The dynamic type cast converts a pointer (or reference) to one class T1 into a pointer (reference) to another class T2
//     if (action == "sweep" && dynamic_cast<Sweeper*>(robot)) {
//         dynamic_cast<Sweeper*>(robot)->sweep();

//     } else if (action == "mop" && dynamic_cast<Mopper*>(robot)) {
//         dynamic_cast<Mopper*>(robot)->mop();

//     } else if (action == "scrub" && dynamic_cast<Scrubber*>(robot)) {
//         dynamic_cast<Scrubber*>(robot)->scrub();
        
//     } else {
//         std::cerr << "invalid action or robot type" << std::endl;
//         return 1;
//     }

//     std::cout << "Done" << std::endl;

//     return 0;
}
