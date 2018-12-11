#pragma once
#ifndef __JEU_HPP__
#define __JEU_HPP__

class Jeu 
{

private:
	unsigned int _scoreMax;
	
	
public:
	Jeu();

	~Jeu();

	void lancerPartie(); // Permet de démarrer une partie
	void finPartie(); // Permet de modifier le score max du joueur et termine la partie
	
	void quitterJeu(); 
		

};

#endif