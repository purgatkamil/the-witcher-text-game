#include "../Fight/fight.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Character/character.hpp"

using namespace std;

void fight(CombatCharacter& fighter1, CombatCharacter& fighter2) {
    srand(time(0));
    
    cout << "A battle begins between " << fighter1.get_name() << " and " << fighter2.get_name() << "!" << endl;
    
    while (fighter1.get_health() > 0 && fighter2.get_health() > 0) {
        // Fighter 1 attacks
        int attackRoll1 = rand() % 10 + 1; // Losowy rzut na skuteczność ataku
        if (attackRoll1 > 2) { // 80% szans na trafienie
            fighter1.attack(fighter2);
        } else {
            cout << fighter1.get_name() << " missed the attack!" << endl;
        }
        
        // Sprawdzenie, czy fighter2 został pokonany
        if (fighter2.get_health() <= 0) {
            cout << fighter2.get_name() << " has been defeated!" << endl;
            break;
        }
        
        // Fighter 2 attacks
        int attackRoll2 = rand() % 10 + 1;
        if (attackRoll2 > 2) {
            fighter2.attack(fighter1);
        } else {
            cout << fighter2.get_name() << " missed the attack!" << endl;
        }
        
        // Sprawdzenie, czy fighter1 został pokonany
        if (fighter1.get_health() <= 0) {
            cout << fighter1.get_name() << " has been defeated!" << endl;
            break;
        }
    }
    cout << "The battle is over!" << endl;
}