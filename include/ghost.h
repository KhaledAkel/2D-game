/*
 * File: ghost.h
 * Authors: Adnan, Hussein & Khaled
 * Date: December 9, 2023
 * Description: Ghost class header.
 */

#pragma once
#include <SFML/Graphics.hpp>

class Ghost {
public:
    Ghost(float width, float height);
    Ghost(const sf::Texture& texture, float x, float y);
    void update(float width, float height);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds() const;  // Add this line
    sf::Sprite& getSprite() {
        return sprite;
    }

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
};