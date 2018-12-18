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
	_menu.hide();
}

void App::endGame()
{
	updateMaxScore();
	_menu.show();
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
	_menu.show();
}

void App::resume()
{
	_menu.hide();
	_currentGame.resume();
}