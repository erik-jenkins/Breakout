#include "../include/game_object.hpp"

GameObject::GameObject()
	: position(0, 0), size(1, 1), velocity(0.0f), color(1.0f),
	rotation(0.0f), destroyed(false), sprite()
{}

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, 
	glm::vec3 color, GLfloat rot, glm::vec2 vel)
	: position(pos), size(size), rotation(rot), velocity(vel), color(color), 
	  destroyed(false), sprite(sprite)
{}

void GameObject::draw(SpriteRenderer& renderer)
{
	renderer.drawSprite(this->sprite, this->position, this->size, this->rotation, this->color);
}