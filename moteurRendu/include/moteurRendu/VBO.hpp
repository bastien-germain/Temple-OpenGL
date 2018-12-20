#pragma once
#ifndef __VBO_HPP__
#define __VBO_HPP__

#include "VAO.hpp"
#include "IBO.hpp"
<<<<<<< HEAD
#include "OBJ.hpp"
=======
#include "VBO.hpp"
>>>>>>> d657ee242a9915666abede95018997f3a19b02a7
#include "Texture.hpp"
#include "TrackballCamera.hpp"
#include <vector>
#include <cstdlib>
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

	VBO(const GLuint &id, const OBJ &obj);
	
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

	/// \brief  Unbinds the buffer
	void debind() const;

	/// \brief Binds buffer and vertex arrays, specifies the buffer array
	void specifyVAO() const;

	/// \brief Sends the vertices to the GPU
	void sendData() const;

	/// \brief Deletes the buffer array
	void deleteBuf() const ;

	void sendLightShader(GLint &uKd, GLint &uKs, GLint &uShininess, GLint &uLightDir_vs, GLint &uLightIntensity, TrackballCamera &track) const;
	

	/// \brief Draws the object with triangles
	void draw() const;

private:

};

#endif