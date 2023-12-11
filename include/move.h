/*
 * File: move.h
 * Author: Alessandra Gorla
 * Date: November 22, 2023
 * Description: Move header.
 */

#include <SFML/Graphics.hpp>

struct Coordinate {
    float x;
    float y;
};

Coordinate add(Coordinate x, Coordinate y);

Coordinate mul(float s, Coordinate a);

Coordinate move(const Coordinate &position, const Coordinate &velocity, float timeDelta);
void movePlayer(sf::Vector2f &position, sf::Time delta);
