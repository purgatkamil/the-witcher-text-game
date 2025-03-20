#include <gtest/gtest.h>
#include "../Map/map.hpp"

class MockDescriptions : public Descriptions {
public:
    static std::string getDescription(Locations_e id) {
        return "Mock description for location ID " + std::to_string(id);
    }
};

TEST(LocationTest, ConstructorTest) {
    GameWorld world;
    Location loc(KAER_MORHEN, "Kaer Morhen", "kaermorhen", world);

    EXPECT_EQ(loc.id, KAER_MORHEN);
    EXPECT_EQ(loc.name, "Kaer Morhen");
    EXPECT_EQ(loc.label, "kaermorhen");
    EXPECT_EQ(world["Kaer Morhen"], &loc);
}

TEST(LocationTest, GetDescriptionTest) {
    GameWorld world;
    Location loc(KAER_MORHEN, "Kaer Morhen", "kaermorhen", world);

    EXPECT_EQ(MockDescriptions::getDescription(loc.id), 
              "Mock description for location ID " + std::to_string(KAER_MORHEN));
}

TEST(LocationTest, AddExitTest) {
    GameWorld world;
    Location locA(KAER_MORHEN, "Kaer Morhen", "kaermorhen", world);
    Location locB(KAER_MORHEN_COURTYARD_LOWER, "Lower Courtyard", "lower", world);

    locA.addExit(&locB);
    EXPECT_EQ(locA.exits["lower"], &locB);
}

TEST(LocationTest, AddGlobalExitTest) {
    GameWorld world;
    Location locA(KAER_MORHEN, "Kaer Morhen", "kaermorhen", world);
    Location locB(KAER_MORHEN_FORTRESS, "Fortress", "fortress", world);

    locA.addGlobalExit(&locB);
    EXPECT_EQ(locA.globalExits["fortress"], &locB);
}

TEST(LocationTest, ConnectTest) {
    GameWorld world;
    Location locA(KAER_MORHEN, "Kaer Morhen", "kaermorhen", world);
    Location locB(KAER_MORHEN_COURTYARD_LOWER, "Lower Courtyard", "lower", world);

    locA.connect(&locB);

    EXPECT_EQ(locA.exits["lower"], &locB);
    EXPECT_EQ(locB.exits["kaermorhen"], &locA);
}

TEST(WorldTest, CreateWorldTest) {
    GameWorld world;
    Location* startingLocation = nullptr;
    
    createWorld(world, startingLocation);

    EXPECT_NE(startingLocation, nullptr);
    EXPECT_EQ(startingLocation->name, "Lower Courtyard");
    EXPECT_EQ(startingLocation->label, "lower");
}

TEST(WorldTest, DisplayLocationTest) {
    GameWorld world;
    Location loc(KAER_MORHEN, "Kaer Morhen", "kaermorhen", world);

    testing::internal::CaptureStdout();
    displayLocation(&loc);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("You are in: Kaer Morhen"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
