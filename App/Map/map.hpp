#pragma once

#include <iostream>
#include <map>
#include <string>
#include <memory>

#include "../types.hpp"
#include "../Descriptions/descriptions.hpp"

class Location : public std::enable_shared_from_this<Location>{
public:
    std::string name;
    std::string label;
    Locations_e id;
    LocalExits exits;
    GlobalExits globalExits;

    Location(Locations_e id, std::string n, std::string label);

    std::string getDescription();
    void addExit(std::shared_ptr<Location> target);
    void addGlobalExit(std::shared_ptr<Location> target);
    void connect(std::shared_ptr<Location>locationB);
    void registerInWorld(GameWorld& world);
    std::shared_ptr<Location> makeLocation(Locations_e id, const std::string& name, const std::string& label, GameWorld& world); 
};
    
void createWorld(GameWorld& world, std::shared_ptr<Location>& startingLocation);
void displayLocation(std::shared_ptr<Location> current);