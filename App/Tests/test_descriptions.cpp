#include <gtest/gtest.h>
#include "../Descriptions/descriptions.hpp"

class DescriptionsTest : public ::testing::Test {
protected:
    void SetUp() override {
        Descriptions::initialize();
    }
};

TEST_F(DescriptionsTest, TestValidDescription) {
    EXPECT_EQ(Descriptions::getDescription(Locations_e::KAER_MORHEN), "The ancient stronghold of the witchers, nestled deep within the Amell Mountains, shrouded in mist and forgotten history. Its weathered stone walls still stand tall over the valley, though their days of glory have long since faded. The wind howls through abandoned towers, carrying echoes of past battles and training. The courtyard, once bustling with young adepts, is now overgrown with weeds, and the old forge barely remembers the warmth of fire. The main hall still smells of smoke and damp stone, while the underground chambers guard tomes filled with knowledge of monsters and elixirs. On the ramparts, the past lingers-a silent presence of long-gone mages and warriors watching over the fallen sanctuary.");
}

TEST_F(DescriptionsTest, TestInvalidDescription) {
    EXPECT_EQ(Descriptions::getDescription(static_cast<Locations_e>(999)), "No description available.");
}

TEST_F(DescriptionsTest, TestEmptyInitialization) {
    Descriptions::descriptions.clear();
    EXPECT_EQ(Descriptions::getDescription(Locations_e::KAER_MORHEN), "No description available.");
}
