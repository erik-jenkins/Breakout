#include "../include/input.hpp"

#include <GLFW/glfw3.h>

void Input::handleInput(int key, int action)
{
	// reset pressed and released keys
	keyDown.clear();
	keyUp.clear();

	// if a key has been pressed
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		if (action != GLFW_REPEAT)
			keyDown[key] = true;

		keyHeld[key] = true;
	}

	// if a key has been released
	if (action == GLFW_RELEASE)
	{
		keyUp[key] = true;
		keyHeld[key] = false;
	}
}

bool Input::isKeyDown(int key)
{
	return keyDown[key];
}

bool Input::isKeyUp(int key)
{
	return keyUp[key];
}

bool Input::isKeyHeld(int key)
{
	return keyHeld[key];
}

std::map<int, bool> Input::keyDown;
std::map<int, bool> Input::keyUp;
std::map<int, bool> Input::keyHeld;