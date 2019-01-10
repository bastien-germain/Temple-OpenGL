#include "moteurJeu/Skybox.hpp"

#include <iostream>

Skybox::Skybox() 
	: _posX(0.f), _posY(1.7f), _posZ(0.f)
{
}

Skybox::Skybox(const Skybox &copied) 
	: _posX(copied._posX), _posY(copied._posY), _posZ(copied._posZ),
	_model(copied._model)
{
}

Skybox::~Skybox() 
{
}
