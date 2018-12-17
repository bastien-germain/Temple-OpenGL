#pragma once
#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "moteurJeu/Play.hpp"
#include "moteurJeu/Menu.hpp"

/// \class Game
/// \brief Main app component
class Game 
{

private:
	unsigned int _maxScore;
	Menu _menu;
	Play _currentPlay;
	
public:
	Game();
	~Game();

	/// \brief Launch a new play
	void launchPlay();

	// PAS FINI
	/// \brief End current play then call updateMaxScore()
	void endPlay();

	void updateMaxScore();
	
	// PAS FAIT
	void exitGame(); 
		

};

#endif