#pragma once

#include <map>
#include <string>

class Location; // Forward declaration

// Definicja ogólnej mapy świata
typedef std::map<std::string, Location*> GameWorld;

// Alias dla przejść wewnątrz tej samej głównej lokacji
typedef std::map<std::string, Location*> LocalExits;

// Alias dla podlokacji (np. pokoje w zamku)
typedef std::map<std::string, Location*> SubLocations;

// Alias dla przejść do innych regionów
typedef std::map<std::string, Location*> GlobalExits;

typedef std::map<Location*, std::string> DescriptionsMap;

