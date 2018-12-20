#pragma once
#ifndef __IBO_HPP__
#define __IBO_HPP__


#include <vector>
#include <cstdlib>
#include <GL/glew.h>
#include "glimac/glm.hpp"
#include "glimac/common.hpp"



/// \class VBO
/// \brief Contain the vertices of an object
class IBO 
{

private:
	GLuint _id;
	std::vector<uint32_t> _indexes;
	size_t _size;
public:
	IBO();
	/// \param vertices: Vector of a structure containing vertex, normal, texture

	IBO(const GLuint &id);

	IBO(const std::vector<uint32_t> &index, const GLuint &id);

	/// \param copied : The VBO to copy into the current object
	IBO(const IBO &copied);
		// glGenBuffers; glBindBuffer; glBufferData; glVertexAttribPointer
	~IBO();
		// deleteBuffers

	inline GLuint id() const
	{
		return _id;
	};

	inline size_t size() const
	{
		return _indexes.size();
	}

	inline std::vector<uint32_t> indexes() const
	{
		return _indexes;
	};

	inline void indexes(std::vector<uint32_t> ind) 
	{
		_indexes = ind;
	};

	/// \brief Allows to bind the buffer array
	void bind() const;

	/// \brief  Unbinds the buffer
	void debind() const;

	/// \brief BiFill the IBO with the indexes
	void fillIbo() const;



private:

};

#endif