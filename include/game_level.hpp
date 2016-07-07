#pragma once

#include <vector>

#include "block.hpp"

class GameLevel
{
public:
	std::vector<Block> blocks;

	GameLevel() {}

	void load(const GLchar* file, GLuint levelWidth, GLuint levelHeight);
	void draw(SpriteRenderer& renderer);
	GLboolean isCompleted();

private:
	void init(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth, GLuint levelHeight);
};