#include "moteurRendu/LightingModel.hpp"

LightingModel::LightingModel()
{
}

LightingModel::LightingModel(const VBO &vbo , const Light &light, const Texture &texture) 
	: Model(vbo, texture), _light(light)
{
}

LightingModel::LightingModel(const LightingModel &copied) 
	: Model(copied), _light(copied._light)
{

}

LightingModel::~LightingModel()
{

}