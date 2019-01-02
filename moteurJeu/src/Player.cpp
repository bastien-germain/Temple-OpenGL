#include "moteurJeu/Player.hpp"

#include <iostream>

Player::Player() 
	: _posX(REGULAR_X), _posY(REGULAR_Y), _posZ(REGULAR_Z), 
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
		_posX += X_SMOOTHNESS;
}

void Player::goCenter() 
{
	if (_posX < REGULAR_X)
		_posX += X_SMOOTHNESS;
	else
		_posX -= X_SMOOTHNESS;
}

void Player::goLeft() 
{
	if(_posX > MIN_X) 
		_posX -= X_SMOOTHNESS;
}

//// Y MOVE ////
	
void Player::jump() 
{	
	if(_posY < MAX_Y) 
		_posY += Y_SMOOTHNESS;
	else 
	{
		_jumping = false;
		_landing = true;
	}
}

void Player::land()
{	
	if (fabs(_posY - REGULAR_Y) <= Y_SMOOTHNESS)
	{	
		_landing = false;
	}
	else
	{
		if (_posY > REGULAR_Y)
			_posY -= Y_SMOOTHNESS;
		else
			_posY += Y_SMOOTHNESS;
	}
}

void Player::bendDown() 
{	
	if(_posY > MIN_Y) 
		_posY -= Y_SMOOTHNESS;
	else
	{	
		_bending = false;
		_landing = true;
	}
}