#include "Map/map.hpp"
#include "Character/character.hpp"
#include "Geralt/geralt.hpp"

void runAutoTest(void) {
    std::cout << "Running auto test...\n";

    GameWorld test_world;
    Geralt test_geralt("TestGeralt", Stats{ 10, 8, 9, 6, 100 });

    createWorld(test_world, test_geralt.getLocationPtr());
    Descriptions::initialize();

    displayLocation(test_geralt.getLocationPtr());

    std::vector<std::string> path = { "middle", "upper", "fortress", "laboratory", "elementalstone" };

    for (const auto& dir : path) {
        test_geralt.move(dir);
        displayLocation(test_geralt.getLocationPtr());
    }

    std::cout << "Auto test completed.\n";
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
