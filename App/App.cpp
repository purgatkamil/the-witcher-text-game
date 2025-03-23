#include "Map/map.hpp"
#include "Character/character.hpp"
#include "Geralt/geralt.hpp"

void runAutoTest(void)
{

}

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "--test-mode") {
        runAutoTest(); 
        return 0;
    }

    GameWorld world;
    Stats geraltStats = { 10, 8, 9, 6, 100 };
    Geralt Geralt("Geralt of Rivia", geraltStats);

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
