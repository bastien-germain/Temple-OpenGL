#include "moteurJeu/Game.hpp"

Game::Game() : _score(0), _distance(0), _coins(0), _speed(0), _pausedSpeed(0), _player(Player()), _enemy(Enemy()) 
{
	for (unsigned int i = 0; i < 3; i++)
	{	
		std::vector<Section> temp;
		_sectionMat.push_back(temp);
	}
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
	if(_enemy.distanceToPlayer() == 0)
		return true;
	else 
		return false;
}

void Game::fillSectionVec(const Section &newSec)
{	
	_sectionVec.push_back(newSec);
}

void Game::fillSectionMat()
{	
	for (unsigned int i = 0; i < _sectionVec.size(); i++) 
	{
		_sectionMat[0].push_back(_sectionVec[i]);

		if (_sectionVec[i].isT())
		{	
			// TESTER S'IL RESTE AU MOINS 6 SECTIONS !

			// On passe les 3 d'après à la deuxième ligne (côté gauche)
			for (unsigned int j = i + 1; j < i + 4; j++)
			{
				_sectionMat[1].push_back(_sectionVec[j]);
			}

			i+=3;

			// On passe les 3 encore d'après à la troisième ligne (côté droit)
			for (unsigned int j = i + 1; j < i + 4; j++)
			{
				_sectionMat[2].push_back(_sectionVec[j]);
			}

			i+=3;
		}
	}	
}

void Game::updateSectionMat(const bool isLeft)
{
	if (isLeft)
	{	
		// left
		_sectionMat[0] = _sectionMat[1];
		_sectionMat[1].clear();
	}
	else
	{	
		// right
		_sectionMat[0] = _sectionMat[2];
		_sectionMat[2].clear();
	}	
}
