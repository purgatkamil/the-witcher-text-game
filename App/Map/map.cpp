#include "../Map/map.hpp"

void createWorld(GameWorld& world, Location*& startingLocation) {
    Location* KaerMorhen = new Location(KAER_MORHEN, "KaerMorhen", world);
        Location* KaerMorhen_LowerCourtyard = new Location(KAER_MORHEN_COURTYARD_LOWER, "Lower Courtyard", world);
            Location* KaerMorhen_MiddleCourtyard = new Location(KAER_MORHEN_COURTYARD_MIDDLE, "Middle Courtyard", world);
                Location* KaerMorhen_UpperCourtyard = new Location(KAER_MORHEN_COURTYARD_UPPER, "Upper Courtyard", world);
                    Location* KaerMorhen_Fortress = new Location(KAER_MORHEN_FORTRESS, "Fortress", world);
                        Location* KaerMorhen_Fortress_Laboratory = new Location(KAER_MORHEN_LABORATORY, "Laboratory", world);
                            Location* KaerMorhen_Fortress_Laboratory_WhisperingStoneCircle = new Location(KAER_MORHEN_WHISPERING_STONE_CIRCLE, "Whispering Stone Circle Hall", world);
                        Location* KaerMorhen_Fortress_Kitchen = new Location(KAER_MORHEN_KITCHEN, "Kitchen", world);
                            Location* KaerMorhen_Fortress_WestWing = new Location(KAER_MORHEN_WEST_WING, "West wing", world);
                                Location* KaerMorhen_Fortress_WestWing_Library = new Location(KAER_MORHEN_LIBRARY, "Library", world);
                                Location* KaerMorhen_Fortress_WestWing_Armory = new Location(KAER_MORHEN_ARMORY, "Armory", world);
                                Location* KaerMorhen_Fortress_WestWing_EveningRoom = new Location(KAER_MORHEN_EVENING_ROOM, "Evening room", world);
                                Location* KaerMorhen_Fortress_WestWing_TrissRoom = new Location(KAER_MORHEN_TRISS_ROOM, "Triss' room", world);
                        Location* KaerMorhen_Fortress_GreatHall = new Location(KAER_MORHEN_GREAT_HALL, "Great hall", world);

        KaerMorhen_LowerCourtyard->addExit("middle", KaerMorhen_MiddleCourtyard);
            KaerMorhen_MiddleCourtyard->addExit("lower", KaerMorhen_LowerCourtyard);
            KaerMorhen_MiddleCourtyard->addExit("upper", KaerMorhen_UpperCourtyard);
                KaerMorhen_UpperCourtyard->addExit("middle", KaerMorhen_MiddleCourtyard);
                KaerMorhen_UpperCourtyard->addExit("fortress", KaerMorhen_Fortress);
                    KaerMorhen_Fortress->addExit("upper", KaerMorhen_UpperCourtyard);
                    KaerMorhen_Fortress->addExit("laboratory", KaerMorhen_Fortress_Laboratory);
                        KaerMorhen_Fortress_Laboratory->addExit("fortress", KaerMorhen_Fortress);
                        KaerMorhen_Fortress_Laboratory->addExit("elementalstone", KaerMorhen_Fortress_Laboratory_WhisperingStoneCircle);
                            KaerMorhen_Fortress_Laboratory_WhisperingStoneCircle->addExit("laboratory", KaerMorhen_Fortress_Laboratory);
                    KaerMorhen_Fortress->addExit("kitchen", KaerMorhen_Fortress_Kitchen);
                        KaerMorhen_Fortress_Kitchen->addExit("fortress", KaerMorhen_Fortress);
                        KaerMorhen_Fortress_Kitchen->addExit("westwing", KaerMorhen_Fortress_WestWing);
                            KaerMorhen_Fortress_WestWing->addExit("kitchen", KaerMorhen_Fortress_Kitchen);
                                KaerMorhen_Fortress_WestWing->addExit("library", KaerMorhen_Fortress_WestWing_Library);
                                    KaerMorhen_Fortress_WestWing_Library->addExit("westwing", KaerMorhen_Fortress_WestWing);
                                KaerMorhen_Fortress_WestWing->addExit("armory", KaerMorhen_Fortress_WestWing_Armory);
                                    KaerMorhen_Fortress_WestWing_Armory->addExit("westwing", KaerMorhen_Fortress_WestWing);
                                KaerMorhen_Fortress_WestWing->addExit("eveningroom", KaerMorhen_Fortress_WestWing_EveningRoom);
                                    KaerMorhen_Fortress_WestWing_EveningRoom->addExit("westwing", KaerMorhen_Fortress_WestWing);
                                KaerMorhen_Fortress_WestWing->addExit("trissroom", KaerMorhen_Fortress_WestWing_TrissRoom);
                                    KaerMorhen_Fortress_WestWing_TrissRoom->addExit("westwing", KaerMorhen_Fortress_WestWing);
                    KaerMorhen_Fortress->addExit("greathall", KaerMorhen_Fortress_GreatHall);
                    KaerMorhen_Fortress_GreatHall->addExit("fortress", KaerMorhen_Fortress);

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