/*
 * File: move.cpp
 * Author: Alessandra Gorla
 * Date: November 22, 2023
 * Description: Move module. It offers the functionality to let the player move.
 */

#include "move.h"
const float SPEED = 1.0f; // Define SPEED

Coordinate add(Coordinate a, Coordinate b) {
    Coordinate c = { 0, 0 };
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

Coordinate mul(float s, Coordinate a) {
    Coordinate b = { 0, 0 };
    b.x = s * a.x;
    b.y = s * a.y;
    return b;
}

Coordinate move(const Coordinate &position, const Coordinate &velocity, float timeDelta) {
    // Update the position based on velocity and time delta
    Coordinate newPosition;
    newPosition.x = position.x + velocity.x * timeDelta;
    newPosition.y = position.y + velocity.y * timeDelta;
    return newPosition;
}

void movePlayer(sf::Vector2f &position, sf::Time delta) {
    // Define the player's velocity
    Coordinate velocity = {SPEED, 0.0f}; // Change the velocity as needed

    // Move the player using the move function
    Coordinate newPosition = move({position.x, position.y}, velocity, 0.001f * delta.asMilliseconds());

    // Update the player's position
    position.x = newPosition.x;
    position.y = newPosition.y;
}