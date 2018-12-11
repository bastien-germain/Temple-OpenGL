#pragma once
#ifndef __VBO_HPP__
#define __VBO_HPP__

#include "VAO.hpp"

class VBO 
{

private:
	GLuint _id;
	VAO _vao;
	size_t _nbSommets;
	
public:
	VBO();
	// On passe un vetceur de point (3c oord)
	VBO(GLuint id, std::vector<glm::vec3> points);
		// glGenBuffers; glBindBuffer; glBufferData; glVertexAttribPointer
	~VBO();
		// deleteBuffers

};

#endif