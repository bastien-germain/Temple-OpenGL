#pragma once
#ifndef __VBO_HPP__
#define __VBO_HPP__

#include <vector>
#include <cstdlib>
#include <string>

#include <GL/glew.h>

#include "glimac/glm.hpp"
#include "glimac/common.hpp"
#include "glimac/Geometry.hpp"

#include "moteurRendu/VAO.hpp"
#include "moteurRendu/IBO.hpp"
#include "moteurRendu/VBO.hpp"
#include "moteurRendu/Light.hpp"
#include "moteurRendu/Texture.hpp"
#include "moteurRendu/TrackballCamera.hpp"

using namespace glimac;

/// \class VBO
/// \brief Contain the vertices of an object
class VBO 
{

private:
	GLuint _id;
	VAO _vao;
	IBO _ibo;
	Geometry _geo;
	size_t _nbVertices;
	std::vector<glimac::ShapeVertex> _vertices;

	
	
public:
	VBO();
	/// \param vertices: Vector of a structure containing vertex, normal, texture
	//NE sert pas 
	VBO(const std::vector<ShapeVertex> &vertices, const GLuint &id, const size_t size, const uint32_t* indexes, const Geometry g);


	//A utiliser pour afficher les obj
	VBO(const GLuint &id,const Geometry &g);

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

	inline Geometry geometry() const 
	{
		return _geo;
	}

	inline size_t nbVertices() const  
	{
		return _nbVertices;
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