/*
 * File: game.cpp
 * Authors: Adnan, Hussein & Khaled
 * Date: December 9, 2023
 * Description: Game class to deal with initialization and controller of 2D my game application.
 */

#include <iostream>
#include <cstdlib>
#include "game.h"
#include "move.h"


const float Game::SCENE_WIDTH = 1200.0f;
const float Game::SCENE_HEIGHT = 800.0f;
const float Game::PLAYER_START_X = 600.0f;
const float Game::PLAYER_START_Y = 400.0f;
const float Game::RADIUS = 40.0f;


Game::Game() : window(sf::VideoMode(1200, 800), "2D Game"), playerSpeed(0.0f, 0.0f), ghost(window.getSize().x, window.getSize().y),  isGameOver(false), player(50, 50), rng(std::time(nullptr)), dist(0, 800), maxGhosts(20), spawnRate(2){
    initWindow();
    initBackground();
    initPlayer();
    ghost.update(window.getSize().x, window.getSize().y);
    if (player.getGlobalBounds().intersects(ghost.getGlobalBounds())) {
        isGameOver = true;
    }
    // Load the ghost texture
    if (!ghostTexture.loadFromFile("resources/ghost.png")) {
        std::cerr << "Failed to load ghost texture\n";
        exit(1);
    }
}

/**
 * Window initializer.
 */
int Game::initWindow() {
    window.create(sf::VideoMode(SCENE_WIDTH, SCENE_HEIGHT), "My 2D game");
    window.setFramerateLimit(120);
    return 0;
}
/**
 * Background initializer.
 */
int Game::initBackground() {
    if (!backgroundTexture.loadFromFile("resources/background.png")) {
        return 1;
    }
    backgroundTexture.setRepeated(true);
    background.setTexture(backgroundTexture);
    background.setTextureRect(sf::IntRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT));
    return 0;
}

/**
 * Player (e.g. PacMan) initializer
 * @return 0 if successfully initialized, 1 otherwise
 */
int Game::initPlayer() {
    player.setRadius(RADIUS);
    player.setOrigin(RADIUS, RADIUS);
    player.setPosition(PLAYER_START_X, PLAYER_START_Y);
    if (!playerTexture.loadFromFile("resources/pacman.png")) {
        return 1;
    }
    player.setTexture(&playerTexture);
    return 0;
}

/**
 * Dealing with events on window.
 */
void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right) {
                playerSpeed.x = 2.0f;
            }
            if (event.key.code == sf::Keyboard::Left) {
                playerSpeed.x = -2.0f;
            }
            if (event.key.code == sf::Keyboard::Up) {
                playerSpeed.y = -2.0f;
            }
            if (event.key.code == sf::Keyboard::Down) {
                playerSpeed.y = 2.0f;
            }
        }
        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Left) {
                playerSpeed.x = 0.0f;
            }
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down) {
                playerSpeed.y = 0.0f;
            }
        }
    }
    player.move(playerSpeed);
}

/**
 * Function to update the position of the player
 */
void Game::update(sf::Time delta, sf::Shape &player) {
    // Get the current player position
    sf::Vector2f currentPosition = player.getPosition();

    Velocity playerVelocity = {playerSpeed.x, playerSpeed.y};
    currentPosition = movePlayer(currentPosition, delta, playerVelocity);

    // Check boundaries
    if (currentPosition.x < 0) currentPosition.x = window.getSize().x;
    if (currentPosition.y < 0) currentPosition.y = window.getSize().y;
    if (currentPosition.x > window.getSize().x) currentPosition.x = 0;
    if (currentPosition.y > window.getSize().y) currentPosition.y = 0;

    // Set the new position of the player
    player.setPosition(currentPosition);

    ghost.update(window.getSize().x, window.getSize().y);
    if (player.getGlobalBounds().intersects(ghost.getGlobalBounds())) {
        isGameOver = true;
    }
    // Occasionally spawn a new ghost
    if (ghosts.size() < maxGhosts && dist(rng) < spawnRate) {
        ghosts.push_back(Ghost(ghostTexture, dist(rng), dist(rng)));
    }

    // Update and check for collisions with each ghost
    for (Ghost& ghost : ghosts) {
        ghost.update(window.getSize().x, window.getSize().y);
        if (player.getGlobalBounds().intersects(ghost.getGlobalBounds())) {
            isGameOver = true;
        }
    }
}


/**
 * Render elements in the window
 */
void Game::render() {
    window.clear();
    if (isGameOver) {
        sf::Text text;
        sf::Font font;
        if (!font.loadFromFile("/Users/husseinsoliman/Documents/GitHub/2D-game/src/Arial.ttf")) {
            std::cerr << "Failed to load font from file 'arial.ttf'\n";
            exit(1);
        }
        text.setFont(font);
        text.setString("Game Over!");
        text.setCharacterSize(54);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
        text.setPosition(sf::Vector2f(window.getSize().x/2.0f,window.getSize().y/2.0f));
        window.draw(text);
    } else {
        window.clear(sf::Color::White);
        window.draw(background);
        window.draw(player);
        ghost.draw(window);
        for (Ghost& ghost : ghosts) {
            ghost.draw(window);
        }
    }
    window.display();
}
/**
 * Main function to deal with events, update the player and render the updated scene on the window.
 */
int Game::run() {
    while (window.isOpen()) {
        sf::Time delta = clock.restart();
        processInput();
        update(delta, player);
        render();
    }
    return 0;
}