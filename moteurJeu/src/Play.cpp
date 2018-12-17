#include "moteurJeu/Play.hpp"

Play::Play() : _score(0), _distance(0), _coins(0), _speed(1)
{

}

Play::~Play() 
{

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

const unsigned int Play::pause() 
{
	unsigned int currentSpeed = _speed;
	// stop the game
	_speed = 0;

	return currentSpeed;
}

void Play::resume(const unsigned int speed) {
	_speed = speed;
}