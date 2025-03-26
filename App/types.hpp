#pragma once

#include <map>
#include <string>
#include <memory>

class Location;

typedef enum 
{
    KAER_MORHEN = 0,
    KAER_MORHEN_COURTYARD_LOWER,
    KAER_MORHEN_COURTYARD_MIDDLE,
    KAER_MORHEN_COURTYARD_UPPER,
    KAER_MORHEN_FORTRESS,
    KAER_MORHEN_LABORATORY,
    KAER_MORHEN_WHISPERING_STONE_CIRCLE,
    KAER_MORHEN_KITCHEN,
    KAER_MORHEN_GREAT_HALL,
    KAER_MORHEN_WEST_WING,
    KAER_MORHEN_LIBRARY,
    KAER_MORHEN_ARMORY,
    KAER_MORHEN_EVENING_ROOM,
    KAER_MORHEN_TRISS_ROOM,

    NUMBER_OF_LOCATIONS,
} Locations_e;

typedef std::map<std::string, std::shared_ptr<Location>> GameWorld;

typedef std::map<std::string, std::weak_ptr<Location>> LocalExits;

typedef std::map<std::string, std::weak_ptr<Location>> GlobalExits;

typedef std::map<Locations_e, std::string> DescriptionsMap;