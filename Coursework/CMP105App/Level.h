#pragma once

#include "Framework/BaseLevel.h"

class Level : BaseLevel{
public:
	enum class Direction { UP, DOWN, LEFT, RIGHT };

	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.

	// Default variables for level class.
	sf::CircleShape m_snake;
	Direction m_last_pressed_direction;
	float const SNAKE_SPEED = 150.0f;
};