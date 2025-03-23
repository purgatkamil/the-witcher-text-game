#include "geralt_skilltree.hpp"

// Konstruktor wypełnia naszą mapę talents danymi o poszczególnych talentach.
// W rzeczywistości tych talentów jest znacznie więcej i mają bardziej złożone zależności.
// Tu pokazuję przykładowe (uproszczone) wpisy.
GeraltSkillTree::GeraltSkillTree()
{
    talents[TalentID::STRENGTH_BRONZE_1] = {
        TalentID::STRENGTH_BRONZE_1,
        "Strength (Bronze I)",
        "Zwiększa obrażenia melee o +10%.",
        false,
        {}

    talents[TalentID::STRENGTH_BRONZE_2] = {
        TalentID::STRENGTH_BRONZE_2,
        "Strength (Bronze II)",
        "Zwiększa obrażenia melee o dodatkowe +10% (stackuje).",
        false,
        { TalentID::STRENGTH_BRONZE_1 }
    };

    talents[TalentID::STRENGTH_SILVER_1] = {
        TalentID::STRENGTH_SILVER_1,
        "Strength (Silver I)",
        "Zwiększa obrażenia melee o kolejne +15%.",
        false,
        { TalentID::STRENGTH_BRONZE_2 }
    };

    talents[TalentID::STRENGTH_GOLD_1] = {
        TalentID::STRENGTH_GOLD_1,
        "Strength (Gold I)",
        "Zwiększa obrażenia melee +20%.",
        false,
        { TalentID::STRENGTH_SILVER_1 }
    };

 
    talents[TalentID::DEXTERITY_BRONZE_1] = {
        TalentID::DEXTERITY_BRONZE_1,
        "Dexterity (Bronze I)",
        "Zwiększa szansę na unik i szybkość ataku.",
        false,
        {}
    };

    talents[TalentID::STRONG_STEEL_BRONZE_1] = {
        TalentID::STRONG_STEEL_BRONZE_1,
        "Strong Steel Style (Bronze I)",
        "Pozwala wykonywać podstawowe silne ataki stalowe.",
        false,
        {}
    };

    talents[TalentID::STRONG_STEEL_SILVER_1] = {
        TalentID::STRONG_STEEL_SILVER_1,
        "Strong Steel Style (Silver I)",
        "Ulepszone silne ataki stalowe (+20% obrażeń).",
        false,
        { TalentID::STRONG_STEEL_BRONZE_1 }
    };

    talents[TalentID::STRONG_SILVER_BRONZE_1] = {
        TalentID::STRONG_SILVER_BRONZE_1,
        "Strong Silver Style (Bronze I)",
        "Pozwala wykonywać podstawowe silne ataki srebrne (przeciw potworom).",
        false,
        {}
    };

    talents[TalentID::AARD_BRONZE_1] = {
        TalentID::AARD_BRONZE_1,
        "Aard (Bronze)",
        "Telekinetyczne uderzenie, odrzuca przeciwników.",
        false,
        {}
    };

    talents[TalentID::AARD_SILVER_1] = {
        TalentID::AARD_SILVER_1,
        "Aard (Silver)",
        "Wzmocnione telekinetyczne uderzenie.",
        false,
        { TalentID::AARD_BRONZE_1 }
    };
}

bool GeraltSkillTree::unlockTalent(TalentID talentId)
{
    auto it = talents.find(talentId);
    if (it == talents.end()) {
        std::cout << "Talent not found!\n";
        return false;
    }

    if (it->second.unlocked) {
        std::cout << "Talent " << it->second.name << " is already unlocked!\n";
        return false;
    }

    for (auto prereq : it->second.prerequisites) {
        if (!isUnlocked(prereq)) {
            std::cout << "Cannot unlock " << it->second.name 
                      << ". Prerequisite not met!\n";
            return false;
        }
    }

    it->second.unlocked = true;
    std::cout << "Unlocked talent: " << it->second.name << "\n";
    return true;
}

bool GeraltSkillTree::isUnlocked(TalentID talentId) const
{
    auto it = talents.find(talentId);
    if (it != talents.end()) {
        return it->second.unlocked;
    }
    return false;
}

const TalentNode* GeraltSkillTree::getTalentData(TalentID talentId) const
{
    auto it = talents.find(talentId);
    if (it != talents.end()) {
        return &(it->second);
    }
    return nullptr;
}
