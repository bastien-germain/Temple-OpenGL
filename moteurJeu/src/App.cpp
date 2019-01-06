#include "moteurJeu/App.hpp"

App::App() : _maxScore(0), _menu(Menu()) 
{

}

App::~App()
{
	
}

void App::launchGame()
{
	_currentGame.start();
}

void App::endGame()
{
	updateMaxScore();
	// do something to end the game
}

void App::updateMaxScore() 
{
	if (_currentGame.score() > _maxScore) 
		_maxScore = _currentGame.score();	
}

void App::pause()
{
	_currentGame.pause();
}

void App::resume()
{
	_currentGame.resume();
}