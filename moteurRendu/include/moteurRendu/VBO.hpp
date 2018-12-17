#pragma once
#ifndef __VBO_HPP__
#define __VBO_HPP__

#include "VAO.hpp"
#include <vector>
#include <cstdlib>
#include <GL/glew.h>
#include "glimac/glm.hpp"
#include "glimac/common.hpp"




class VBO 
{

private:
	GLuint _id;
	VAO _vao;
	size_t _nbVertices;
	std::vector<glimac::ShapeVertex> _vertices;
	
	
public:
	VBO();
	
	VBO(const std::vector<glimac::ShapeVertex> &vertices);
		// glGenBuffers; glBindBuffer; glBufferData; glVertexAttribPointer
	~VBO();
		// deleteBuffers

	void bind() const;
	void debind() const;
	void specifyVAO() const;
	void sendData() const;
	void deleteBuf();

};

#endif