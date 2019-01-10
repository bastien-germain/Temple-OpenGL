#include "moteurJeu/Player.hpp"

#include <iostream>

Player::Player() 
	: _posX(REGULAR_X), _posY(REGULAR_Y), _posZ(REGULAR_Z), _rotateX(0), _oppositeRotateX(0), 
	_jumping(false), _landing(false)
{
}

Player::Player(const Player &copied) 
	: _posX(copied._posX), _posY(copied._posY), _posZ(copied._posZ),
	_jumping(copied._jumping), _landing(copied._landing), 
	_model(copied._model), _rotateX(copied._rotateX), _oppositeRotateX(copied._oppositeRotateX)
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
	if (_posX < REGULAR_X - 0.1)
		_posX += X_SMOOTHNESS;
	else if (_posX > REGULAR_X + 0.1)
		_posX -= X_SMOOTHNESS;
}

void Player::goLeft() 
{
	if(_posX > MIN_X) 
		_posX -= X_SMOOTHNESS;
}

//// Y MOVE ////
	
void Player::jump(FreeflyCamera &fly) 
{	
	if(_posY < MAX_Y - 2)
	{
		_posY += Y_SMOOTHNESS * 1.5;
		fly.moveTop(Y_SMOOTHNESS * 1.5);
	} 
	else if (_posY < MAX_Y - 1)
	{
		_posY += Y_SMOOTHNESS;
		fly.moveTop(Y_SMOOTHNESS );
	}
	else if (_posY < MAX_Y)
	{
		// Ralentit le saut lorsqu'il s'approche de son point culminant
		_posY += Y_SMOOTHNESS * 0.8;
		fly.moveTop(Y_SMOOTHNESS * 0.8);
	}
	else 
	{
		_jumping = false;
		_landing = true;
	}
}

void Player::land(FreeflyCamera &fly)
{	
	if (fabs(_posY - REGULAR_Y) <= Y_SMOOTHNESS)
	{	
		_landing = false;
	}
	else
	{
		if (_posY > REGULAR_Y + 2)
		{
			_posY -= Y_SMOOTHNESS * 0.8;
			fly.moveTop(-Y_SMOOTHNESS * 0.8);
		} 
		else if (_posY > REGULAR_Y + 1)
		{
			_posY -= Y_SMOOTHNESS;	
			fly.moveTop(-Y_SMOOTHNESS);		
		}
		else 
		{
			_posY -= Y_SMOOTHNESS * 1.5;
			fly.moveTop(-Y_SMOOTHNESS * 1.5);
		}
		
	}
}