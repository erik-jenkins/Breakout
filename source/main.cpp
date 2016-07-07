#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../include/game.hpp"
#include "../include/resource_manager.hpp"
#include "../include/input.hpp"
#include "../include/window.hpp"

// window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

Game breakout(WIDTH, HEIGHT);

int main()
{
	// create window
	Window window(800, 600, "Breakout");

	// init game
	breakout.init();

	// timing
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	// start game within menu state
	breakout.state = GAME_ACTIVE;

	// game loop
	while (!Window::getWindowShouldClose())
	{
		// calculate delta time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glfwPollEvents();

		// handle user input
		breakout.handleInput(deltaTime);
		breakout.update(deltaTime);

		if (Input::isKeyDown(GLFW_KEY_E))
			std::cout << "E key down" << std::endl;

		if (Input::isKeyHeld(GLFW_KEY_E))
			std::cout << "E key held" << std::endl;

		// render
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		breakout.render();

		Window::swapBuffers();
	}

	return 0;
}