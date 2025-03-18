#include <gtest/gtest.h>

int dodaj(int a, int b) {
    return a + b;
}

TEST(DodajTest, PozytywneLiczby) {
    EXPECT_EQ(dodaj(2, 3), 5);
}

TEST(DodajTest, NegatywneLiczby) {
    EXPECT_EQ(dodaj(-2, -3), -5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
