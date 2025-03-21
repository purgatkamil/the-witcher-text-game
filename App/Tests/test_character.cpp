#include <gtest/gtest.h>
#include "../Character/character.hpp"
#include "../Map/map.hpp"

// ---------- Character Tests ----------

TEST(CharacterTest, TakeDamageReducesHealth) {
    Character c("TestChar", 100);
    c.take_damage(25);
    EXPECT_EQ(c.get_health(), 75);
}

TEST(CharacterTest, CharacterDefeatedMessage) {
    Character c("WeakChar", 10);
    testing::internal::CaptureStdout();
    c.take_damage(15);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("has been defeated") != std::string::npos);
}

// ---------- CombatCharacter Tests ----------

TEST(CombatCharacterTest, AttackReducesTargetHealth) {
    CombatCharacter attacker("Attacker", 100, 30, 5, {});
    Character target("Target", 100);
    attacker.attack(target);
    EXPECT_EQ(target.get_health(), 70);
}

TEST(CombatCharacterTest, DisplayTraitsPrintsCorrectly) {
    CombatCharacter fighter("Fighter", 100, 20, 10, {"Fast", "Strong"});
    testing::internal::CaptureStdout();
    fighter.display_traits();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Fast") != std::string::npos);
    EXPECT_TRUE(output.find("Strong") != std::string::npos);
}

// ---------- NPC Tests ----------

TEST(NPCTest, TalkPrintsMessage) {
    NPC npc("Villager", 30, "Forest");
    testing::internal::CaptureStdout();
    npc.talk();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Hello, traveler!") != std::string::npos);
}

// ---------- Enemy Tests ----------

TEST(EnemyTest, InitializesCorrectly) {
    Enemy e("Ghoul", 50, 15, 5, {"Undead"}, "Monster", "Ghoul");
    EXPECT_EQ(e.get_name(), "Ghoul");
    EXPECT_EQ(e.get_health(), 50);
}

// ---------- Geralt Tests ----------

TEST(GeraltTest, InitializationCorrect) {
    Geralt g;
    EXPECT_EQ(g.get_name(), "Geralt");
    EXPECT_EQ(g.get_health(), 100);
}

TEST(GeraltTest, MoveToValidDirectionUpdatesLocation) {
    Geralt g;
    GameWorld world;

    auto* loc1 = new Location(KAER_MORHEN, "Kaer Morhen", "kaermorhen", world);
    auto* loc2 = new Location(KAER_MORHEN_COURTYARD_LOWER, "Lower Courtyard", "lower", world);

    loc1->exits["east"] = loc2;
    g.getLocationPtr() = loc1;

    testing::internal::CaptureStdout();
    g.move("east");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Geralt moved to: Lower Courtyard") != std::string::npos);

    delete loc1;
    delete loc2;
}

/* not implemented yet

TEST(GeraltTest, MoveInvalidDirectionPrintsError) {
    Geralt g;
    GameWorld world;

    auto* loc1 = new Location(KAER_MORHEN, "Kaer Morhen", "kaermorhen", world);

    g.getLocationPtr() = loc1;

    testing::internal::CaptureStdout();
    g.move("north");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("You cannot go that way") != std::string::npos);

    delete loc1;
}*/
