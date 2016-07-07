#include "../include/game_level.hpp"

#include <string>
#include <sstream>
#include <fstream>

#include "../include/resource_manager.hpp"
#include "../include/block.hpp"
#include "../include/texture.hpp"

void GameLevel::load(const GLchar* file, GLuint levelWidth, GLuint levelHeight)
{
	this->blocks.clear();

	GLuint tileCode;
	GameLevel level;

	std::string line;
	std::ifstream fstream(file);
	std::vector<std::vector<GLuint>> tileData;
	if (fstream)
	{
		while (std::getline(fstream, line))
		{

			std::istringstream sstream(line);
			std::vector<GLuint> row;

			while (sstream >> tileCode)
				row.push_back(tileCode);

			tileData.push_back(row);
		}

		if (tileData.size() > 0)
			this->init(tileData, levelWidth, levelHeight);
	}
}

void GameLevel::draw(SpriteRenderer& renderer)
{
	for (Block& block : this->blocks)
		if (!block.destroyed)
			block.draw(renderer);
}

GLboolean GameLevel::isCompleted()
{
	for (Block& block : this->blocks)
		if (!block.isSolid() && !block.destroyed)
			return GL_FALSE;

	return GL_TRUE;
}

void GameLevel::init(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth, GLuint levelHeight)
{
	// calculate dimensions
	GLuint height = tileData.size();
	GLuint width = tileData[0].size();
	GLfloat unitHeight = levelHeight / height;
	GLfloat unitWidth = levelWidth / static_cast<GLfloat>(width);

	// initialize level tiles based on tileData
	for (GLuint y = 0; y < height; y++)
	{
		for (GLuint x = 0; x < width; x++)
		{
			glm::vec2 pos(unitWidth * x, unitHeight * y);
			glm::vec2 size(unitWidth, unitHeight);

			// tileData[y][x] contains the level of the block
			Block block(pos, size, tileData[y][x]);

			// add the new block
			this->blocks.push_back(block);
		}
	}
}