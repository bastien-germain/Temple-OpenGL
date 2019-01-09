#include "moteurJeu/Skybox.hpp"

#include <iostream>

Skybox::Skybox() 
	: _posX(0.f), _posY(1.7f), _posZ(0.f), _rotateX(0), _oppositeRotateX(0)
{
}

Skybox::Skybox(const Skybox &copied) 
	: _posX(copied._posX), _posY(copied._posY), _posZ(copied._posZ),
	_model(copied._model), _rotateX(copied._rotateX), _oppositeRotateX(copied._oppositeRotateX)
{
}

Skybox::~Skybox() 
{
}

//// X MOVE ////

