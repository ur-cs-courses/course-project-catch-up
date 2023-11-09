#include <libclean/manager.hpp>
#include <libclean/room.hpp>


int main() {
    // Testing Room: 
    Room Office("Office", 16.0, 12.5, true, true, true);

    // Test: getSize
    std::cout << Office.getSize() << std::endl;

    // Test: setPercentSwept
    std::cout << Office.percentSwept << std::endl;
    Office.setPercentSwept(20);
    std::cout << Office.percentSwept << std::endl;

    // Test: setPercentMopped
    std::cout << Office.percentMopped << std::endl;
    Office.setPercentMopped(15);
    std::cout << Office.percentMopped << std::endl;

    // Test: setPercentScrubbed
    std::cout << Office.percentScrubbed << std::endl;
    Office.setPercentScrubbed(100);
    std::cout << Office.percentScrubbed << std::endl;

    // Test: randomlyDirty
    //Check to make sure randomlyDirty changed the percentage:
    Office.randomlyDirty();
    std::cout << Office.percentSwept << std::endl;
    std::cout << Office.percentMopped << std::endl;
    std::cout << Office.percentScrubbed << std::endl;

    Office.randomlyDirty();
    std::cout << Office.percentScrubbed << std::endl;

    // Testing Manager:

    // // Test: viewRobotStatus
    // viewRobotStatus(Robot1);

    // // Test: viewLocation
    // viewLocation(Office);

    // // Test: assignRobot
    // assignRobot(Robot1, Office);

    // // Making sure assignRobot changed location of Robot1:
    // viewRobotStatus(Robot1);
};

