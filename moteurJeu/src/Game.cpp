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
	updateMaxScore();
	_menu.show();
	// do something to end the play
}

void Game::updateMaxScore() 
{
	if (_currentPlay.score() > _maxScore) 
		_maxScore = _currentPlay.score();	
}

void Game::pause()
{
	_currentPlay.pause();
	_menu.show();
}

void Game::resume()
{
	_menu.hide();
	_currentPlay.resume();
}