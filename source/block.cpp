#include "../include/block.hpp"
#include "../include/resource_manager.hpp"

Block::Block()
{
	this->position = glm::vec2(0, 0);
	this->size = glm::vec2(10, 10);
	this->destroyed = GL_FALSE;
	this->sprite = ResourceManager::getTexture("block");
	this->destroyed = false;
}

Block::Block(
	glm::vec2 pos,
	glm::vec2 size,
	GLuint level,
	GLfloat rot,
	glm::vec2 velocity)
{
	this->position = pos;
	this->size = size;
	this->level = level;
	this->rotation = rot;
	this->velocity = velocity;
	this->destroyed = false;

	if (this->level == 1)
		this->sprite = ResourceManager::getTexture("block_solid");
	else
		this->sprite = ResourceManager::getTexture("block");

	this->color = getColor();
}

void Block::update(GLfloat dt)
{

}

void Block::draw(SpriteRenderer& renderer)
{
	GameObject::draw(renderer);
}

GLboolean Block::isSolid()
{
	return this->level == 1;
}

glm::vec3 Block::getColor()
{
	switch (this->level)
	{
	case 1:
		return glm::vec3(0.8f, 0.8f, 0.7f);
	case 2:
		return glm::vec3(0.2f, 0.6f, 1.0f);
	case 3:
		return glm::vec3(0.0f, 0.7f, 0.0f);
	case 4:
		return glm::vec3(0.8f, 0.8f, 0.4f);
	case 5:
		return glm::vec3(1.0f, 0.5f, 0.0f);
	default:
		return glm::vec3(0.0f, 0.0f, 0.0f);
	}
}