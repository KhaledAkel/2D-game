# The Pacman Survival Game

By Adnan, Hussein & Khaled

Welcome to the 2D Pacman game implementation! This project was developed to fulfill a series of tasks assigned for an assignment. The instructions for the assignment included the following key tasks:

## 1. Assignment Tasks:
* Task 1: Player Movement
Make the player move with arrow controls, ensuring the player does not move outside the boundaries of the scene.

* Task 2: Introduce Ghosts
Implement a new shape (e.g., a ghost) that appears in the space. The ghost should move randomly within the scene boundaries without any keyboard control.

* Task 3: Collision Interaction
Define an interaction when the player and shape(s) collide. Ensure that the shape (ghost) disappears upon collision.

* Task 4: Dynamic Ghost Spawning
Instead of a single instance of the ghost, introduce a random number of ghosts, with a maximum set in the configuration. The ghosts should appear at random times and coordinates.

* Task 5: Testing
Add test cases to the project during implementation, aiming for high coverage and meaningful tests.

Bonus Points: Additional Features
Implement any other feature that comes to mind, earning bonus points for creativity and extra functionality.

## 2. Dependencies
This project depends on the [SFML library](https://www.sfml-dev.org/index.php). SFML can be installed via apt on Linux, brew on MacOS  

## 3. Setup 
Welcome to our 2D Pacman game implementation! To get started with this exciting game, follow these simple installation steps. First, clone the repository to your local machine using the following command:

```git clone <repository_url>```

Next, ensure you have SFML installed on your system. If you don't have it installed, you can download it from the official website or use a package manager.

Now, since we developed this project using CLion as our preferred C++ IDE, it is suggested that you open the project in CLion. Once the project is loaded, you can build it using the built-in tools provided by CLion.

That's it! You are now ready to explore our 2D Pacman game. Enjoy the classic experience of controlling Pacman with arrow keys, dodging randomly moving ghosts, and mastering the art of survival in our dynamic gaming environment.

The provided code is a simple 2D game implemented in C++ using the SFML library. Let's break down the components and understand the game's overview, rules, and objectives.

## 4. Game Rules and Objectives:

### Objective:
The game window opens with a Pacman character in a scene filled with ghosts. The player can control Pacman's movement using the arrow keys. The objective is to avoid colliding with the ghosts for as long as possible. The game ends when Pacman collides with a ghost, and a "Game Over!" message is displayed.

Survival: The primary objective of the game is for the player to survive as long as possible without colliding with any ghosts.

### Game Elements:
1.⁠ ⁠*Player (Pac-Man Character):*
* Represented as a sprite.
* Controlled by arrow keys (Up, Down, Left, Right) through the ⁠ processInput() ⁠ method.
* BONUS FEATURE: Player wraps around the screen edges, appearing on the opposite side when reaching the boundary.

2.⁠ ⁠*Ghosts:*
* Ghosts are represented by instances of the ⁠Ghost ⁠ class.
* Initially spawned at random positions within the game window.
* Move randomly with bouncing behavior when reaching screen edges.
* Occasionally, a new ghost is spawned with a certain probability (⁠ spawnRate ⁠).

3.⁠ ⁠*Collision Detection:*
* Collision between the player and ghosts is checked using bounding rectangles (⁠ getGlobalBounds() ⁠ method).
* If the player collides with any ghost, the game ends.

4.⁠ ⁠*Game Over:*
* When a collision occurs, the game sets the  isGameOver  ⁠flag to true.
* The game loop (⁠ run() ⁠) detects the game over condition and displays a "Game Over" message on the screen.

*Scoring and Progression:*
 The game does not have explicit scoring or levels but the player's performance is measured by the duration of survival and we are planning (for future reference) on putting a timer aspect and keeping track of high scores.

### Additional Game Features:
 1.⁠ ⁠*Background:*
    - The game has a background image loaded from "resources/background.png".
    The background is displayed behind the player and ghosts.

 2.⁠ ⁠*Ghost Textures:*
    - Ghosts use a texture loaded from "resources/ghost.png".
    The texture is applied to the ghost sprites for visual representation.

 3.⁠ ⁠*Player Texture:*
    - The player uses a texture loaded from "resources/pacman.png".

 4.⁠ ⁠*Randomization:*
    - Randomization is utilized for ghost positions, initial velocities, and the decision to spawn new ghosts.
    The ⁠ std::mt19937 ⁠ random number generator and ⁠ std::uniform_int_distribution<int> ⁠ distribution are used.

### Game Flow:
 1.⁠ ⁠*Initialization:*
* The game initializes the window, background, player, and a single ghost (⁠ Ghost ghost ⁠).
* Ghosts vector (⁠ std::vector<Ghost> ghosts ⁠) is initialized to store multiple ghosts.

 2.⁠ ⁠*Game Loop (⁠ run() ⁠):*
* The main game loop manages input, updates, and rendering.
* Input is processed through the ⁠ processInput() ⁠ method, updating the player's speed.
* The player's position is updated based on the velocity and screen boundaries.

 3.⁠ ⁠*Ghost Spawning:*
A new ghost is occasionally spawned with a probability defined by ⁠ spawnRate ⁠.

 4.⁠ ⁠*Collision Detection:*
The game checks for collisions between the player and the initial ghost, as well as between the player and any spawned ghosts.

 5.⁠ ⁠*Game Over Handling:*
If a collision occurs, the ⁠ isGameOver ⁠ flag is set to true, triggering the display of the "Game Over" message.

 6.⁠ ⁠*Rendering:*
The game renders the background, player, ghosts, and the "Game Over" message if applicable.

 7.⁠ ⁠*Termination:*
* The game continues until the player closes the window.
* Upon termination, the program returns 0.



## 5. Game Structure

### Game Class (game.h, game.cpp)
The Game class is responsible for managing the game's main loop, window, player movement, ghost spawning, and collision detection.

Attributes:

* sf::RenderWindow window: The game window.
* sf::Sprite background: Background sprite.
* sf::Texture backgroundTexture: Texture for the background.
* sf::Texture playerTexture: Texture for the player (Pacman).
* sf::CircleShape player: Pacman's shape.
* sf::Clock clock: Game clock.
* sf::Texture ghostTexture: Texture for the ghosts.
* sf::Vector2f playerSpeed: Pacman's movement speed.
* Ghost ghost: An instance of the Ghost class representing a single ghost.
* std::vector<Ghost> ghosts: Vector to store multiple ghosts.
* std::mt19937 rng: Random number generator.
* std::uniform_int_distribution<int> dist: Distribution for random positions.
* int maxGhosts: Maximum number of ghosts allowed.
* int spawnRate: Chance to spawn a new ghost each frame.
* bool isGameOver: Flag indicating whether the game is over.

Methods:

* Game(): Constructor for the Game class.
* int run(): Main game loop.
* int initWindow(): Initializes the game window.
* int initBackground(): Initializes the background.
* int initPlayer(): Initializes the player (Pacman).
* void processInput(): Handles user input.
* void update(sf::Time delta, sf::Shape &player): Updates the game state.
* void render(): Renders the game elements.

### Ghost Class (ghost.h, ghost.cpp)
The Ghost class represents the ghost characters in the game. It includes methods for updating their positions, drawing them on the window, and getting their global bounds for collision detection.

Attributes:

* sf::Sprite sprite: Ghost sprite.
* sf::Texture texture: Texture for the ghost.
* sf::Vector2f velocity: Velocity of the ghost.

Methods:

* Ghost(float width, float height): Constructor for the Ghost class.
* Ghost(const sf::Texture& texture, float x, float y): Constructor with explicit position.
* void update(float width, float height): Updates the ghost's position and behavior.
* void draw(sf::RenderWindow& window): Draws the ghost on the window.
* sf::FloatRect getGlobalBounds() const: Returns the global bounding rectangle of the ghost


Move Module (move.h, move.cpp)
The move module file contains utility functions for handling 2D coordinate operations and player movement.

Functions:

* Coordinate add(Coordinate x, Coordinate y): Adds two coordinates.
* Coordinate mul(float s, Coordinate a): Multiplies a coordinate by a scalar.
* Coordinate move(Coordinate position, Coordinate velocity, float delta): Moves a position based on velocity and delta.
* sf::Vector2f movePlayer(sf::Vector2f currentPosition, sf::Time delta, const Velocity &velocity): Moves the player based on velocity and delta.

## 6. Google Tests
The project includes Google Tests for unit testing, these are included under the file name googletest.cpp and can be run directly from CLion. The following are the tests we conducted and what they are for:

1.⁠ ⁠*CoordinateTest - Add:*
* This test is checking the functionality of the ⁠ add ⁠ function in the ⁠ move.h ⁠ file.
* It creates two ⁠ Coordinate ⁠ objects, ⁠ a ⁠ and ⁠ b ⁠, and adds them using the ⁠ add ⁠ function.
* The expected result is that the resulting coordinates have their components added correctly.

 2.⁠ ⁠*CoordinateTest - Multiply:*
* This test is checking the functionality of the ⁠ mul ⁠ (multiply) function in the ⁠ move.h ⁠ file.
* It creates a ⁠ Coordinate ⁠ object ⁠ a ⁠ and a scalar ⁠ s ⁠ and multiplies them using the ⁠ mul ⁠ function.
* The expected result is that the resulting coordinates have their components multiplied by the scalar.

 3.⁠ ⁠*CoordinateTest - Move:*
* This test is checking the functionality of the ⁠ move ⁠ function in the ⁠ move.h ⁠ file.
* It then moves the position using the ⁠ move ⁠ function based on the velocity and delta.
* The expected result is that the resulting coordinates represent the new position after the movement.

 4.⁠ ⁠*MovePlayerTest - MovePlayer:*
* This test is checking the functionality of the ⁠ movePlayer ⁠ function in the ⁠ move.h ⁠ file.
* It then moves the player's position using the ⁠ movePlayer ⁠ function based on the velocity and delta.
* The expected result is that the resulting position represents the new position after the movement.

 5.⁠ ⁠*MovePlayerTest - MovePlayer_ZeroVelocity:*
* This test is checking the behavior of the ⁠ movePlayer ⁠ function when the velocity is zero.
* It checks whether the player's position remains unchanged when the velocity is zero.

 6.⁠ ⁠*MovePlayerTest - MovePlayer_LargeDeltaTime:*
* This test is checking the behavior of the ⁠ movePlayer ⁠ function when a large delta time is provided.
* It checks whether the player's position changes significantly with a large delta time.

 7.⁠ ⁠*MovePlayerTest - MovePlayer_NegativeVelocity:*
* This test is checking the behavior of the ⁠ movePlayer ⁠ function when the velocity is negative.
* It checks whether the player's position moves in the opposite direction with a negative velocity.
