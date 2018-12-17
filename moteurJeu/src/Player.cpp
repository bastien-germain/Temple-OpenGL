#include "moteurJeu/Player.hpp"

Player::Player() : _posX(0), _posY(0)
{

}

Player::~Player() 
{

}

void Player::goRight() 
{
	if(_posX != 1) 
	{
		_posX += 1;
	}
}

void Player::goLeft() 
{
	if(_posX != -1) 
	{
		_posX -= 1;
	}
}

void Player::jump() 
{
	_posY = 1;
}

void Player::bendDown() 
{	
	_posX -= 1;
}