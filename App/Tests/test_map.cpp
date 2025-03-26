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
    std::shared_ptr<Location> loc = std::make_shared<Location>(KAER_MORHEN, "Kaer Morhen", "kaermorhen");

    EXPECT_EQ(loc->id, KAER_MORHEN);
    EXPECT_EQ(loc->name, "Kaer Morhen");
    EXPECT_EQ(loc->label, "kaermorhen");
}

TEST(LocationTest, GetDescriptionTest) {
    GameWorld world;
    std::shared_ptr<Location> loc = std::make_shared<Location>(KAER_MORHEN, "Kaer Morhen", "kaermorhen");

    EXPECT_EQ(MockDescriptions::getDescription(loc->id), 
              "Mock description for location ID " + std::to_string(KAER_MORHEN));
}

TEST(LocationTest, AddExitTest) {
    GameWorld world;
    std::shared_ptr<Location> locA = std::make_shared<Location>(KAER_MORHEN, "Kaer Morhen", "kaermorhen");
    std::shared_ptr<Location> locB = std::make_shared<Location>(KAER_MORHEN_COURTYARD_LOWER, "Lower Courtyard", "lower");

    locA->addExit(locB);
    EXPECT_EQ(locA->exits["lower"], locB);
}

TEST(LocationTest, AddGlobalExitTest) {
    GameWorld world;
    std::shared_ptr<Location> locA = std::make_shared<Location>(KAER_MORHEN, "Kaer Morhen", "kaermorhen");
    std::shared_ptr<Location> locB = std::make_shared<Location>(KAER_MORHEN_FORTRESS, "Fortress", "fortress");

    locA->addGlobalExit(locB);
    EXPECT_EQ(locA->globalExits["fortress"], locB);
}

TEST(LocationTest, ConnectTest) {
    GameWorld world;
    std::shared_ptr<Location> locA = std::make_shared<Location>(KAER_MORHEN, "Kaer Morhen", "kaermorhen");
    std::shared_ptr<Location> locB = std::make_shared<Location>(KAER_MORHEN_COURTYARD_LOWER, "Lower Courtyard", "lower");

    locA->connect(locB);

    EXPECT_EQ(locA->exits["lower"], locB);
    EXPECT_EQ(locB->exits["kaermorhen"], locA);
}

TEST(WorldTest, CreateWorldTest) {
    GameWorld world;
    std::shared_ptr<Location> startingLocation;

    createWorld(world, startingLocation);

    ASSERT_NE(startingLocation, nullptr);
    EXPECT_EQ(startingLocation->name, "Lower Courtyard");
    EXPECT_EQ(startingLocation->label, "lower");
}

TEST(WorldTest, DisplayLocationTest) {
    GameWorld world;
    std::shared_ptr<Location> loc = std::make_shared<Location>(KAER_MORHEN, "Kaer Morhen", "kaermorhen");

    testing::internal::CaptureStdout();
    displayLocation(loc);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("You are in: Kaer Morhen"), std::string::npos);
}
