#pragma once

#include "../Character/character.hpp"
#include "../Geralt/geralt_skilltree.hpp"
#include "../Map/map.hpp" 

class Geralt : public Character
{
private:
    std::shared_ptr<Location>  current_location; 
    int energy;
    int toxicity; 
    std::vector<SpecialAbility> activePotions;

    GeraltSkillTree skillTree;

public:
    Geralt(const std::string& name, const Stats& baseStats);

    std::shared_ptr<Location>& getLocationPtr();
    std::shared_ptr<Location> getCurrentLocation() const;
    void move(const std::string& command);

    int getEnergy() const;
    void setEnergy(int e);
    int getToxicity() const;
    void setToxicity(int t);

    void drinkPotion(const SpecialAbility& potion);
    void removePotion(int index);

    bool unlockTalent(TalentID talentId);
    bool isTalentUnlocked(TalentID talentId) const;

    void attack(Character& target) override;
    void takeDamage(int amount) override;
    void useSpecialAbility(int index) override;
};
