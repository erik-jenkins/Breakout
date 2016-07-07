#include "../include/game.hpp"

#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../include/window.hpp"
#include "../include/resource_manager.hpp"

GameState Game::state = GAME_ACTIVE;

Game::Game(GLuint width, GLuint height)
	: keys(), width(width), height(height)
{}

Game::~Game()
{
	delete player;
	delete renderer;
}

void Game::init()
{
	// set up sprite shader
	ResourceManager::loadShader("shaders/sprite.vert",
		"shaders/sprite.frag", nullptr, "sprite");

	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->width),
		static_cast<GLfloat>(this->height), 0.0f, -1.0f, 1.0f);

	ResourceManager::getShader("sprite").use().setInteger("image", 0);
	ResourceManager::getShader("sprite").setMatrix4f("projection", projection);

	Shader spriteShader = ResourceManager::getShader("sprite");
	renderer = new SpriteRenderer(spriteShader);

	// load textures
	ResourceManager::loadTexture("textures/block.png", GL_FALSE, "block");
	ResourceManager::loadTexture("textures/block_solid.png", GL_FALSE, "block_solid");
	ResourceManager::loadTexture("textures/background.jpg", GL_FALSE, "background");
	ResourceManager::loadTexture("textures/awesome_face.png", GL_TRUE, "awesome_face");
	ResourceManager::loadTexture("textures/paddle.png", GL_TRUE, "paddle");

	// create player
	player = new Player();

	// load levels
	for (int i = 0; i < 4; ++i)
	{
		GameLevel lvl;
		std::string path = "levels/level" + std::to_string(i + 1) + ".lvl";

		lvl.load(path.c_str(), this->width, this->height * 0.5);
		this->levels.push_back(lvl);
	}

	this->currentLevel = 0;
}

void Game::update(GLfloat dt)
{
	this->player->update(dt);
}

void Game::handleInput(GLfloat dt)
{

}

void Game::render()
{
	if (this->state == GAME_ACTIVE)
	{
		// draw background
		Texture2D backgroundTexture = ResourceManager::getTexture("background");
		renderer->drawSprite(backgroundTexture, glm::vec2(0, 0), glm::vec2(this->width, this->height), 0.0f);

		// draw player
		this->player->draw(*renderer);

		// draw level
		this->levels[this->currentLevel].draw(*renderer);
	}
}