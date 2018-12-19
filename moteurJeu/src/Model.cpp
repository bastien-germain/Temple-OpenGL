#include "moteurJeu/Model.hpp"

Model::Model()
{
	std::cout << " *** MODEL DEFAULT CONSTRUCTOR" << std::endl;
}

Model::Model(const VBO &vbo , const VAO &vao, const Light &light, const Texture &texture) 
	:_vbo(vbo), _vao(vao), _light(light), _texture(texture)
{
	std::cout << "*** MODEL VALUE-BASED CONSTRUCTOR" << std::endl;
}

Model::Model(const Model &copied) 
	:_vbo(copied._vbo), _vao(copied._vao), _light(copied._light), _texture(copied._texture)
{

}

Model::~Model()
{

}