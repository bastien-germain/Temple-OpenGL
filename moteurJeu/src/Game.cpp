#include "moteurJeu/Game.hpp"

Game::Game(Program &program, const FilePath &applicationPath) : _maxScore(0), _currentGameScore(0), _gameManager(GameManager(program, applicationPath))
{	
    
    /*_gameManager.worldGenerator().generateInitialSections(
        &_gameManager, 
        _gameManager.factory());*/
    
    
    _gameManager.worldGenerator().generateSectionsFromFile(
        &_gameManager, 
        _gameManager.factory(), 
        _gameManager.parser());
    
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
    bool over = false;
    _gameManager.handleEvent(event);

    glm::mat4 matCamera;

    if (_gameManager.eventManager().camTrack())
        matCamera = _gameManager.trackball().getViewMatrix();
    else
        matCamera = _gameManager.fly().getViewMatrix();

    over = !_gameManager.drawer().draw(_gameManager.worldGenerator().sectionVec(), 
        matCamera,
         _gameManager.player(), 
         _gameManager.enemy(), 
         _gameManager.skybox(),
         program);

    _gameManager.worldGenerator()._popCounter += WORLD_SPEED;

    if (fabs(_gameManager.worldGenerator()._popCounter -  POSITION_OFFSET_Z) < WORLD_SPEED)
    {
        _gameManager.worldGenerator().sectionVec().erase(_gameManager.worldGenerator().sectionVec().begin());
        _gameManager.worldGenerator().generateSection(&_gameManager, _gameManager.factory());
    }

    if (over)
    {
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