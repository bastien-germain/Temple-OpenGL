#include "moteurJeu/Player.hpp"
#include <iostream>

Player::Player(const float &xSmoothness, const float &ySmoothness) 
	: _posX(REGULAR_X), _posY(REGULAR_Y), _posZ(REGULAR_Z), _xSmoothness(xSmoothness) ,_ySmoothness(ySmoothness), 
	_jumping(false), _landing(false), _bending(false)
{
}

Player::~Player() 
{
}

//// X MOVE ////

void Player::goRight() 
{
	if(_posX < MAX_X) 
		_posX += _xSmoothness;
}

void Player::goCenter() 
{
	if (_posX < REGULAR_X)
		_posX += _xSmoothness;
	else
		_posX -= _xSmoothness;
}

void Player::goLeft() 
{
	if(_posX > MIN_X) 
		_posX -= _xSmoothness;
}

//// Y MOVE ////
	
void Player::jump() 
{	
	if(_posY < MAX_Y) 
		_posY += _ySmoothness;
	else 
	{
		_jumping = false;
		_landing = true;
	}
}

void Player::land()
{	
	if (fabs(_posY - REGULAR_Y) <= _ySmoothness)
	{	
		_landing = false;
	}
	else
	{
		if (_posY > REGULAR_Y)
			_posY -= _ySmoothness;
		if (_posY < REGULAR_Y)
			_posY += _ySmoothness;
	}
}

void Player::bendDown() 
{	
	if(_posY > MIN_Y) 
		_posY -= _ySmoothness;
	else
		_bending = false;
		_landing = true;
}