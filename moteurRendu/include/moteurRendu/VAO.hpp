#pragma once
#ifndef __VAO_HPP__
#define __VAO_HPP__

#include <vector>
#include <cstdlib>
#include <GL/glew.h>

class VAO 
{

private:
	GLuint _id;
	const GLuint _VERTEX_POSITION;
	const GLuint _VERTEX_NORMAL;
	const GLuint _VERTEX_TEXTURE;

	
public:
	VAO();

	//VAO(const std::vector<GLuint> &lAttribute);
		// glGenVertexArrays; glBindVertexArray glBufferData;
	~VAO();
		// deleteVertexArrays

	void specifyAttributes() const;
	void debind() const;
	void bind() const;
	void deleteBuf();

};

#endif