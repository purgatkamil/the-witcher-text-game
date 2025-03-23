#include "character.hpp"
#include <iostream>

Character::Character(const std::string& n, const Stats& s)
    : name(n), stats(s)
{

}

void Character::attack(Character& target)
{
    std::cout << name << " attacks " << target.getName() << "!" << std::endl;
}

void Character::takeDamage(int amount)
{
    stats.health -= amount;
    if (stats.health < 0) stats.health = 0;
    std::cout << name << " takes " << amount << " damage! "
              << "Current health: " << stats.health << std::endl;
}

void Character::useSpecialAbility(int index)
{
    if (index < 0 || index >= (int)specialAbilities.size())
    {
        std::cout << "Invalid ability index for " << name << std::endl;
        return;
    }
    specialAbilities[index].useAbility(name);
}

const std::string& Character::getName() const
{
    return name;
}

const Stats& Character::getStats() const
{
    return stats;
}

void Character::setStats(const Stats& s)
{
    stats = s;
}

void Character::addResistance(const std::string& type, float value)
{
    resistances[type] = value;
}

void Character::addWeakness(const std::string& type, float value)
{
    weaknesses[type] = value;
}

void Character::addSpecialAbility(const SpecialAbility& ability)
{
    specialAbilities.push_back(ability);
}

int Character::getSpecialAbilityCount() const
{
    return (int)specialAbilities.size();
}