#include "Map/map.hpp"
#include "Character/character.hpp"

int main() {
    // Tworzymy świat gry
    GameWorld world;
    Geralt Geralt;

    createWorld(world, Geralt.getLocationPtr());
    
    Descriptions::initialize();  // Przypisujemy opisy do lokacji

    // Pętla gry
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
