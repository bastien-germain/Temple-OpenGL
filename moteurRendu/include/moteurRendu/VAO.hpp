#pragma once
#ifndef __VAO_HPP__
#define __VAO_HPP__

#include <vector>
#include <cstdlib>
#include <GL/glew.h>
#include <iostream>

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
<<<<<<< HEAD
	VAO(const GLuint id);
=======
	VAO(const GLuint &id);
>>>>>>> f376191bbe1c06e3e090b8d8aa06d8d15cd183dd
	~VAO();

	/// \brief Gives spefications for the buffer
	void specifyAttributes() const;


	void debind() const;
	void bind() const;
	void deleteBuf();

};

#endif