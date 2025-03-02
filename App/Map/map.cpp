#include "../Map/map.hpp"

void createWorld(GameWorld& world, Location*& startingLocation) {
    Location* KaerMorhen = new Location("KaerMorhen");
        Location* KaerMorhen_Courtyard_Lower = new Location("KaerMorhen_Courtyard_Lower");
        Location* KaerMorhen_Courtyard_Middle = new Location("KaerMorhen_Courtyard_Middle");
        Location* KaerMorhen_Courtyard_Upper = new Location("KaerMorhen_Courtyard_Upper");

    KaerMorhen->addChildLocation(KaerMorhen_Courtyard_Lower);
    KaerMorhen->addChildLocation(KaerMorhen_Courtyard_Middle);
    KaerMorhen->addChildLocation(KaerMorhen_Courtyard_Upper);

    KaerMorhen_Courtyard_Lower->addExit("middle", KaerMorhen_Courtyard_Middle);
    KaerMorhen_Courtyard_Middle->addExit("lower", KaerMorhen_Courtyard_Lower);
    KaerMorhen_Courtyard_Middle->addExit("upper", KaerMorhen_Courtyard_Upper);
    KaerMorhen_Courtyard_Upper->addExit("middle", KaerMorhen_Courtyard_Middle);

    // Dodanie lokacji do mapy świata
    world["KaerMorhen"] = KaerMorhen;
    world["KaerMorhen_Courtyard_Lower"] = KaerMorhen_Courtyard_Lower;
    world["KaerMorhen_Courtyard_Middle"] = KaerMorhen_Courtyard_Middle;
    world["KaerMorhen_Courtyard_Upper"] = KaerMorhen_Courtyard_Upper;

    // Zwracamy wskaźnik do lokacji startowej
    startingLocation = KaerMorhen_Courtyard_Lower;
}

void displayLocation(Location* current) {
    std::cout << "\nYou are in: " << current->name << "\n";  // Nazwa lokacji
    std::cout << "\n" << current->getDescription() << "\n";

    // Wyświetlanie możliwych przejść w ramach tej samej lokacji
    if (!current->exits.empty()) {
        std::cout << "\nYou can move within this area:\n";
        for (const auto& [dir, loc] : current->exits) {
            std::cout << "  - " << dir << " -> " << loc->name << "\n";
        }
    }

    // Wyświetlanie pod-lokacji
    if (!current->childLocations.empty()) {
        std::cout << "\nThis place contains:\n";
        for (const auto& [name, loc] : current->childLocations) {
            std::cout << "  - " << name << "\n";
        }
    }

    // Wyświetlanie przejść do innych regionów
    if (!current->globalExits.empty()) {
        std::cout << "\nYou can travel to other locations:\n";
        for (const auto& [dir, loc] : current->globalExits) {
            std::cout << "  - " << dir << " -> " << loc->name << " (different region)\n";
        }
    }
}