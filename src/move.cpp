/*
 * File: move.cpp
 * Authors: Adnan, Hussein & Khaled
 * Date: December 9, 2023
 * Description: Move module. It offers the functionality to let the player move.
 */

#include "move.h"
const float SPEED = 0.0f; // Define SPEED

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

Coordinate move(Coordinate position, Coordinate velocity, float delta) {
    return add(position, mul(delta, velocity));
}

sf::Vector2f movePlayer(sf::Vector2f currentPosition, sf::Time delta, const Velocity &velocity) {
    Coordinate newCoordinate = move({currentPosition.x, currentPosition.y}, {velocity.vx, velocity.vy}, delta.asSeconds());
    return sf::Vector2f(newCoordinate.x, newCoordinate.y);
}