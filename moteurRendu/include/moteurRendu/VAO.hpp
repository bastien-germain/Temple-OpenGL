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
	GLuint _VERTEX_POSITION;
	GLuint _VERTEX_NORMAL;
	GLuint _VERTEX_TEXTURE;

	
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