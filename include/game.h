/*
 * File: game.h
 * Authors: Adnan, Hussein & Khaled
 * Date: December 9, 2023
 * Description: Game class header.
 */
#pragma once
#include <SFML/Graphics.hpp>
#include "ghost.h"
#include "vector"
#include <random>

class Game {
    sf::Vector2f playerSpeed;
public:
    Game();
    int run();


private:
    sf::RenderWindow window;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    sf::Texture playerTexture;
    sf::CircleShape player;
    sf::Clock clock;
    sf::Texture ghostTexture;

    static const float SCENE_WIDTH;
    static const float SCENE_HEIGHT;
    static const float PLAYER_START_X;
    static const float PLAYER_START_Y;
    static const float RADIUS;
    static const float SPEED;

    int initWindow();
    int initBackground();
    int initPlayer();
    void processInput();
    void update(sf::Time delta, sf::Shape &player);
    void render();

    Ghost ghost;
    bool isGameOver;

    std::vector<Ghost> ghosts;
    std::mt19937 rng;  // random number generator
    std::uniform_int_distribution<int> dist;  // distribution for random positions
    int maxGhosts;  // maximum number of ghosts
    int spawnRate;  // chance to spawn a new ghost each frame
};