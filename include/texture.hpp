#pragma once

#include <GL/glew.h>

class Texture2D
{
public:
	GLuint id;
	GLuint width, height;
	GLuint internalFormat;
	GLuint imageFormat;
	GLuint wrapS;
	GLuint wrapT;
	GLuint filterMin;
	GLuint filterMax;

	Texture2D();

	// generate texture from image data
	void generate(GLuint width, GLuint height, unsigned char* data);

	// binds the texture as the current active GL_TEXTURE_2D texture object
	void bind() const;
};