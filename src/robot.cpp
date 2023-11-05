#include <math.h>

#include "libclean/robot.hpp"

Robot::Robot(strin name, float battery, Size size, string location){
       Name = name 
       battery = battery
       size = size
       location = location
};

void Robot::move(){
    
};

bool Robot::ifBusy(){


};
        
float Robot::getBattery(){
   return battery;
};
       
       
Size Robot::getSize(){
   return size;
};

void Robot::charge(){

};
       
void Robot::setName(string newname){
    name = newname;
};

bool Robot::hasFailed(){

};
  
bool Robot::isRoomClean(){
    
};