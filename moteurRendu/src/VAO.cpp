#include "moteurRendu/VAO.hpp"


VAO::VAO(): _VERTEX_POSITION(0), _VERTEX_NORMAL(1), _VERTEX_TEXTURE(2)
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



void VAO::specifyAttributes() const
{
	glEnableVertexAttribArray(_VERTEX_POSITION);
    glEnableVertexAttribArray(_VERTEX_NORMAL);
    glEnableVertexAttribArray(_VERTEX_TEXTURE);

	glVertexAttribPointer(_VERTEX_POSITION, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (const GLvoid*)0); 
    glVertexAttribPointer(_VERTEX_NORMAL, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (const GLvoid*) (3*sizeof(GLfloat)));
    glVertexAttribPointer(_VERTEX_TEXTURE, 2, GL_FLOAT, GL_FALSE, 8*sizeof(GLfloat), (const GLvoid*) (6*sizeof(GLfloat)));
    
}


void VAO::deleteBuf()
{
	glDeleteVertexArrays(1, &_id);
}