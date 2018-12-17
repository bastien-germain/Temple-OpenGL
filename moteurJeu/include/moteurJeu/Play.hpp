#pragma once
#ifndef __PLAY_HPP__
#define __PLAY_HPP__

#include "moteurJeu/Player.hpp"

/// \class Player
/// \brief Character played by users
class Play 
{

private:

	unsigned int _score;
	unsigned int _distance; // distance travelled 
	unsigned int _coins; // number of coins collected
	unsigned int _speed; // current speed
	Player _player;
	
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

	/// \return Current play speed
	const unsigned int pause();

	/// \param speed : resume the game at that speed
	void resume(const unsigned int speed);		

};

#endif