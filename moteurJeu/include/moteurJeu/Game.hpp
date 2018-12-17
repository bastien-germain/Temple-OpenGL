#pragma once
#ifndef __GAME_HPP__
#define __GAME_HPP__

class Game 
{

private:
	unsigned int _maxScore;
	
	
public:
	Game();

	~Game();

	void launchPlay(); // Permet de démarrer une partie
	void endPlay(); // Permet de modifier le score max du joueur et termine la partie
	
	void exitGame(); 
		

};

#endif