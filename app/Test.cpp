#include <libclean/manager.hpp>
#include <libclean/room.hpp>
#include "libclean/robot.hpp"

int main() {

    // Create a new manager:
    Manager manager;

//    Testing Room Constructor: 
    // Create a new Room called the Office
    Room Office("Office", 16.0, 12.5, true, true, true);
    // Create a new Room called the Atrium
    Room Atrium("Atrium", 160, 120.5, false, true, true);
    // Create a new Room called the CSMajorLab
    Room CSMajorLab("CSMajorLab", 20, 10, true, false, false);

    // Test: getSize
    // returns the size of the room which is the length * width
    std::cout << "The size of the office is: " << Office.getSize() << std::endl;

    // Test: setPercentSwept
    // sets the percent swept of the room 
    std::cout << Office.percentSwept << "% of the office has been swept." << std::endl;
    Office.setPercentSwept(20); // -- 20 % of the office has been swept
    std::cout << Office.percentSwept << "% of the office has been swept." << std::endl;

    // Test: setPercentMopped
    // sets the percent mopped of the room 
    std::cout << Office.percentMopped << "% of the office has been mopped." << std::endl;
    Office.setPercentMopped(15); // -- 15 % of the office has been mopped
    std::cout << Office.percentMopped << "% of the office has been swept." << std::endl;

    // Test: setPercentScrubbed
    // sets the percent scrubbed of the room
    std::cout << Office.percentScrubbed << "% of the office has been srubbed." << std::endl;
    Office.setPercentScrubbed(100); // -- 100 % of the office has been scrubbed
    std::cout << Office.percentScrubbed << "% of the office has been scrubbed." << std::endl;

    // Test: randomlyDirty
    //Check to make sure randomlyDirty changed the percentage:
    Office.randomlyDirty();
    std::cout << "After one cycle of randomlyDirty:" << std::endl;
    std::cout << Office.percentSwept << "% of the office has been swept." << std::endl;
    std::cout << Office.percentMopped << "% of the office has been mopped." << std::endl;
    std::cout << Office.percentScrubbed << "% of the office has been srubbed." << std::endl;

    std::cout << "After another cycle of randomlyDirty:" << std::endl;
    Office.randomlyDirty();
    std::cout << Office.percentScrubbed << "% of the office has been scrubbed." << std::endl;

//  Testing Robot Constructor: Scrubber
    // Creating a Scrubber robot called Robot1.
    Scrubber Robot1("Robot1", 100, Size::SMALL, Office, false);
    manager.viewRobotStatus(Robot1);

//  Testing Robot Constructor: Sweeper
    // Creating a Sweeper robot called Robot2.
    Sweeper Robot2("Robot2", 100, Size::LARGE, CSMajorLab, false);
    manager.viewRobotStatus(Robot2);

    // Making the robot sweep the room it is assigned to/in.
    std::cout << Office.percentSwept << "% of the CSMajorLab has been swept." << std::endl;
    Robot2.sweep(); // -- Robot2 sweeps the CSMajorLab
    std::cout << "After Robot2 swept: " << Office.percentSwept << "% of the CSMajorLab has been swept." << std::endl;

//  Testing Robot Constructor: Mopper
    // Creating a Mopper robot called Robot3
    Mopper Robot3("Robot3", 100, Size::LARGE, Atrium, false);
    manager.viewRobotStatus(Robot3);

    // Making the robot mop the room it is assigned to/in.
    std::cout << Atrium.percentMopped << "% of the Atrium has been mopped." << std::endl;
    Robot3.mop(); // -- Robot3 mops the Atrium
    std::cout << "After Robot3 mopped: " << Office.percentMopped << "% of the Atrium has been mopped." << std::endl;

    // Test : move
    // Moves the robot to the specified room
    Robot1.move(Atrium); // -- moves Robot1 to the Atrium from the Office
    std::cout << "New location of Robot1: " << Robot1.location.name << std::endl;

    // Making the robot scrub the room it is assigned to/in.
    std::cout << Office.percentScrubbed << "% of the Office has been scrubbed." << std::endl;
    Robot1.scrub(); // -- Robot1 scrubs the Office
    std::cout << "After Robot1 scrubs: " << Office.percentScrubbed  << "% of the Office has been mopped." << std::endl;

    // Test : charge
    std::cout << "Before Charging: " << Robot1.battery << std::endl;
    Robot1.charge(); // -- Robot1 battery will go up to 100%
    std::cout << "After Charging: " << Robot1.battery << std::endl;

    // Test : setName
    // Changes the name of the robot
    Robot2.setName("Martin"); // -- Robot2 name is now Martin
    std::cout << "Robot2 new name: " << Robot2.name << std::endl;

    // Test : hasFailed
    // Should always return false - not implemented yet
    std::cout << "Robot2 fail status: " << Robot2.hasFailed() << std::endl;

    // Test : isRoomClean
    // Returns true if the room is clean according to that robots type
    std::cout << "The CSMajorLab status: " << Robot2.isRoomClean() << std::endl;
    std::cout << "The CSMajorLab percentSwept: " << CSMajorLab.percentSwept << std::endl;
    CSMajorLab.randomlyDirty();
    std::cout << "After a cycle of randomlyDirty: " << std::endl;
    std::cout << "The CSMajorLab percentSwept: " << CSMajorLab.percentSwept << std::endl;
    std::cout << "The CSMajorLab status: " << Robot2.isRoomClean() << std::endl;

//   Testing Manager:

    // Test: viewRobotStatus
    manager.viewRobotStatus(Robot1);

    // Test: viewLocation
    // Prints the name of the room, what can be done to it, and the room status
    manager.viewLocation(Office);

    // Test: assignRobot
    // Assigns a robot to a specific room
    manager.assignRobot(Robot1, Office); // -- Manager is assigning Robot1 to the Office from the Atrium

    // Making sure assignRobot changed location of Robot1:
    manager.viewRobotStatus(Robot1);
};

