#pragma once

#include <map>
#include <string>

#include <GL/glew.h>

#include "texture.hpp"
#include "shader.hpp"

class ResourceManager
{
public:
	static std::map<std::string, Shader> shaders;
	static std::map<std::string, Texture2D> textures;

	static Shader loadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name);
	static Shader getShader(std::string name);

	static Texture2D loadTexture(const GLchar* textureFile, GLboolean alpha, std::string name);
	static Texture2D getTexture(std::string name);

	// deallocate all loaded resources
	static void clear();

private:
	ResourceManager() {}

	static Shader loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile = nullptr);
	static Texture2D loadTextureFromFile(const GLchar* file, GLboolean alpha);
};