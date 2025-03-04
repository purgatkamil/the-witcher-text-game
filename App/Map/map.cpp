#include "../Map/map.hpp"

void createWorld(GameWorld& world, Location*& startingLocation) {
    Location* KaerMorhen = new Location(KAER_MORHEN, "Kaer Morhen", "kaermorhen", world);
        Location* KaerMorhen_LowerCourtyard = new Location(KAER_MORHEN_COURTYARD_LOWER, "Lower Courtyard", "lower", world);
            Location* KaerMorhen_MiddleCourtyard = new Location(KAER_MORHEN_COURTYARD_MIDDLE, "Middle Courtyard", "middle", world);
                Location* KaerMorhen_UpperCourtyard = new Location(KAER_MORHEN_COURTYARD_UPPER, "Upper Courtyard", "upper", world);
                    Location* KaerMorhen_Fortress = new Location(KAER_MORHEN_FORTRESS, "Fortress", "fortress", world);
                        Location* KaerMorhen_Fortress_Laboratory = new Location(KAER_MORHEN_LABORATORY, "Laboratory", "laboratory", world);
                            Location* KaerMorhen_Fortress_Laboratory_WhisperingStoneCircle = new Location(KAER_MORHEN_WHISPERING_STONE_CIRCLE, "Whispering Stone Circle Hall", "elementalstone", world);
                        Location* KaerMorhen_Fortress_Kitchen = new Location(KAER_MORHEN_KITCHEN, "Kitchen", "kitchen", world);
                            Location* KaerMorhen_Fortress_WestWing = new Location(KAER_MORHEN_WEST_WING, "West wing", "westwing", world);
                                Location* KaerMorhen_Fortress_WestWing_Library = new Location(KAER_MORHEN_LIBRARY, "Library", "library", world);
                                Location* KaerMorhen_Fortress_WestWing_Armory = new Location(KAER_MORHEN_ARMORY, "Armory", "armory", world);
                                Location* KaerMorhen_Fortress_WestWing_EveningRoom = new Location(KAER_MORHEN_EVENING_ROOM, "Evening room", "eveningroom", world);
                                Location* KaerMorhen_Fortress_WestWing_TrissRoom = new Location(KAER_MORHEN_TRISS_ROOM, "Triss' room", "trissroom", world);
                        Location* KaerMorhen_Fortress_GreatHall = new Location(KAER_MORHEN_GREAT_HALL, "Great hall", "greathall", world);

    KaerMorhen_LowerCourtyard->connect(KaerMorhen_MiddleCourtyard);
        KaerMorhen_MiddleCourtyard->connect(KaerMorhen_UpperCourtyard);
            KaerMorhen_UpperCourtyard->connect(KaerMorhen_Fortress);
                KaerMorhen_Fortress->connect(KaerMorhen_Fortress_Laboratory);
                    KaerMorhen_Fortress_Laboratory->connect(KaerMorhen_Fortress_Laboratory_WhisperingStoneCircle);
                KaerMorhen_Fortress->connect(KaerMorhen_Fortress_Kitchen);
                    KaerMorhen_Fortress_Kitchen->connect(KaerMorhen_Fortress_WestWing);
                        KaerMorhen_Fortress_WestWing->connect(KaerMorhen_Fortress_WestWing_Library);
                        KaerMorhen_Fortress_WestWing->connect(KaerMorhen_Fortress_WestWing_Armory);
                        KaerMorhen_Fortress_WestWing->connect(KaerMorhen_Fortress_WestWing_EveningRoom);
                        KaerMorhen_Fortress_WestWing->connect(KaerMorhen_Fortress_WestWing_TrissRoom);
                KaerMorhen_Fortress->connect(KaerMorhen_Fortress_GreatHall);
                        
    startingLocation = KaerMorhen_LowerCourtyard;
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

    if (!current->globalExits.empty()) {
        std::cout << "\nYou can travel to other locations:\n";
        for (const auto& [dir, loc] : current->globalExits) {
            std::cout << "  - " << dir << " -> " << loc->name << " (different region)\n";
        }
    }
}