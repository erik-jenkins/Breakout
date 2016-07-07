#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "game_level.hpp"
#include "player.hpp"

// current game state
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

// holds all game-related state and functionality
class Game
{
public:
	static GameState state;
	GLboolean keys[1024];
	Player* player;
	GLuint width, height;
	std::vector<GameLevel> levels;
	GLuint currentLevel;

	Game(GLuint width, GLuint height);
	~Game();

	void init();

	void handleInput(GLfloat dt);
	void update(GLfloat dt);
	void render();

private:
	SpriteRenderer* renderer;
};