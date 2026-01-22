#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	// initialise game objects

	m_snake.setRadius(10);
	m_snake.setFillColor(sf::Color::Yellow);
	m_snake.setPosition({10,10});
	m_last_pressed_direction = Direction::RIGHT;
}

// handle user input
void Level::handleInput(float dt)
{
	/*if (m_input.isLeftMousePressed())
	{
		std::cout << "left mouse pressed" << std::endl;
	}*/

	// movement
	if (m_input.isKeyDown(sf::Keyboard::Scancode::W))
	{
		m_last_pressed_direction = Direction::UP;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::A))
	{
		m_last_pressed_direction = Direction::LEFT;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::S))
	{
		m_last_pressed_direction = Direction::DOWN;
	}
	if (m_input.isKeyDown(sf::Keyboard::Scancode::D))
	{
		m_last_pressed_direction = Direction::RIGHT;
	}

}

// Update game objects
void Level::update(float dt)
{

	// sustained movement
	switch (m_last_pressed_direction)
	{
	case Level::Direction::UP:
		m_snake.move({ 0.0f, -SNAKE_SPEED * dt });
		break;
	case Level::Direction::DOWN:
		m_snake.move({ 0.0f, SNAKE_SPEED * dt });
		break;
	case Level::Direction::LEFT:
		m_snake.move({ -SNAKE_SPEED * dt, 0.0f });
		break;
	case Level::Direction::RIGHT:
		m_snake.move({ SNAKE_SPEED * dt, 0.0f });
		break;
	default:
		break;
	}

	// check for out-of-bounds movement
	sf::Vector2f pos = m_snake.getPosition();
	float radius = m_snake.getRadius();
	sf::Vector2u window_size = m_window.getSize();
	if (pos.x + radius * 2 > window_size.x || pos.x < 0)
	{
		m_snake.setPosition({ window_size.x * 0.5f, window_size.y * 0.5f });
	}
	if (pos.y < 0 || pos.y + radius * 2 > window_size.y)
	{
		m_snake.setPosition({ window_size.x * 0.5f, window_size.y * 0.5f });
	}

}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_snake);
	endDraw();
}

