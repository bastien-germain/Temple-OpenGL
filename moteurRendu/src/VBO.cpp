#include "moteurRendu/VBO.hpp"
#include <iostream>


VBO::VBO() : _id(0)
{
	std::cout << " *** VBO DEFAULT CONSTRUCTOR" << std::endl;
}

VBO::VBO(const Geometry &g) : _nbVertices(g.getVertexCount()), _geo(g)
{
    for (size_t i =0; i < _nbVertices; i ++)
    {
        _vertices.push_back(g.getVertexBuffer()[i]);
    }
	glGenBuffers(1,&_id);
	std::cout << "vbo id in vbo const : " << _id << std::endl;
	_vao = VAO();
	std::cout << "vao id in vbo constr : " << _vao.id() << std::endl;
	_ibo = IBO(g.getIndexCount(), g.getIndexBuffer());
	std::cout << "ibo id in vbo constr : " << _ibo.id() << std::endl;
	std::cout << "ibo size in vbo constr : " << _ibo.size() << std::endl;
}

VBO::VBO(const VBO &copied) 
	: _id(copied._id), _vao(copied._vao), _ibo(copied._ibo), _geo(copied._geo), 
	_nbVertices(copied._nbVertices), _vertices(copied._vertices)
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
	glBufferData(GL_ARRAY_BUFFER,  _nbVertices * sizeof(ShapeVertex), &_vertices[0], GL_STATIC_DRAW);
	// glBufferData(GL_ARRAY_BUFFER,  _geo.getVertexCount() * sizeof(ShapeVertex), _geo.getVertexBuffer(), GL_STATIC_DRAW);
// 
	debind();

	specifyVAO();
}

void VBO::deleteBuf() const 
{

	_vao.deleteBuf();
	glDeleteBuffers(1, &_id);
}


void VBO::draw() const
{
    // glDrawElements(GL_TRIANGLES, _geo.getIndexCount(), GL_UNSIGNED_INT, 0);
	_vao.bind();
	std::cout << "draw" << "vao id : " << _vao.id() << " | vbo id : " << _id << std::endl;
	std::cout << "draw" << "ibo size : " << _ibo.size() << std::endl;
    glDrawElements(GL_TRIANGLES, _ibo.size(), GL_UNSIGNED_INT, 0);
	_vao.debind();
}