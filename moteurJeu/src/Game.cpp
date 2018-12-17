#include "moteurJeu/Game.hpp"

Game::Game() : _maxScore(0), _menu(Menu()) 
{

}

Game::~Game()
{
	
}

void Game::launchPlay()
{
	_currentPlay.start();
	_menu.hide();
}

void Game::endPlay()
{
	// do something
	updateMaxScore();
}

void Game::updateMaxScore() 
{
	if (_currentPlay.score() > _maxScore) 
	{
		_maxScore = _currentPlay.score();
	}
}