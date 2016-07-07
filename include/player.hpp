#pragma once

#include <glm/glm.hpp>

#include "game_object.hpp"

class Player : public GameObject
{
public:
	GLfloat paddleSpeed;

	Player();
	Player(
		glm::vec2 pos,
		glm::vec2 size,
		Texture2D sprite,
		glm::vec3 color = glm::vec3(1.0f),
		GLfloat rot = 0.0f,
		glm::vec2 velocity = glm::vec2(0.0f, 0.0f),
		GLfloat paddleSpeed = 500.0f
	);
	
	void update(GLfloat dt);
	void draw(SpriteRenderer& renderer);
};