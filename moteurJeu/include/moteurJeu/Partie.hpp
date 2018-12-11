#pragma once
#ifndef __PARTIE_HPP__
#define __PARTIE_HPP__

class Partie 
{

private:
	unsigned int _score;

	
public:
	Partie();
	~Partie();

	void pause();
	void reprendre();
		

};

#endif