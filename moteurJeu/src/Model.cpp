#include "moteurJeu/Model.hpp"

Model::Model()
{
}

Model::Model(const VBO &vbo, const Texture &texture) 
	:_vbo(vbo), _texture(texture)
{
}

Model::Model(const Model &copied) 
	:_vbo(copied._vbo), _texture(copied._texture)
{

}

Model::~Model()
{

}