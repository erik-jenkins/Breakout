#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "texture.hpp"
#include "sprite_renderer.hpp"

class GameObject
{
public:
	GLboolean destroyed;
	glm::vec2 position, size, velocity;
	glm::vec3 color;
	GLfloat rotation;
	Texture2D sprite;

	GameObject();
	GameObject(
		glm::vec2 pos,
		glm::vec2 size,
		Texture2D sprite,
		glm::vec3 color = glm::vec3(1.0f),
		GLfloat rot = 0.0f,
		glm::vec2 velocity = glm::vec2(0.0f, 0.0f)
	);

	virtual void update(GLfloat dt) = 0;
	virtual void draw(SpriteRenderer &renderer);
};