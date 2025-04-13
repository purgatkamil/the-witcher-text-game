#include "character.hpp"
#include <iostream>

Character::Character(const std::string& n, const Stats& s)
    : name(n), stats(s)
{
}

void Character::attack(Character& target)
{
    std::cout << name << " attacks " << target.getName() << "!" << std::endl;

    int damage = stats.attack - target.getStats().defence;
    if (damage < 0) damage = 0;

    target.takeDamage(damage);
}

void Character::takeDamage(int amount)
{
    stats.health -= amount;
    if (stats.health < 0) stats.health = 0;

    std::cout << name << " takes " << amount << " damage! "
              << "Current health: " << stats.health << std::endl;
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
