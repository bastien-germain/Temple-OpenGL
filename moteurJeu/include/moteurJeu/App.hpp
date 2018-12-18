#pragma once
#ifndef __APP_HPP__
#define __APP_HPP__

#include "moteurJeu/Game.hpp"
#include "moteurJeu/Menu.hpp"

/// \class App
/// \brief Main app component
class App 
{

private:
	unsigned int _maxScore;
	Menu _menu;
	Game _currentGame;
	
public:
	App();
	~App();

	/// \brief Launch a new game
	void launchGame();

	// PAS FINI
	/// \brief End current game then call updateMaxScore()
	void endGame();

	void updateMaxScore();

	void pause();
	
	void resume();
	
	// PAS FAIT; pour quitter le programme
	void exitApp(); 
		

};

#endif