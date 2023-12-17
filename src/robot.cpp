#include <string> 
#include <math.h> 
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <iostream>
#include <random>

#include "libclean/robot.hpp"
#include "libclean/room.hpp"
#include "libclean/timer.hpp"

int Robot::numberOfRobots = 0;
int currentTimeRobot = Timer::getTime();

Robot::Robot(std::string name, float battery_, Size size, Room *location, const std::string& filename, Job job) 
    :   name(name), id(numberOfRobots), battery_(battery_), size(size), location(location), busy(false), failed(false), job(job)
    {
    currentTimeRobot = Timer::getTime();
    numberOfRobots++;
    this->filename = filename;
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot" << name << "object created at " << currentTimeRobot << std::endl; 
};

bool Robot::operator==(const Robot& robot){
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Checking if robots are the same at time " << currentTimeRobot << std::endl;
    if (id == robot.id) {
        return true;
    } else {
        return false;
    }
};

std::string Robot::getName() {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getName() function was called at time " << currentTimeRobot << "for robot " << name << std::endl;
    return name;
};

int Robot::getID(){
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getID() function was called at time "  << currentTimeRobot << "for robot " << name << std::endl;
    return id;
};

float Robot::getBattery() {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getBattery() function was called at time "  << currentTimeRobot << "for robot " << name << std::endl;
    return battery_;
};

Size Robot::getSize() {
    currentTimeRobot = Timer::getTime();
   std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getSize() function was called at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    return size;
};

Room* Robot::getLocation() {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getLocation() function was called at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    return location;
};

bool Robot::getBusy() {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getBusy() function was called at time "  << currentTimeRobot << "for robot " << name << std::endl;
    return busy;
};

bool Robot::getFailed() {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getFailed() function was called at time "  << currentTimeRobot << "for robot " << name  << std::endl;
    return failed;
};

Job Robot::getJob() {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot getJob() function was called at time "  << currentTimeRobot << "for robot " << name << std::endl;
    return job;
};

void Robot::move(Room *room) {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot move() function was called at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    if (battery_ <= 5) {
        std::cout << "Battery is low, need to charge." << std::endl;
        return;
    }
    this->location = room;
    std::cout << name << " with battery: " << battery_ << " is moving to: " << location->getName() << std::endl;
    this->battery_ -= 5;
    if (battery_ < 0) {
        this->battery_ = 0;
    }
};

void Robot::charge() {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot charge() function was at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    if (battery_ >= 0.0 && battery_ < 100.0) {
        float newBattery_ = this->getBattery() + 5;
        if (newBattery_ < 100) {
            this->setBattery(newBattery_);
        } else {
            this->setBattery(100);
        }
    }
};

void Robot::setLocation(Room* room) {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot setLocation() function was called at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    this->location = room;
};

void Robot::setName(std::string newname) {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot setName() function was called at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    this->name = newname;
};

void Robot::setBattery(float percent){
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot setBattery() function was called at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    if(percent <= 100 && percent >= 0){
        this->battery_ = percent;
    } else if(percent > 100) {
        this->battery_ = 100;
    } else if(percent < 0) {
        this->battery_ = 0;
    }
};

bool Robot::hasFailed() {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot hasFailed() function was called at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    return battery_ == 0 || this->getFailed();
};

void Robot::setBusy(bool status) {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot setBusy() function was called at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    this->busy = status;
};

void Robot::setFailed(bool status) {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open(filename, std::ofstream::app);
    file << "Robot setFailed() function was called at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    this->failed = status;
};

bool Robot::isRoomClean() {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open("logfile.csv", std::ofstream::app);
    file << "Robot isRoomClean() function was called at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    if (this->getJob() == Job::SCRUBBER) {
        if ((this->getLocation())->getScrubbable()) {
            if (this->getLocation()->getPercentScrubbed() == 100) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else if(this->getJob() == Job::MOPPER) {
        if (this->getLocation()->getMoppable()) {
            if (this->getLocation()->getPercentMopped() == 100) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else if(this->getJob() == Job::VACUUMER) {
        if (this->getLocation()->getVacuumable()) {
            if (this->getLocation()->getPercentVacuumed() == 100) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        if (this->getLocation()->getSweepable()) {
            if (this->getLocation()->getPercentSwept() == 100) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
};

void Robot::clean() {
    currentTimeRobot = Timer::getTime();
    std::ofstream file;
    file.open("logfile.csv", std::ofstream::app);
    file << "Robot clean() function was called at time "  << currentTimeRobot  << "for robot " << name << std::endl;
    double chanceFailed = ((double)std::rand()) / RAND_MAX;
    if (chanceFailed < 0.10) {
        this->setFailed(true);
        std::cout << this->getName() << " has failed." << std::endl;
    }
    if (!this->hasFailed()) {
        if (this->getJob() == Job::SWEEPER) {
            if (this->getLocation()->getSweepable()) {
                if (this->getSize() == Size::SMALL) {
                    float percentOfRoomCleaned_ = ((5 / (this->getLocation())->getSize()) * 100) + (this->getLocation())->getPercentSwept();
                    if (percentOfRoomCleaned_ < 100) {
                        (this->getLocation())->setPercentSwept(percentOfRoomCleaned_);
                    } else {
                        this->getLocation()->setPercentSwept(100);
                    }
                    this->setBattery(this->getBattery() - 1);
                } else if (this->getSize() == Size::LARGE) {
                    float percentOfRoomCleaned_ = ((12 / (this->getLocation())->getSize()) * 100) + (this->getLocation())->getPercentSwept();
                    if (percentOfRoomCleaned_ < 100) {
                        (this->getLocation())->setPercentSwept(percentOfRoomCleaned_);
                    } else {
                        this->getLocation()->setPercentSwept(100);
                    }
                    this->setBattery(this->getBattery() - 1);
                }
            }
        } 
        else if (this->getJob() == Job::MOPPER) {
            if (this->getLocation()->getMoppable()) {
                if (this->getSize() == Size::SMALL) {
                    float percentOfRoomCleaned_ = ((5 / (this->getLocation())->getSize()) * 100) + (this->getLocation())->getPercentMopped();
                    if (percentOfRoomCleaned_ < 100) {
                        (this->getLocation())->setPercentMopped(percentOfRoomCleaned_);
                    } else {
                        this->getLocation()->setPercentMopped(100);
                    }
                    this->setBattery(this->getBattery() - 1);
                } else if (this->getSize() == Size::LARGE) {
                    float percentOfRoomCleaned_ = ((12 / (this->getLocation())->getSize()) * 100) + (this->getLocation())->getPercentMopped();
                    if (percentOfRoomCleaned_ < 100) {
                        (this->getLocation())->setPercentMopped(percentOfRoomCleaned_);
                    } else {
                        this->getLocation()->setPercentMopped(100);
                    }
                    this->setBattery(this->getBattery() - 1);
                }
            }
        }
        else if (this->getJob() == Job::VACUUMER) {
            if (this->getLocation()->getVacuumable()) {
                if (this->getSize() == Size::SMALL) {
                    float percentOfRoomCleaned_ = ((5 / (this->getLocation())->getSize()) * 100) + (this->getLocation())->getPercentVacuumed();
                    if (percentOfRoomCleaned_ < 100) {
                        (this->getLocation())->setPercentVacuumed(percentOfRoomCleaned_);
                    } else {
                        this->getLocation()->setPercentVacuumed(100);
                    }
                    this->setBattery(this->getBattery() - 1);
                } else if (this->getSize() == Size::LARGE) {
                    float percentOfRoomCleaned_ = ((12 / (this->getLocation())->getSize()) * 100) + (this->getLocation())->getPercentVacuumed();
                    if (percentOfRoomCleaned_ < 100) {
                        (this->getLocation())->setPercentVacuumed(percentOfRoomCleaned_);
                    } else {
                        this->getLocation()->setPercentVacuumed(100);
                    }
                    this->setBattery(this->getBattery() - 1);
                }
            }
        }
         else {
            if (this->getLocation()->getScrubbable()) {
                if (this->getSize() == Size::SMALL) {
                    float percentOfRoomCleaned_ = ((5 / (this->getLocation())->getSize()) * 100) + (this->getLocation())->getPercentScrubbed();
                    if (percentOfRoomCleaned_ < 100) {
                        (this->getLocation())->setPercentScrubbed(percentOfRoomCleaned_);
                    } else {
                        this->getLocation()->setPercentScrubbed(100);
                    }
                    this->setBattery(this->getBattery() - 1);
                } else if (this->getSize() == Size::LARGE) {
                    float percentOfRoomCleaned_ = ((12 / (this->getLocation())->getSize()) * 100) + (this->getLocation())->getPercentScrubbed();
                    if (percentOfRoomCleaned_ < 100) {
                        (this->getLocation())->setPercentScrubbed(percentOfRoomCleaned_);
                    } else {
                        this->getLocation()->setPercentScrubbed(100);
                    }
                    this->setBattery(this->getBattery() - 1);
                }
            }
        }
    } else {
        std::cout << this->getName() << " tried to clean " << (this->getLocation())->getName() << " but it has failed." << std::endl;
    }
};