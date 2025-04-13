#include <gtest/gtest.h>
#include "../Character/character.hpp"
#include <sstream>
#include <iostream>

Stats createDefaultStats() {
    return {10, 5, 100};
}

TEST(CharacterTest, ConstructorInitializesFieldsCorrectly) {
    Stats s = createDefaultStats();
    Character c("Hero", s);

    EXPECT_EQ(c.getName(), "Hero");
    EXPECT_EQ(c.getStats().health, 100);
}

TEST(CharacterTest, TakeDamageReducesHealth) {
    Character c("Hero", createDefaultStats());
    c.takeDamage(30);

    EXPECT_EQ(c.getStats().health, 70);
}

TEST(CharacterTest, TakeDamageCannotGoBelowZero) {
    Character c("Hero", createDefaultStats());
    c.takeDamage(150);

    EXPECT_EQ(c.getStats().health, 0);
}

TEST(CharacterTest, AttackReducesHealthBasedOnDefence) {
    Stats attackerStats = {20, 5, 100};
    Stats defenderStats = {10, 10, 100};
    Character attacker("Warrior", attackerStats);
    Character defender("Goblin", defenderStats);

    attacker.attack(defender);
    EXPECT_EQ(defender.getStats().health, 90);
}

TEST(CharacterTest, SetStatsChangesStats) {
    Character c("Hero", createDefaultStats());
    Stats newStats = {15, 10, 50};
    c.setStats(newStats);

    EXPECT_EQ(c.getStats().health, 50);
    EXPECT_EQ(c.getStats().attack, 15);
    EXPECT_EQ(c.getStats().defence, 10);
}
