#pragma once

#include <string>
#include <vector>
#include <map>
#include "special_abilities.hpp"

struct Stats
{
    int strength;       
    int dexterity;      
    int endurance;      
    int intelligence;  
    int health;
};

class Character
{
private:
    std::string name;
    Stats stats;

    // Odporności i słabości można reprezentować jako mapę:
    // klucz = np. typ obrażeń ("fire", "poison", "bleed" itp.)
    // wartość = modyfikator odporności (dodatni - odporność, ujemny - słabość)
    // Np. +0.2 oznacza 20% redukcji obrażeń, -0.3 oznacza 30% więcej otrzymanych obrażeń.
    std::map<std::string, float> resistances;
    std::map<std::string, float> weaknesses;

    std::vector<SpecialAbility> specialAbilities;

public:
    Character(const std::string& n, const Stats& s);

    virtual void attack(Character& target);
    virtual void takeDamage(int amount);
    virtual void useSpecialAbility(int index); 

    const std::string& getName() const;
    const Stats& getStats() const;
    void setStats(const Stats& s);

    void addResistance(const std::string& type, float value);
    void addWeakness(const std::string& type, float value);

    void addSpecialAbility(const SpecialAbility& ability);
    int getSpecialAbilityCount() const;
};