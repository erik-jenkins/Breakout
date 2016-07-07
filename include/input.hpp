#pragma once

#include <map>

class Input
{
public:
	static void handleInput(int key, int action);

	static bool isKeyDown(int key);
	static bool isKeyUp(int key);
	static bool isKeyHeld(int key);

private:
	static std::map<int, bool> keyDown;
	static std::map<int, bool> keyUp;
	static std::map<int, bool> keyHeld;
};