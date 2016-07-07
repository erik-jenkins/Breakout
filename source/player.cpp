#include "../include/player.hpp"

#include "../include/input.hpp"
#include "../include/window.hpp"
#include "../include/resource_manager.hpp"

Player::Player() : GameObject()
{
	this->position = glm::vec2(
		(Window::width - size.x)/2,
		(Window::height - size.y)
	);

	this->size = glm::vec2(100, 20);
	this->sprite = ResourceManager::getTexture("paddle");
	this->color = glm::vec3(0.0f);
	this->rotation = 0.0f;
	this->velocity = glm::vec2(0.0f);
	this->paddleSpeed = 500.0f;
}

Player::Player(
	glm::vec2 pos,
	glm::vec2 size,
	Texture2D sprite,
	glm::vec3 color,
	GLfloat rot,
	glm::vec2 velocity,
	GLfloat paddleSpeed
) : GameObject(pos, size, sprite, color, rot, velocity), paddleSpeed(paddleSpeed)
{}

void Player::update(GLfloat dt)
{}

void Player::draw(SpriteRenderer& renderer)
{
	GameObject::draw(renderer);
}