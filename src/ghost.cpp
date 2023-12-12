/*
 * File: ghost.cpp
 * Authors: Adnan, Hussein & Khaled
 * Date: December 9, 2023
 * Description: Ghost class
 */

#include "Ghost.h"

Ghost::Ghost(float width, float height) {
    if (!texture.loadFromFile("resources/ghost.png")) {
        // handle error...
    }
    sprite.setTexture(texture);
    sprite.setPosition(rand() % (int)(width - sprite.getGlobalBounds().width), rand() % (int)(height - sprite.getGlobalBounds().height));
    velocity = sf::Vector2f((rand() % 3) - 1, (rand() % 3) - 1);

    // Scale the sprite to half its original size
    sprite.setScale(0.2f, 0.2f);
}

Ghost::Ghost(const sf::Texture& texture, float x, float y) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(0.2f, 0.2f);
    velocity = sf::Vector2f((rand() % 3) - 1, (rand() % 3) - 1);
}

void Ghost::update(float width, float height) {
    sf::Vector2f position = sprite.getPosition();
    if (position.x < 0 || position.x > width - sprite.getGlobalBounds().width) velocity.x *= -1;
    if (position.y < 0 || position.y > height - sprite.getGlobalBounds().height) velocity.y *= -1;
    sprite.move(velocity);
}

void Ghost::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Ghost::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}