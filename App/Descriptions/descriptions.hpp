#ifndef DESCRIPTIONS_HPP
#define DESCRIPTIONS_HPP

#include <string>
#include "../types.hpp"

class Descriptions {
public:
    static DescriptionsMap descriptions;  // Mapa wskaźników na opisy

    static void initialize(GameWorld& world);  // Inicjalizacja opisów
    static std::string getDescription(Location* location); // Pobranie opisu danej lokacji
};

#endif