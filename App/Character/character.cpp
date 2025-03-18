#include "../Character/character.hpp"
#include "../Map/map.hpp"

using namespace std;

// Character Class Implementation
Character::Character(string n, int h) : name(n), health(h) {}
Character::~Character() {}

void Character::take_damage(int damage) {
    health -= damage;
    cout << name << " took " << damage << " damage. Remaining health: " << health << endl;
    if (health <= 0) {
        cout << name << " has been defeated!" << endl;
    }
}

string Character::get_name() const { return name; }
int Character::get_health() const { return health; }

// CombatCharacter Class Implementation
CombatCharacter::CombatCharacter(string n, int h, int atk, int blk, vector<string> traits)
    : Character(n, h), attack_power(atk), block_power(blk), special_traits(traits) {}

void CombatCharacter::attack(Character& target) {
    cout << name << " attacks " << target.get_name() << " with power " << attack_power << "!" << endl;
    target.take_damage(attack_power);
}

void CombatCharacter::block() {
    cout << name << " blocks with power " << block_power << "!" << endl;
}

void CombatCharacter::display_traits() {
    cout << name << " has the following traits: ";
    for (const string& trait : special_traits) {
        cout << trait << " ";
    }
    cout << endl;
}

// NPC Class Implementation
NPC::NPC(string n, int h, string loc) : Character(n, h), location(loc) {}

void NPC::talk() {
    cout << name << " at " << location << " says: Hello, traveler!" << endl;
}

// Enemy Class Implementation
Enemy::Enemy(string n, int h, int atk, int blk, vector<string> traits, string t, string st)
    : CombatCharacter(n, h, atk, blk, traits), type(t), subtype(st) {}

// Geralt Class Implementation
Geralt::Geralt() : CombatCharacter("Geralt", 100, 20, 10, {}), energy(100), toxicity(0), current_location(nullptr) {}

Location*& Geralt::getLocationPtr()
{
    return current_location;
}

Location Geralt::getCurrentLocation()
{
    return *current_location;
}

void Geralt::move(const string& command) {
    if (current_location && current_location->exits.find(command) != current_location->exits.end()) {
        current_location = current_location->exits[command];
        cout << "Geralt moved to: " << current_location->name << endl;
    } else {
        cout << "You cannot go that way." << endl;
    }
}