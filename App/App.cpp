#include "Map/map.hpp"

int main() {
    // Tworzymy świat gry
    GameWorld world;
    Location* currentLocation = nullptr;
    createWorld(world, currentLocation);
    Descriptions::initialize(world);  // Przypisujemy opisy do lokacji

    // Pętla gry
    std::string command;
    while (true) {
        displayLocation(currentLocation);

        std::cout << "\nEnter a direction to move (or 'exit' to quit): ";
        std::cin >> command;

        if (command == "exit") {
            std::cout << "Exiting the game. Goodbye!\n";
            break;
        }

        if (currentLocation->exits.find(command) != currentLocation->exits.end()) {
            currentLocation = currentLocation->exits[command];
        } else {
            std::cout << "You cannot go that way.\n";
        }
    }

    return 0;
}
