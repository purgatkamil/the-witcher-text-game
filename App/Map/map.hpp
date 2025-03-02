#pragma once

#include <iostream>
#include <map>
#include <string>

#include "../types.hpp"
#include "../Descriptions/descriptions.hpp"

class Location {
    public:
        std::string name;
        LocalExits exits;
        SubLocations childLocations;
        GlobalExits globalExits;
    
        Location(std::string n, GameWorld& world) : name(n) {
            world[n] = this; 
        }
    
        std::string getDescription() {
            return Descriptions::getDescription(this);
        }
    
        void addExit(std::string direction, Location* target) {
            exits[direction] = target;
        }
    
        void addChildLocation(Location* child) {
            childLocations[child->name] = child;
        }
    
        void addGlobalExit(std::string direction, Location* target) {
            globalExits[direction] = target;
        }
    };
    
void createWorld(GameWorld& world, Location*& startingLocation);
void displayLocation(Location* current);