#include <string> 
#include <math.h> 
#include "libclean/robot.hpp"
#include <fmt/core.h>
#include <iostream>

using namespace std; 




class Robot {
    string Name; // Member variable names should start with lowercase or have underscores to differentiate from parameter names
    float battery;
    Size size;
    Point location;
    bool busy; // Assuming we have a member to track if the robot is busy

public:
    Robot(string name, float battery, Size size, string location)
        : Name(name), 
        battery(battery), 
        size(size), 
        location(location), 
        busy(false) {} 

      void move(int newX, int newY) {
      if (battery <= 0) {
         cout << "Battery is too low. Unable to move." << endl;
         return;
      }

      if (busy) {
         cout << "Robot is busy and cannot move right now." << endl;
         return;
      }

      // Update the location with the new coordinates
      location.set(newX, newY);
      busy = true;
      cout << Name << " is moving to ";
      location.display(); // Display the new location coordinates

      // Simulate the robot being busy for a while after moving
      busy = false;


      // Reduce battery by some amount to simulate energy consumption
      battery -= 10;
      if (battery < 0) {
         battery = 0;
      }
   }




    bool ifBusy() {
        // Return the current state of the busy flag
        return busy;
    }

    float getBattery() {
        return battery;
    }

     string getSizeLabel() const {
        return size.getSize();
    }
   

    void charge(Robot& R ) {

      if (battery > 0 && battery < 100) {
      battery = 100;

      } 

      else{
       std::cout << "The battery is full no need to charge" << std::endl;

      }
        
        
    }

   void setName(string newname) {
        Name = newname;
    }

    bool hasFailed() {
        // Implement failure detection logic -- we didnt talj about it yet so we need to do so soon
        // Return true if the robot has encountered a failure condition
        return false; 
    }

    bool isRoomClean() {
   //also im not sure of the room class how we are implementing the clenlinesss of the room 
   //nut the way to do it here is that we need to call the clean part in room class and return it here. 
      cout<< "Room is clean- Robot done cleaning "<<endl;
        
        return true;
    }
};

















//for location in room (x, y) coordinates 
struct Point {
    int x;
    int y;
//constructor 
    Point(int x_0 = 0, int y_0 = 0) : 
    x(x_0), 
    y(y_0) 
    {}

    // Method to set the coordinates
    void set(int X_n, int Y_n) {
        x = X_n;
        y = Y_n;
    }

    // display coordinates
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};








 class Size {
private:
    string size;  // This will hold either "small", "medium", or "large"

public:
    // Default constructor
    Size() : size("medium") {}  // Default to "medium" size, for example

    // Parameterized constructor
    Size(const string& s) {
        if (s == "small" || s == "medium" || s == "large") {
            size = s;
        } else {
            size = "medium";  // Default to "medium" if an invalid size is given
        }
    }

    // Copy constructor
    Size(const Size& other) : size(other.size) {}

    // Assignment operator
    Size& operator=(const Size& other) {
        if (this != &other) {
            size = other.size;
        }
        return *this;
    }

    // Accessor for size
    string getSize() const { return size; }

    // Mutator for size
    void setSize(const string& s) {
        if (s == "small" || s == "medium" || s == "large") {
            size = s;
        }
        // Optionally handle the case where s is not a valid size
    }

    // You may also want to add more functionality to this class depending on your needs
    // For example, methods to compare sizes, to convert size to dimensions if applicable, etc.

    // Destructor is not needed here since we are not dynamically allocating resources
};











