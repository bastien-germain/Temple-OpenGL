#include "moteurJeu/Game.hpp"

Game::Game() : _score(0), _distance(0), _coins(0), _speed(0), _pausedSpeed(0), _manager()
{
}

Game::~Game() 
{

}

void Game::start() 
{
	_speed = 1;
}

void Game::speedUp() 
{
	_speed ++;
}

void Game::updateScore() 
{
	_score = _coins * 10 + _distance;
}

void Game::updateDistance() 
{
	_distance += _speed;
	updateScore();
}

void Game::addCoins(const unsigned int quantity) 
{
	_coins += quantity;
	updateScore();
}

void Game::pause() 
{
	_pausedSpeed = _speed;
	// stop the game
	_speed = 0;
}

void Game::resume() 
{
	_speed = _pausedSpeed;
}

bool Game::isOver() const
{
	if(_manager.enemy().distanceToPlayer() == 0)
		return true;
	else
		return false;
}

GameManager Game::gameManager() const {
	return _manager;
}