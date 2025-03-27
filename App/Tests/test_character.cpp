#include <gtest/gtest.h>
#include "../Character/character.hpp"
#include <sstream>
#include <iostream>

Stats createDefaultStats() {
    return {10, 10, 10, 10, 100};
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

TEST(CharacterTest, AddResistanceStoresCorrectly) {
    Character c("Hero", createDefaultStats());
    c.addResistance("fire", 0.25f);
    // No public getter to verify the stored value directly, placeholder for now
    SUCCEED();
}

TEST(CharacterTest, AddWeaknessStoresCorrectly) {
    Character c("Hero", createDefaultStats());
    c.addWeakness("ice", -0.4f);
    // No public getter to verify the stored value directly, placeholder for now
    SUCCEED();
}

TEST(CharacterTest, AttackPrintsCorrectMessage) {
    Character c1("Warrior", createDefaultStats());
    Character c2("Goblin", createDefaultStats());

    testing::internal::CaptureStdout();
    c1.attack(c2);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Warrior attacks Goblin!"), std::string::npos);
}

TEST(CharacterTest, SetStatsChangesStats) {
    Character c("Hero", createDefaultStats());
    Stats newStats = {5, 5, 5, 5, 50};
    c.setStats(newStats);

    EXPECT_EQ(c.getStats().health, 50);
    EXPECT_EQ(c.getStats().strength, 5);
}
