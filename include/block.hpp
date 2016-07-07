#pragma once

#include <glm/glm.hpp>

#include "game_object.hpp"

class Block : public GameObject
{
public:

	// level: determines level of block
	// level = 1: solid
	// level = 2: one   hit to destroy
	// level = 3: two   """ "" """""""
	// level = 4: three """ "" """""""
	// level = 5: four  """ "" """""""
	GLuint level;

	Block();
	Block(
		glm::vec2 pos,
		glm::vec2 size,
		GLuint level,
		GLfloat rot = 0.0f,
		glm::vec2 velocity = glm::vec2(0.0f, 0.0f)
	);

	void update(GLfloat dt);
	void draw(SpriteRenderer& renderer);

	// convenience method to determine if block is solid
	GLboolean isSolid();

private:
	// gets the color of the block based on the block's level
	glm::vec3 getColor();
};