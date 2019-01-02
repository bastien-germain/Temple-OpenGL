#pragma once
#ifndef __VAO_HPP__
#define __VAO_HPP__

#include <vector>
#include <cstdlib>
#include <iostream>

#include <GL/glew.h>

/// \class VAO
/// \brief Specifies the buffer array of the class VBO
class VAO 
{

private:
	GLuint _id;
	GLuint _VERTEX_POSITION;
	GLuint _VERTEX_NORMAL;
	GLuint _VERTEX_TEXTURE;

	
public:
	VAO();
	VAO(const GLuint &id);
	~VAO();

	/// \brief Gives spefications for the buffer
	void specifyAttributes() const;


	void debind() const;
	void bind() const;
	void deleteBuf() const;

};

#endif