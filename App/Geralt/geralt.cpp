#include "geralt.hpp"
#include <iostream>

Geralt::Geralt(const std::string& name, const Stats& baseStats)
    : Character(name, baseStats), 
      energy(100),                
      toxicity(0),                
      current_location(nullptr)   
{
    std::cout << "Geralt constructed with name: " << name << std::endl;
}

Location*& Geralt::getLocationPtr()
{
    return current_location;
}

Location Geralt::getCurrentLocation()
{
    return *current_location;
}

void Geralt::move(const std::string& command)
{
    if (current_location && current_location->exits.find(command) != current_location->exits.end()) {
        current_location = current_location->exits[command];
        std::cout << "Geralt moved to: " << current_location->name << std::endl;
    } else {
        std::cout << "You cannot go that way." << std::endl;
    }
}

int Geralt::getEnergy() const
{
    return energy;
}

void Geralt::setEnergy(int e)
{
    energy = e;
}

int Geralt::getToxicity() const
{
    return toxicity;
}

void Geralt::setToxicity(int t)
{
    toxicity = t;
}

void Geralt::drinkPotion(const SpecialAbility& potion)
{
    activePotions.push_back(potion);
    std::cout << getName() << " drinks potion: " << potion.name << "\n";
}

void Geralt::removePotion(int index)
{
    if (index < 0 || index >= (int)activePotions.size()) {
        std::cout << "Invalid potion index!\n";
        return;
    }
    std::cout << getName() << " potion expired: " 
              << activePotions[index].name << "\n";
    activePotions.erase(activePotions.begin() + index);
}

bool Geralt::unlockTalent(TalentID talentId)
{
    return skillTree.unlockTalent(talentId);
}

bool Geralt::isTalentUnlocked(TalentID talentId) const
{
    return skillTree.isUnlocked(talentId);
}

void Geralt::attack(Character& target)
{
    std::cout << "[Geralt special attack logic?]\n";
    Character::attack(target);
}

void Geralt::takeDamage(int amount)
{
    std::cout << "[Geralt defensive logic?]\n";
    Character::takeDamage(amount);
}

void Geralt::useSpecialAbility(int index)
{
    std::cout << "[Geralt uses special ability - check energy/toxicity?]\n";
    Character::useSpecialAbility(index);
}
