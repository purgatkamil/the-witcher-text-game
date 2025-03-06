#include "Map/map.hpp"
#include "Character/character.hpp"
#include "Fight/fight.hpp"

int main() {
    GameWorld world;
    Geralt Geralt;

    createWorld(world, Geralt.getLocationPtr());
    
    Descriptions::initialize();

    std::string command;
    while (true) {
        displayLocation(Geralt.getLocationPtr());

        std::cout << "\nEnter a direction to move (or 'exit' to quit): ";
        std::cin >> command;

        if (command == "exit") {
            std::cout << "Exiting the game. Goodbye!\n";
            break;
        }

        Geralt.move(command);
    }

    return 0;
}
