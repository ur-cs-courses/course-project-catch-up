#include <string> 
#include <math.h> 
#include "libclean/robot.hpp"

using namespace std; 


    class Size {
private:
    float width;
    float height;
    float depth;

public:
    // Default constructor
    Size() : width(0.0f), height(0.0f), depth(0.0f) {}

    // Parameterized constructor
    Size(float w, float h, float d) : width(w), height(h), depth(d) {}

    // Copy constructor
    Size(const Size& other) : width(other.width), height(other.height), depth(other.depth) {}

    // Assignment operator
    Size& operator=(const Size& other) {
        if (this != &other) {
            width = other.width;
            height = other.height;
            depth = other.depth;
        }
        return *this;
    }

    // Accessors and mutators for width, height, and depth
    float getWidth() const { return width; }
    void setWidth(float w) { width = w; }

    float getHeight() const { return height; }
    void setHeight(float h) { height = h; }

    float getDepth() const { return depth; }
    void setDepth(float d) { depth = d; }

    // A member function to calculate the volume, if it's a 3D size
    float volume() const {
        return width * height * depth;
    }

    // Destructor is not needed here since we are not dynamically allocating resources
    // However, if you ever expand this class to manage resources, remember to implement it
};



class Robot {
    string Name; // Member variable names should start with lowercase or have underscores to differentiate from parameter names
    float battery;
    Size size;
    string location;
    bool busy; // Assuming we have a member to track if the robot is busy

public:
    Robot(string name, float battery, Size size, string location)
        : Name(name), 
        battery(battery), 
        size(size), 
        location(location), 
        busy(false) {} // Proper initialization list

    void move() {
        // Implement movement logic here
        // For now, let's just set busy to true
        busy = true;
        // Add logic to change location, consume battery, etc.
    }

    bool ifBusy() {
        // Return the current state of the busy flag
        return busy;
    }

    float getBattery() {
        return battery;
    }

    Size getSize() {
        return size;
    }

    void charge() {
      if (battery > 0 && battery < 100) {
      // This block will execute because number is greater than 0
      battery = 100;
      } 
      else{
         
      }
        
        
    }

    void setName(string newname) {
        Name = newname;
    }

    bool hasFailed() {
        // Implement failure detection logic
        // Return true if the robot has encountered a failure condition
        return false; // Placeholder
    }

    bool isRoomClean() {
        // Implement room cleanliness check
        // Return true if the room is clean
        return true; // Placeholder
    }
};
