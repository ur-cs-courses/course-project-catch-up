#include "libclean/manager.hpp"
#include "libclean/fleet.hpp"
#include "libclean/robot.hpp" 
#include "libclean/room.hpp"
#include "libclean/building.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "The command line should be in formate: " << argv[0] << " <robot> <action> <room>" << std::endl;
        return 1;
    }

    std::string robotName = argv[1];
    std::string action = argv[2];
    std::string roomName = argv[3];

    // make building and room and robot objects
    Building building;
    Room office("Office", 16.0, 12.5, true, true, true);
    Room atrium("Atrium", 160, 120.5, false, true, true);
    building.addRoom(&office);
    building.addRoom(&atrium);

    Sweeper sweeperRobot("Sweeper", 100, Size::SMALL, &office);
    Mopper mopperRobot("Mopper", 100, Size::LARGE, &atrium);

Robot* findrobot(const std::string& name) {
    if (name == "Sweeper") return &sweeperRobot;
    if (name == "Mopper") return &mopperRobot;
    return nullptr; // Return nullptr if robot not found
}

Room* findroom(const std::string& name) {
    if (name == "Office") return &office;
    if (name == "Atrium") return &atrium;
    // Add more rooms here
    return nullptr; 
}

    Robot* robot = findrobot(robotName); //map robotname to robot
    Room* room = findroom(roomName); //same here

    if (!robot || !room) {
        std::cerr << "room name or robot name doesnt exist" << std::endl;
        return 1;
    }


    // Perform the action  -- The dynamic type cast converts a pointer (or reference) to one class T1 into a pointer (reference) to another class T2
    if (action == "sweep" && dynamic_cast<Sweeper*>(robot)) {
        dynamic_cast<Sweeper*>(robot)->sweep();

    } else if (action == "mop" && dynamic_cast<Mopper*>(robot)) {
        dynamic_cast<Mopper*>(robot)->mop();

    } else if (action == "scrub" && dynamic_cast<Scrubber*>(robot)) {
        dynamic_cast<Scrubber*>(robot)->scrub();
        
    } else {
        std::cerr << "invalid action or robot type" << std::endl;
        return 1;
    }

    std::cout << "Done" << std::endl;

    return 0;
}
