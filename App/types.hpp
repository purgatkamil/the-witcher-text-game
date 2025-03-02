#pragma once

#include <map>
#include <string>

class Location; // Forward declaration

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

// Definicja ogólnej mapy świata
typedef std::map<std::string, Location*> GameWorld;

// Alias dla przejść wewnątrz tej samej głównej lokacji
typedef std::map<std::string, Location*> LocalExits;

// Alias dla podlokacji (np. pokoje w zamku)
typedef std::map<std::string, Location*> SubLocations;

// Alias dla przejść do innych regionów
typedef std::map<std::string, Location*> GlobalExits;

typedef std::map<Locations_e, std::string> DescriptionsMap;