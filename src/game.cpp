/*
 * File: game.cpp
 * Author: Alessandra Gorla
 * Date: November 21, 2023
 * Description: Game class to deal with initialization and controller of 2D my game application.
 */
#include <iostream>
#include "game.h"
#include "move.h"
#include "playermovement.h"


const float Game::SCENE_WIDTH = 800.0f;
const float Game::SCENE_HEIGHT = 600.0f;
const float Game::PLAYER_START_X = 400.0f;
const float Game::PLAYER_START_Y = 300.0f;
const float Game::RADIUS = 40.0f;
const float Game::SPEED = 150.0f;

Game::Game() {
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(1.0f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-1.0f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.move(0.0f, -1.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.move(0.0f, 1.0f);
        }
    }
}

/**
 * Function to update the position of the player
 */
void Game::update(sf::Time delta, sf::Shape &player) {
    // Get the current player position
    sf::Vector2f currentPosition = player.getPosition();

    // Move the player using the movePlayer function
    movePlayer(currentPosition, delta);

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