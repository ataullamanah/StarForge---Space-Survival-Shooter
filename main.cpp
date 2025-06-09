#include <SFML/Graphics.hpp>
#include <iostream>

// Game constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float PLAYER_SPEED = 200.0f; // Pixels per second

// Player class to handle ship properties and behavior
class Player {
private:
    sf::RectangleShape shape; // Temporary shape for the player (replace with sprite later)
    sf::Vector2f velocity;

public:
    Player() {
        // Initialize player shape (a simple rectangle for now)
        shape.setSize(sf::Vector2f(40.0f, 40.0f));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);
        velocity = sf::Vector2f(0.0f, 0.0f);
    }

    // Update player position based on input and delta time
    void update(float deltaTime, sf::RenderWindow& window) {
        velocity = sf::Vector2f(0.0f, 0.0f);

        // Handle keyboard input for movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            velocity.y -= PLAYER_SPEED;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            velocity.y += PLAYER_SPEED;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            velocity.x -= PLAYER_SPEED;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocity.x += PLAYER_SPEED;
        }

        // Move the player
        shape.move(velocity * deltaTime);

        // Keep player within window bounds
        sf::Vector2f pos = shape.getPosition();
        if (pos.x < 0) shape.setPosition(0, pos.y);
        if (pos.x > WINDOW_WIDTH - shape.getSize().x) shape.setPosition(WINDOW_WIDTH - shape.getSize().x, pos.y);
        if (pos.y < 0) shape.setPosition(pos.x, 0);
        if (pos.y > WINDOW_HEIGHT - shape.getSize().y) shape.setPosition(pos.x, WINDOW_HEIGHT - shape.getSize().y);
    }

    // Draw the player
    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
};

int main() {
    // Create the game window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "StarForge - Space Survival Shooter");
    window.setFramerateLimit(60);

    // Create the player
    Player player;

    // Clock for calculating delta time
    sf::Clock clock;

    // Main game loop
    while (window.isOpen()) {
        // Calculate delta time
        float deltaTime = clock.restart().asSeconds();

        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Update game state
        player.update(deltaTime, window);

        // Render
        window.clear(sf::Color::Black); // Space background
        player.draw(window);
        window.display();
    }

    return 0;
}
