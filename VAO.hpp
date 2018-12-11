#pragma once
#ifndef __VAO_HPP__
#define __VAO_HPP__

class VAO {

private:
	GLuint _id;
	
public:
	VAO();

	VAO(GLuint id);
		// glGenVertexArrays; glBindVertexArray glBufferData;
	~VAO();
		// deleteVertexArrays

	debind();

};

#endif