////
//// Created by Hussein Soliman on 12/12/2023.
////

#include "gtest/gtest.h"
#include "move.h"

TEST(CoordinateTest, Add) {
    Coordinate a = {1.0f, 2.0f};
    Coordinate b = {3.0f, 4.0f};
    Coordinate result = add(a, b);
    EXPECT_FLOAT_EQ(result.x, 4.0f);
    EXPECT_FLOAT_EQ(result.y, 6.0f);
}

TEST(CoordinateTest, Multiply) {
    Coordinate a = {2.0f, 3.0f};
    float s = 1.5f;
    Coordinate result = mul(s, a);
    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 4.5f);
}

TEST(CoordinateTest, Move) {
    Coordinate position = {1.0f, 2.0f};
    Coordinate velocity = {3.0f, 4.0f};
    float delta = 0.5f;
    Coordinate result = move(position, velocity, delta);
    EXPECT_FLOAT_EQ(result.x, 2.5f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST(MovePlayerTest, MovePlayer) {
    sf::Vector2f currentPosition = {1.0f, 2.0f};
    Velocity velocity = {3.0f, 4.0f};
    sf::Time delta = sf::seconds(0.5f);
    sf::Vector2f result = movePlayer(currentPosition, delta, velocity);
    EXPECT_FLOAT_EQ(result.x, 2.5f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST(MovePlayerTest, MovePlayer_ZeroVelocity) {
    sf::Vector2f currentPosition = {1.0f, 2.0f};
    Velocity velocity = {0.0f, 0.0f};
    sf::Time delta = sf::seconds(0.5f);
    sf::Vector2f result = movePlayer(currentPosition, delta, velocity);
    EXPECT_FLOAT_EQ(result.x, 1.0f);
    EXPECT_FLOAT_EQ(result.y, 2.0f);
}

TEST(MovePlayerTest, MovePlayer_LargeDeltaTime) {
    sf::Vector2f currentPosition = {1.0f, 2.0f};
    Velocity velocity = {3.0f, 4.0f};
    sf::Time delta = sf::seconds(5.0f);
    sf::Vector2f result = movePlayer(currentPosition, delta, velocity);
    // Expect the position to change significantly with a large delta time
    EXPECT_FLOAT_EQ(result.x, 16.0f);
    EXPECT_FLOAT_EQ(result.y, 22.0f);
}

TEST(MovePlayerTest, MovePlayer_NegativeVelocity) {
    sf::Vector2f currentPosition = {1.0f, 2.0f};
    Velocity velocity = {-3.0f, -4.0f};
    sf::Time delta = sf::seconds(0.5f);
    sf::Vector2f result = movePlayer(currentPosition, delta, velocity);
    // Expect the position to move in the opposite direction with negative velocity
    EXPECT_FLOAT_EQ(result.x, -0.5f);
    EXPECT_FLOAT_EQ(result.y, 0.0f);
}

