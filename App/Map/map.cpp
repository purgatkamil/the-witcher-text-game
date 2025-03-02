#include "../Map/map.hpp"

void createWorld(GameWorld& world, Location*& startingLocation) {
    Location* KaerMorhen = new Location(KAER_MORHEN, "KaerMorhen", world);
        Location* KaerMorhen_Courtyard_Lower = new Location(KAER_MORHEN_COURTYARD_LOWER, "Lower Courtyard", world);
        Location* KaerMorhen_Courtyard_Middle = new Location(KAER_MORHEN_COURTYARD_MIDDLE, "Middle Courtyard", world);
        Location* KaerMorhen_Courtyard_Upper = new Location(KAER_MORHEN_COURTYARD_UPPER, "Upper Courtyard", world);

        KaerMorhen->addChildLocation(KaerMorhen_Courtyard_Lower);
        KaerMorhen->addChildLocation(KaerMorhen_Courtyard_Middle);
        KaerMorhen->addChildLocation(KaerMorhen_Courtyard_Upper);

        KaerMorhen_Courtyard_Lower->addExit("middle", KaerMorhen_Courtyard_Middle);
        KaerMorhen_Courtyard_Middle->addExit("lower", KaerMorhen_Courtyard_Lower);
        KaerMorhen_Courtyard_Middle->addExit("upper", KaerMorhen_Courtyard_Upper);
        KaerMorhen_Courtyard_Upper->addExit("middle", KaerMorhen_Courtyard_Middle);

    startingLocation = KaerMorhen_Courtyard_Lower;
}

void displayLocation(Location* current) {
    std::cout << "\nYou are in: " << current->name << "\n";
    std::cout << "\n" << current->getDescription() << "\n";

    if (!current->exits.empty()) {
        std::cout << "\nYou can move within this area:\n";
        for (const auto& [dir, loc] : current->exits) {
            std::cout << "  - " << dir << " -> " << loc->name << "\n";
        }
    }

    if (!current->childLocations.empty()) {
        std::cout << "\nThis place contains:\n";
        for (const auto& [name, loc] : current->childLocations) {
            std::cout << "  - " << name << "\n";
        }
    }

    if (!current->globalExits.empty()) {
        std::cout << "\nYou can travel to other locations:\n";
        for (const auto& [dir, loc] : current->globalExits) {
            std::cout << "  - " << dir << " -> " << loc->name << " (different region)\n";
        }
    }
}