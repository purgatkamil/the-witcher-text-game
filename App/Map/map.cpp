#include "../Map/map.hpp"

Location::Location(Locations_e id, std::string n, std::string label) {
    this->id = id;
    this->name = n;
    this->label = label;
}

void Location::registerInWorld(GameWorld& world) {
    world[this->name] = shared_from_this();
}

std::shared_ptr<Location> makeLocation(Locations_e id, const std::string& name, const std::string& label, GameWorld& world) {
    std::shared_ptr<Location> loc = std::make_shared<Location>(id, name, label);
    loc->registerInWorld(world);
    return loc;
}

std::string Location::getDescription() {
    return Descriptions::getDescription(this->id);
}

void Location::addExit(std::shared_ptr<Location> target) {
    exits[target->label] = target;
}

void Location::addGlobalExit(std::shared_ptr<Location> target) {
    globalExits[target->label] = target;
}

void Location::connect(std::shared_ptr<Location> locationB) {
    this->addExit(locationB);
    locationB->addExit(shared_from_this());
}

void createWorld(GameWorld& world, std::shared_ptr<Location>& startingLocation)
{
    std::shared_ptr<Location> KaerMorhen = makeLocation(KAER_MORHEN, "Kaer Morhen", "kaermorhen", world);
        std::shared_ptr<Location> KaerMorhen_LowerCourtyard = makeLocation(KAER_MORHEN_COURTYARD_LOWER, "Lower Courtyard", "lower", world);
            std::shared_ptr<Location> KaerMorhen_MiddleCourtyard = makeLocation(KAER_MORHEN_COURTYARD_MIDDLE, "Middle Courtyard", "middle", world);
                std::shared_ptr<Location> KaerMorhen_UpperCourtyard = makeLocation(KAER_MORHEN_COURTYARD_UPPER, "Upper Courtyard", "upper", world);
                    std::shared_ptr<Location> KaerMorhen_Fortress = makeLocation(KAER_MORHEN_FORTRESS, "Fortress", "fortress", world);
                        std::shared_ptr<Location> KaerMorhen_Fortress_Laboratory = makeLocation(KAER_MORHEN_LABORATORY, "Laboratory", "laboratory", world);
                            std::shared_ptr<Location> KaerMorhen_Fortress_Laboratory_WhisperingStoneCircle = makeLocation(KAER_MORHEN_WHISPERING_STONE_CIRCLE, "Whispering Stone Circle Hall", "elementalstone", world);
                        std::shared_ptr<Location> KaerMorhen_Fortress_Kitchen = makeLocation(KAER_MORHEN_KITCHEN, "Kitchen", "kitchen", world);
                            std::shared_ptr<Location> KaerMorhen_Fortress_WestWing = makeLocation(KAER_MORHEN_WEST_WING, "West wing", "westwing", world);
                                std::shared_ptr<Location> KaerMorhen_Fortress_WestWing_Library = makeLocation(KAER_MORHEN_LIBRARY, "Library", "library", world);
                                std::shared_ptr<Location> KaerMorhen_Fortress_WestWing_Armory = makeLocation(KAER_MORHEN_ARMORY, "Armory", "armory", world);
                                std::shared_ptr<Location> KaerMorhen_Fortress_WestWing_EveningRoom = makeLocation(KAER_MORHEN_EVENING_ROOM, "Evening room", "eveningroom", world);
                                std::shared_ptr<Location> KaerMorhen_Fortress_WestWing_TrissRoom = makeLocation(KAER_MORHEN_TRISS_ROOM, "Triss' room", "trissroom", world);
                        std::shared_ptr<Location> KaerMorhen_Fortress_GreatHall = makeLocation(KAER_MORHEN_GREAT_HALL, "Great hall", "greathall", world);

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

void displayLocation(std::shared_ptr<Location> current) {
    std::cout << "\nYou are in: " << current->name << "\n";
    std::cout << "\n" << current->getDescription() << "\n";

    if (!current->exits.empty()) {
        std::cout << "\nYou can move within this area:\n";
        for (const auto& [dir, weakLoc] : current->exits) {
            if (auto loc = weakLoc.lock()) {
                std::cout << "  - " << dir << " -> " << loc->name << "\n";
            }
        }
        
    }

    if (!current->globalExits.empty()) {
        std::cout << "\nYou can travel to other locations:\n";
        for (const auto& [dir, weakLoc] : current->globalExits) {
            if (auto loc = weakLoc.lock()) {
                std::cout << "  - " << dir << " -> " << loc->name << " (different region)\n";
            }
        }
    }
}