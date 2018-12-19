#include "moteurRendu/VBO.hpp"

VBO::VBO() : _id(0)
{
	std::cout << " *** VBO DEFAULT CONSTRUCTOR" << std::endl;
}

// On passe un vetceur de point (3c oord)
VBO::VBO(const std::vector<glimac::ShapeVertex> &vertices, const GLuint &id, const size_t size, uint32_t* indexes)
: _vertices(vertices), _nbVertices(vertices.size()), _id(id)
{
	glGenBuffers(1,&_id);
	_vao = VAO(_id);
	_ibo = IBO(size, indexes, id);
	
}

VBO::VBO(const VBO &copied) : _id(copied._id), _vao(copied._vao)
{

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
	_ibo.fillIbo();
	_vao.bind();
	_ibo.bind();
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

	_vao.deleteBuf();
	glDeleteBuffers(1, &_id);
}


void VBO::draw() const
{
    // glDrawArrays(GL_TRIANGLES, 0, _nbVertices); //Dessin des triangles

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
