#pragma once

#include <string>
#include <map>
#include <vector>
#include <iostream>

enum class TalentID {
    STRENGTH_BRONZE_1,
    STRENGTH_BRONZE_2,
    STRENGTH_SILVER_1,
    STRENGTH_GOLD_1,

    DEXTERITY_BRONZE_1,
    DEXTERITY_BRONZE_2,
    DEXTERITY_SILVER_1,
    DEXTERITY_GOLD_1,

    STAMINA_BRONZE_1,
    STAMINA_SILVER_1,
    STAMINA_GOLD_1,

    INTELLIGENCE_BRONZE_1,
    INTELLIGENCE_SILVER_1,
    INTELLIGENCE_GOLD_1,

    STRONG_STEEL_BRONZE_1,
    STRONG_STEEL_SILVER_1,
    STRONG_STEEL_GOLD_1,

    FAST_STEEL_BRONZE_1,
    FAST_STEEL_SILVER_1,
    FAST_STEEL_GOLD_1,

    GROUP_STEEL_BRONZE_1,
    GROUP_STEEL_SILVER_1,

    STRONG_SILVER_BRONZE_1,
    STRONG_SILVER_SILVER_1,
    STRONG_SILVER_GOLD_1,

    FAST_SILVER_BRONZE_1,
    FAST_SILVER_SILVER_1,
    FAST_SILVER_GOLD_1,

    GROUP_SILVER_BRONZE_1,
    GROUP_SILVER_SILVER_1,

    AARD_BRONZE_1,
    AARD_SILVER_1,
    IGNI_BRONZE_1,
    IGNI_SILVER_1,
    QUEN_BRONZE_1,
    YRDEN_BRONZE_1,
    AXII_BRONZE_1,
};

struct TalentNode
{
    TalentID id;
    std::string name;           
    std::string description;     
    bool unlocked;             

    std::vector<TalentID> prerequisites;
};

class GeraltSkillTree
{
private:
    std::map<TalentID, TalentNode> talents;

public:
    GeraltSkillTree();

    //bool unlockTalent(TalentID talentId);

    //bool isUnlocked(TalentID talentId) const;

    //const TalentNode* getTalentData(TalentID talentId) const;
};
