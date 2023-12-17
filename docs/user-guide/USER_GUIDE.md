# User Guide

To go back to README.md, click [here](../README.md)

Before using our management system, you will first need to configure an input file, and place it in the app folder.  There is a sample input file and template already provided in the folder, so just ensure it follows that format.  To see more details on how to configure the input file, click [here](../../app/APP.md).

You can now run the program.  Use cmake to build and execute the main file found in the app folder.  If you have cmake on vscode installed, this should be as simple as clicking the play button in the lower blue ribbon.

This management system simulates the act of commanding a fleet of robots to clean rooms within a building.  You will first notice when running the program that the current time is displayed.  This application uses simulated time, with each time unit being equal to roughly 5 minutes of time in the real world.  If you want to get started quickly, type "help" in the terminal window to see a list of commands you can perform, although more detailed descriptions of what the application is doing can be found below.

The "assign" command takes in two arguments: the name of a robot and the name of a room.  This command will attempt to send the robot specified to clean the room specified.  However, the robot will not be able to be sent if it is not of the job that is required to clean that room (i.e. a mopper robot will not go to a room that is not moppable).  In addition, this command will check to make sure the robot has enough battery left to clean the room specified by itself.  If the robot does not have enough battery, it will prompt the user to ensure that they are certain the robot should be sent (this is useful in the case that the user wants multiple robots to clean a room that none of them can clean by themselves).  After a robot is assigned to a room, it will clean the room until it fails (10% chance), runs out of battery, or finishes cleaning the room, in which case it will return to base, where it will charge (5% every time unit incremented).

The "display" command only takes in the following arguments: "dirty rooms", "clean rooms", "all rooms", "busy robots", "available robots", and "all robots".  As you may notice, it is used to view groups of rooms/robots.  "dirty rooms" will display rooms that are not 100% clean in all aspects that they can be, "clean rooms" will display rooms that are 100% clean, and "all rooms" will display all rooms in the building.  "busy robots" will display all robots that are not currently at base, "available robots" will display all robots at base, and "all robots" will display all robots in your fleet.

The "view" command takes in one argument, either a room name or a robot name.  It will allow the user to view the specifics of a room (its length, width, percentSweeped, percentMopped, etc.) or a robot (its ID, battery level, job, etc.)

The "call technician" command takes in one additional argument: a robot name. The technician will attempt to take the robot back to base and fix it, but only if the robot has actually failed on the job or has run out of battery.  Every unit of time incremented, the technician will fix one robot that is in its queue of robots to be fixed.

The "time" command takes in either one argument of a positive integer, or by writing "time until" instead, will take in one argument of a robot name.  Using an integer, time will advance forward however many units of the integer specified.  By using "time until" with a robot name, the application will advance units of time until that robot finishes cleaning the room it is in, or until the robot fails or runs out of battery while cleaning.

The "dirty" command takes in one argument of a room name.  It will randomly dirty the room specfied by setting its percent cleaned values to values between 0 and 100 (note if a room is already very dirty, this command might actually clean the room by randomly getting values higher than the ones already in the room).

The "exit" command will exit the program.

After the program is done running, you may want to look at the logfile generated in app to see where things may have gone wrong, or just to see more of the inner workings of the program.

Thank you for using the Catch Up Robot Management System!

