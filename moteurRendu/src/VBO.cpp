#include "moteurRendu/VBO.hpp"

VBO::VBO()
{}

// On passe un vetceur de point (3c oord)
VBO::VBO(const std::vector<glimac::ShapeVertex> &vertices): _vertices(vertices), _nbVertices(vertices.size())
{
	glGenBuffers(1,&_id);
	// glGenBuffers; glBindBuffer; glBufferData; glVertexAttribPointer
}

VBO::~VBO()
{}

void VBO::debind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _id);
}

void VBO::specifyVAO() const
{
	_vao.bind();
	bind();
	_vao.specifyAttributes();
	debind();
	_vao.debind();

}

void VBO::sendData() const
{
	bind();
	glBufferData(GL_ARRAY_BUFFER,  _nbVertices * sizeof(glimac::ShapeVertex), &_vertices[0], GL_STATIC_DRAW);
	debind();
}

void VBO::deleteBuf()
{
	glDeleteBuffers(1, &_id);
}

