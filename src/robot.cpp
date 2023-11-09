#include <string> 
#include <math.h> 
#include "libclean/robot.hpp"
#include <fmt/core.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std; 


//should we use a timer? 
//if the time exisst then we add conditions related to that 

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

         //assign a new condition for the battary, so that the function would check if the battary is enough for a movemrnt 
         //so if the battary is lower then like 20% then go to charge (call the charge function ) 
         //if the batttry is greater then that then uou can move and decrement the charhe of the batttatry 

         //add a decrement function for the battary here (maybe not necessry a function but a variable ot just call (battary--))
      if (battery <= 0) {
         cout << "battary is low, need to charge" << endl;
         return;
      }

      if (busy) {
         cout << "Robot is busy and cannot move right now." << endl;
         return;
      }

      std::this_thread::sleep_for(std::chrono::minutes(0.5)); //robot takes half a min to move 

      // Update the location with the new coordinates
      location.set(newX, newY);
      //since robot is mobing to new location its busy 
      busy = true;
      // Display the new location coordinate
      cout << Name <<" with battery: "<< battery<<" is moving to: "<<location.display()<<endl;
       

      // Reduce battery by 5% to signal robot is moving and using its enery 
      battery -= 5;
      if (battery < 0) {
         battery = 0;
      }
      busy = false;

   }




    bool ifBusy() {
        // Return the current state of the busy flag
        return busy;
    }

    float getBattery() { //get battary charge 
        return battery;
    }

     string getSizeLabel() const { //get robot size 
        return size.getSize();
    }
   

void charge(Robot& R) {
  
    if (R.battery >= 0.0 && R.battery < 100.0) {
        // Loop until the battery is fully charged
        while (R.battery < 100.0) {
            // charge the battery  by 5%
            R.battery += 5.0;
            // if exceeded 100 stop at 100 
            if (R.battery > 100.0) {
                R.battery = 100.0;
            }
        std::cout << "Charging... Battery is at " << R.battery << "%" << std::endl;
        // Wait for 2 seconds before the next charge -> we use thread becaosue we want the program to keep going while battary of robot is charging 
        std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        std::cout << "The battery is 100%" << std::endl;
    } else {
        std::cout << "The battery is full no need to charge robot" << std::endl;
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

    bool isRoomClean() { //this function depends on the room class - currently without it i am unable to impelemnt this 
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

    
    Size(const string& s) {
        if (s == "small" || s == "medium" || s == "large") {
            size = s;
        } else {
            size = "medium";  // Default to "medium" if an invalid size is given
        }
    }

    // Copy constructor
    Size(const Size& other) : 
    size(other.size) {
        
    }

    // Assignment operator
    Size& operator=(const Size& other) {
        if (this != &other) {
            size = other.size;
        }
        return *this;
    }

 
    string getSize() const {
         return size;
     }

    // Mutator for size
    void setSize(const string& s) {
        if (s == "small" || s == "medium" || s == "large") {
            size = s;
        }
        // Optionally handle the case where s is not a valid size
    }

   
};











