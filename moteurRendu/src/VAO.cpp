#include "moteurRendu/VAO.hpp"

VAO::VAO()
{
	
}

VAO::VAO(const std::vector<GLuint> &lAttribute): _lAttribute(lAttribute)
{
	glGenVertexArrays(1,&_id);
}

VAO::~VAO()
{}

void VAO::debind() const 
{
	glBindVertexArray(0);
}

void VAO::bind() const 
{
	glBindVertexArray(_id);
}

void VAO::specificationAttributes() const
{
	for (int i = 0; i < _lAttribute.size() ; i++)
	{

	}
}