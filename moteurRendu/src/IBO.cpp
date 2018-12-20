#include "moteurRendu/IBO.hpp"

IBO::IBO(): _id(0)
{
}

IBO::IBO(const size_t &size, const GLuint &id): _id(id), _size(size)
{
	_indexes = new unsigned int[ size ];
	glGenBuffers(1, &_id);

}

IBO::IBO(const size_t &size, const unsigned int* index, const GLuint &id):  
_id(id), _indexes(index), _size(size)
{
	glGenBuffers(1, &_id);
}


IBO::IBO(const IBO &copied): _id( copied._id), _indexes(copied._indexes), _size(copied._size)
{

}

IBO::~IBO()
{
	
}


void IBO::bind() const 
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
}


void IBO::debind() const 
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IBO::fillIbo() const 
{
	bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _size * sizeof(unsigned int), _indexes, GL_STATIC_DRAW);
	debind();
}