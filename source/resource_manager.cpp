#include "../include/resource_manager.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

#include <SOIL.h>

std::map<std::string, Shader> ResourceManager::shaders;
std::map<std::string, Texture2D> ResourceManager::textures;

Shader ResourceManager::loadShader(const GLchar* vShaderFile, const GLchar* fShaderFile,
	const GLchar* gShaderFile, std::string name)
{
	shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
	return shaders[name];
}

Shader ResourceManager::getShader(std::string name)
{
	return shaders[name];
}

Texture2D ResourceManager::loadTexture(const GLchar* file, GLboolean alpha, std::string name)
{
	textures[name] = loadTextureFromFile(file, alpha);
	return textures[name];
}

Texture2D ResourceManager::getTexture(std::string name)
{
	return textures[name];
}

void ResourceManager::clear()
{
	for (auto iter : shaders)
		glDeleteProgram(iter.second.id);

	for (auto iter : textures)
		glDeleteTextures(1, &iter.second.id);
}

Shader ResourceManager::loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile)
{
	// retrieve shader source code from path
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;

	try
	{
		// open files
		std::ifstream vertexShaderFile(vShaderFile);
		std::ifstream fragmentShaderFile(fShaderFile);
		std::stringstream vShaderStream, fShaderStream;

		// read file's buffer contents into streams
		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();

		// close files
		vertexShaderFile.close();
		fragmentShaderFile.close();

		// convert stream to string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

		// repeat for geometry shader if present
		if (gShaderFile != nullptr)
		{
			std::ifstream geometryShaderFile(gShaderFile);
			std::stringstream gShaderStream;
			gShaderStream << geometryShaderFile.rdbuf();
			geometryShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}
	catch (std::exception e)
	{
		std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
	}

	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();
	const GLchar* gShaderCode = geometryCode.c_str();

	// create shader object from source code
	Shader shader;
	shader.compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
	return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const GLchar* file, GLboolean alpha)
{
	Texture2D texture;
	if (alpha)
	{
		texture.internalFormat = GL_RGBA;
		texture.imageFormat = GL_RGBA;
	}

	// load image
	int width, height;
	unsigned char* image = SOIL_load_image(file, &width, &height, 0,
		texture.imageFormat == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
	texture.generate(width, height, image);
	SOIL_free_image_data(image);
	return texture;
}