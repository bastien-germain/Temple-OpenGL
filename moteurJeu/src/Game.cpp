#include "moteurJeu/Game.hpp"

Game::Game(Program &program) : _maxScore(0), _currentGameScore(0), _gameManager(GameManager(program))
{	
    _gameManager.loadSections();
}

Game::~Game()
{
	
}

void Game::launchGame()
{	
	// start le defilement du decor
}

bool Game::processGame(SDL_Event *event, Program &program)
{
	std::cout << "Jeu affiché" << std::endl;
    _gameManager.handleEvent(event);

    glm::mat4 trackMat = _gameManager.trackball().getViewMatrix();

    _gameManager.drawer().draw(
        _gameManager.sectionVec(), 
        _gameManager.trackball().getViewMatrix(), 
        _gameManager.player(),
        _gameManager.enemy(),
        _gameManager.skybox(),
        program);

    if (_gameManager.isOver())
    {
        std::cout << "game over" << std::endl;
        return true;
    }
    return false;
}

void Game::endGame()
{
	updateMaxScore();
	// do something to end the game
}

void Game::updateMaxScore() 
{
	if (_currentGameScore > _maxScore) 
		_maxScore = _currentGameScore;	
}

void Game::updateScore() 
{
	
}


void Game::pause()
{

}

void Game::resume()
{
	
}