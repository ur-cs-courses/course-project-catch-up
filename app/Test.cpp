#include <libclean/manager.hpp>
#include <libclean/room.hpp>
#include "libclean/robot.hpp"

int main() {

    // Create a new manager:
    Manager manager;

//    Testing Room Constructor: 
    // Create a new Room called the office
    Room office {"Office", 16.0, 12.5, true, true, true};
    // Create a new Room called the atrium
    Room atrium {"Atrium", 160, 120.5, false, true, true};
    // Create a new Room called the csMajorLab
    Room csMajorLab {"CSMajorLab", 20, 10, true, false, false};

    // Test: getSize
    // returns the size of the room which is the length * width
    std::cout << "The size of the office is: " << office.getSize() << std::endl;

    // Test: setPercentSwept
    // sets the percent swept of the room 
    std::cout << office.getPercentSwept() << "% of the office has been swept." << std::endl;
    office.setPercentSwept(20); // -- 20 % of the office has been swept
    std::cout << office.getPercentSwept() << "% of the office has been swept." << std::endl;

    // Test: setPercentMopped
    // sets the percent mopped of the room 
    std::cout << office.getPercentMopped() << "% of the office has been mopped." << std::endl;
    office.setPercentMopped(15); // -- 15 % of the office has been mopped
    std::cout << office.getPercentMopped() << "% of the office has been swept." << std::endl;

    // Test: setPercentScrubbed
    // sets the percent scrubbed of the room
    std::cout << office.getPercentScrubbed() << "% of the office has been srubbed." << std::endl;
    office.setPercentScrubbed(100); // -- 100 % of the office has been scrubbed
    std::cout << office.getPercentScrubbed() << "% of the office has been scrubbed." << std::endl;

    // Test: randomlyDirty
    //Check to make sure randomlyDirty changed the percentage:
    office.randomlyDirty();
    std::cout << "After one cycle of randomlyDirty:" << std::endl;
    std::cout << office.getPercentSwept() << "% of the office has been swept." << std::endl;
    std::cout << office.getPercentMopped() << "% of the office has been mopped." << std::endl;
    std::cout << office.getPercentScrubbed() << "% of the office has been srubbed." << std::endl;

    std::cout << "After another cycle of randomlyDirty:" << std::endl;
    office.randomlyDirty();
    std::cout << office.getPercentScrubbed() << "% of the office has been scrubbed." << std::endl;

//  Testing Robot Constructor: Scrubber
    // Creating a Scrubber robot called Robot1.
    Scrubber Robot1 {"Robot1", 100, Size::SMALL, office, false};
    manager.viewRobotStatus(Robot1);

//  Testing Robot Constructor: Sweeper
    // Creating a Sweeper robot called Robot2.
    Sweeper Robot2 {"Robot2", 100, Size::LARGE, csMajorLab, false};
    manager.viewRobotStatus(Robot2);

    // Making the robot sweep the room it is assigned to/in.
    std::cout << office.getPercentSwept() << "% of the csMajorLab has been swept." << std::endl;
    Robot2.sweep(); // -- Robot2 sweeps the csMajorLab
    std::cout << "After Robot2 swept: " << office.getPercentSwept() << "% of the csMajorLab has been swept." << std::endl;

//  Testing Robot Constructor: Mopper
    // Creating a Mopper robot called Robot3
    Mopper Robot3 {"Robot3", 100, Size::LARGE, atrium, false};
    manager.viewRobotStatus(Robot3);

    // Making the robot mop the room it is assigned to/in.
    std::cout << atrium.getPercentMopped() << "% of the atrium has been mopped." << std::endl;
    Robot3.mop(); // -- Robot3 mops the atrium
    std::cout << "After Robot3 mopped: " << office.getPercentMopped() << "% of the atrium has been mopped." << std::endl;

    // Test : move
    // Moves the robot to the specified room
    Robot1.move(atrium); // -- moves Robot1 to the atrium from the office
    std::cout << "New location of Robot1: " << Robot1.getLocation().getName() << std::endl;

    // Making the robot scrub the room it is assigned to/in.
    std::cout << office.getPercentScrubbed() << "% of the office has been scrubbed." << std::endl;
    Robot1.scrub(); // -- Robot1 scrubs the office
    std::cout << "After Robot1 scrubs: " << office.getPercentScrubbed()  << "% of the office has been mopped." << std::endl;

    // Test : charge
    std::cout << "Before Charging: " << Robot1.getBattery() << std::endl;
    Robot1.charge(); // -- Robot1 battery will go up to 100%
    std::cout << "After Charging: " << Robot1.getBattery() << std::endl;

    // Test : setName
    // Changes the name of the robot
    Robot2.setName("Martin"); // -- Robot2 name is now Martin
    std::cout << "Robot2 new name: " << Robot2.getName() << std::endl;

    // Test : hasFailed
    // Should always return false - not implemented yet
    std::cout << "Robot2 fail status: " << Robot2.hasFailed() << std::endl;

    // Test : isRoomClean
    // Returns true if the room is clean according to that robots type
    std::cout << "The csMajorLab status: " << Robot2.isRoomClean() << std::endl;
    std::cout << "The csMajorLab percent swept: " << csMajorLab.getPercentSwept() << std::endl;
    csMajorLab.randomlyDirty();
    std::cout << "After a cycle of randomlyDirty: " << std::endl;
    std::cout << "The csMajorLab percent swept: " << csMajorLab.getPercentSwept() << std::endl;
    std::cout << "The csMajorLab status: " << Robot2.isRoomClean() << std::endl;

//   Testing Manager:

    // Test: viewRobotStatus
    manager.viewRobotStatus(Robot1);

    // Test: viewLocation
    // Prints the name of the room, what can be done to it, and the room status
    manager.viewLocation(office);

    // Test: assignRobot
    // Assigns a robot to a specific room
    manager.assignRobot(Robot1, office); // -- Manager is assigning Robot1 to the office from the atrium

    // Making sure assignRobot changed location of Robot1:
    manager.viewRobotStatus(Robot1);
};

