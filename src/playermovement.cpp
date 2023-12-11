//
// Created by Hussein Soliman on 11/12/2023.
//

// player_movement.cpp
// player_movement.cpp
#include "playermovement.h"

sf::Vector2f movePlayer(sf::Vector2f current_position, float speed) {
    current_position.x += speed;
    return current_position;
}