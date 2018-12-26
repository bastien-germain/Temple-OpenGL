#pragma once
#ifndef __VBO_HPP__
#define __VBO_HPP__

#include "VAO.hpp"
#include "IBO.hpp"
#include "VBO.hpp"
#include "Light.hpp"
#include "Texture.hpp"
#include "TrackballCamera.hpp"
#include <vector>
#include <cstdlib>
#include <string>
#include <GL/glew.h>
#include "glimac/glm.hpp"
#include "glimac/common.hpp"
#include "glimac/Geometry.hpp"

/// \class VBO
/// \brief Contain the vertices of an object
class VBO 
{

private:
	GLuint _id;
	VAO _vao;
	IBO _ibo;
	glimac::Geometry _geo;
	size_t _nbVertices;
	std::vector<glimac::ShapeVertex> _vertices;

	
	
public:
	VBO();
	/// \param vertices: Vector of a structure containing vertex, normal, texture
	//NE sert pas 
	VBO(const std::vector<glimac::ShapeVertex> &vertices, const GLuint &id, const size_t size, const uint32_t* indexes, const glimac::Geometry g);


	//A utiliser pour afficher les obj
	VBO(const GLuint &id,const glimac::Geometry &g);

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

	inline glimac::Geometry geometry() const {
		return _geo;
	}

	/// \brief  Unbinds the buffer
	void debind() const;

	/// \brief Binds buffer and vertex arrays, specifies the buffer array
	void specifyVAO() const;

	/// \brief Sends the vertices to the GPU
	void sendData() const;

	/// \brief Deletes the buffer array
	void deleteBuf() const ;

	/// \brief Draws the object with triangles
	void draw() const;

private:

};

#endif