#pragma once

#include <iostream>
#include <map>
#include <string>

#include "../types.hpp"
#include "../Descriptions/descriptions.hpp"

class Location {
public:
    std::string name;
    std::string label;
    Locations_e id;
    LocalExits exits;
    GlobalExits globalExits;

    Location(Locations_e id, std::string n, std::string label, GameWorld& world) {
        this->id = id;
        this->name = n;
        this->label = label;
        world[n] = this;
    }

    std::string getDescription() {
        return Descriptions::getDescription(this->id);
    }

    void addExit(Location* target) {
        exits[target->label] = target;
    }

    void addGlobalExit(Location* target) {
        globalExits[target->label] = target;
    }

    void connect(Location* locationB) {
        this->addExit(locationB);
        locationB->addExit(this);
    }
};
    
void createWorld(GameWorld& world, Location*& startingLocation);
void displayLocation(Location* current);