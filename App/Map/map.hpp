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

    Location(Locations_e id, std::string n, std::string label, GameWorld& world);

    std::string getDescription();
    void addExit(Location* target);
    void addGlobalExit(Location* target);
    void connect(Location* locationB);
};
    
void createWorld(GameWorld& world, Location*& startingLocation);
void displayLocation(Location* current);