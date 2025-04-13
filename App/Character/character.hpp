#pragma once

#include <string>

struct Stats
{
    int attack;
    int defence;
    int health;
};

class Character
{
private:
    std::string name;
    Stats stats;

public:
    Character(const std::string& n, const Stats& s);

    virtual void attack(Character& target);
    virtual void takeDamage(int amount);

    const std::string& getName() const;
    const Stats& getStats() const;
    void setStats(const Stats& s);
};
