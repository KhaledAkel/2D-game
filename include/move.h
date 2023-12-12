/*
 * File: move.h
 * Authors: Adnan, Hussein & Khaled
 * Date: December 9, 2023
 * Description: Move header.
 */

#include <SFML/Graphics.hpp>

struct Coordinate {
    float x;
    float y;
};

struct Velocity {
    float vx;
    float vy;
};

Coordinate add(Coordinate x, Coordinate y);

Coordinate mul(float s, Coordinate a);

Coordinate move(Coordinate position, Coordinate velocity, float delta);

sf::Vector2f movePlayer(sf::Vector2f currentPosition, sf::Time delta, const Velocity &velocity);