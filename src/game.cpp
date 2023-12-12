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
const float Game::SPEED = 150.0f;

Game::Game() : window(sf::VideoMode(1200, 800), "2D Game"), playerSpeed(0.0f, 0.0f){
    initWindow();
    initBackground();
    initPlayer();
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
    if (currentPosition.x < 0) currentPosition.x = 0;
    if (currentPosition.y < 0) currentPosition.y = 0;
    if (currentPosition.x > window.getSize().x) currentPosition.x = window.getSize().x;
    if (currentPosition.y > window.getSize().y) currentPosition.y = window.getSize().y;

    // Set the new position of the player
    player.setPosition(currentPosition);
}


/**
 * Render elements in the window
 */
void Game::render() {
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(player);
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