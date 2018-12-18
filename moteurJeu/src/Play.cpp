#include "moteurJeu/Play.hpp"

Play::Play() : _score(0), _distance(0), _coins(0), _speed(0), _pausedSpeed(0), _player(Player()), _enemy(Enemy())
{

}

Play::~Play() 
{

}

void Play::start() 
{
	_speed = 1;
}

void Play::speedUp() 
{
	_speed ++;
}

void Play::updateScore() 
{
	_score = _coins * 10 + _distance;
}

void Play::updateDistance() 
{
	_distance += _speed;
	updateScore();
}

void Play::addCoins(const unsigned int quantity) 
{
	_coins += quantity;
	updateScore();
}

void Play::pause() 
{
	_pausedSpeed = _speed;
	// stop the game
	_speed = 0;
}

void Play::resume() 
{
	_speed = _pausedSpeed;
}

bool Play::isOver()
{
	if(_enemy.distanceToPlayer() == 0)
		return true;
	else 
		return false;
}