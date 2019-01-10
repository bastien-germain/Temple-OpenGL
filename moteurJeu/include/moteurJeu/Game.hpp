#pragma once
#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "moteurJeu/GameManager.hpp"

#include <glimac/Program.hpp>

/// \class Game
/// \brief Main game component
class Game 
{

private:
	unsigned int _maxScore;
	unsigned int _currentGameScore;
	GameManager _gameManager;
	
public:
	Game(Program &program);
	~Game();

	/// \brief Launch a new game
	void launchGame();

	bool processGame(SDL_Event *event, Program &program);

	/// \brief End current game then call updateMaxScore()
	void endGame();

	/// \brief Update score based on distance and coins
	void updateScore();

	void updateMaxScore();

	void pause();
	
	void resume();		

};

#endif