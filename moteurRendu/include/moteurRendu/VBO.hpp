#pragma once
#ifndef __VBO_HPP__
#define __VBO_HPP__

#include "VAO.hpp"
#include "IBO.hpp"
#include <vector>
#include <cstdlib>
#include <GL/glew.h>
#include "glimac/glm.hpp"
#include "glimac/common.hpp"



/// \class VBO
/// \brief Contain the vertices of an object
class VBO 
{

private:
	GLuint _id;
	VAO _vao;
	IBO _ibo;
	size_t _nbVertices;
	std::vector<glimac::ShapeVertex> _vertices;

	
	
public:
	VBO();
	/// \param vertices: Vector of a structure containing vertex, normal, texture
	VBO(const std::vector<glimac::ShapeVertex> &vertices, const GLuint &id, const size_t size, uint32_t* indexes);

	/// \param copied : The VBO to copy into the current object
	VBO(const VBO &copied);
		// glGenBuffers; glBindBuffer; glBufferData; glVertexAttribPointer
	~VBO();
		// deleteBuffers

	/// \brief Allows to bind the buffer array
	void bind() const;

	inline VAO vao() const
	{
		return _vao;
	}

	inline IBO ibo() const
	{
		return _ibo;
	}

	/// \brief  Unbinds the buffer
	void debind() const;

	/// \brief Binds buffer and vertex arrays, specifies the buffer array
	void specifyVAO() const;

	/// \brief Sends the vertices to the GPU
	void sendData() const;

	/// \brief Deletes the buffer array
	void deleteBuf();

	/// \brief Draws the object with triangles
	void draw() const;

private:

};

#endif