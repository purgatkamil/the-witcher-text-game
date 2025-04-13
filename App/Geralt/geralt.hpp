#pragma once

#include "../Character/character.hpp"
#include "../Map/map.hpp"

class Geralt : public Character
{
private:
    Location* current_location; 
    int energy;
    int toxicity;

public:
    Geralt(const std::string& name, const Stats& baseStats);

    Location*& getLocationPtr();
    Location getCurrentLocation();
    void move(const std::string& command);

    int getEnergy() const;
    void setEnergy(int e);
    int getToxicity() const;
    void setToxicity(int t);

    void attack(Character& target) override;
    void takeDamage(int amount) override;
};
