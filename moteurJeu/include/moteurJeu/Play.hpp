#pragma once
#ifndef __PLAY_HPP__
#define __PLAY_HPP__

#include "moteurJeu/Player.hpp"
#include "moteurJeu/Enemy.hpp"
#include "moteurJeu/Section.hpp"
#include <vector>

/// \class Play
/// \brief One try a the game
class Play 
{

private:

	unsigned int _score;
	unsigned int _distance; // distance travelled 
	unsigned int _coins; // number of coins collected
	unsigned int _speed; // current speed
	unsigned int _pausedSpeed; // contains current play speed when play is paused
	Player _player;
	Enemy _enemy;
	std::vector<std::vector<Section>> _sections;
	
public:
	Play();
	~Play();

	/// \brief Getter score
	inline unsigned int score() const 
	{
		return _score;
	}

	/// \brief Start the play (speed goes from 0 to 1)
	void start();

	/// \brief Increase distance based on current speed then call updateScore()
	void updateDistance();

	/// \brief Update score based on distance and coins
	void updateScore();

	/// \brief Increase speed
	void speedUp();

	/// \brief add a number of coins to the total of collected coins then call updateScore()
	/// \param quantity : number of coins to be added
	void addCoins(const unsigned int quantity);

	void pause();

	void resume();

	/// \brief test end of play
	bool isOver();		

};

#endif