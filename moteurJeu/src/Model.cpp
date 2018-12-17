#include "moteurJeu/Model.hpp"

Model::Model(const VBO &vbo , const VAO &vao, const Light &light, const Texture &texture) 
	:_vbo(vbo), _vao(vao), _light(light), _texture(texture)
{

}

Model::Model(const Model &copied) 
	:_vbo(copied._vbo), _vao(copied._vao), _light(copied._light), _texture(copied_texture)
{

}

Model::~Model()
{

}