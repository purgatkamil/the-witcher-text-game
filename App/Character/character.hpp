#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../types.hpp"

using namespace std;

class Character {
protected:
    string name;
    int health;
public:
    Character(string n, int h);
    virtual ~Character();
    
    virtual void take_damage(int damage);
    
    string get_name() const;
    int get_health() const;
};

class CombatCharacter : public Character {
protected:
    int attack_power;
    int block_power;
    vector<string> special_traits;
public:
    CombatCharacter(string n, int h, int atk, int blk, vector<string> traits);
    
    void attack(Character& target);
    void block();
    void display_traits();
};

class NPC : public Character {
    string location;
public:
    NPC(string n, int h, string loc);
    void talk();
};

class Enemy : public CombatCharacter {
    string type;
    string subtype;
public:
    Enemy(string n, int h, int atk, int blk, vector<string> traits, string t, string st);
};

class GeraltStats {
    int strength;
    int agility;
    int stamina;
    int intelligence;
};

class GeraltSigns {
    vector<string> aard;
    vector<string> igni;
    vector<string> yrden;
    vector<string> quen;
    vector<string> aksji;
};

class FightingStyles {
    vector<string> strong;
    vector<string> fast;
    vector<string> group;
};

class Geralt : public CombatCharacter {
    int energy;
    int toxicity;
    Location* current_location;
    GeraltStats stats;
    GeraltSigns signs;
    FightingStyles silverSword;
    FightingStyles steelSword;
public:
    Geralt();

    Location*& getLocationPtr();
    Location getCurrentLocation();
    void move(const string& command);
};