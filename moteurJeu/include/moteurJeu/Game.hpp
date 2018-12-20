#pragma once
#ifndef __GAME_HPP__
#define __GAME_HPP__

/// \class Game
/// \brief One try a the game
class Game 
{

private:
	unsigned int _score;
	unsigned int _distance; // distance travelled 
	unsigned int _coins; // number of coins collected
	unsigned int _speed; // current speed
	unsigned int _pausedSpeed; // contains current play speed when play is paused
public:
	Game();
	~Game();

	/// \brief Getter score
	inline unsigned int score() const 
	{
		return _score;
	}


	/// \brief Start the game (speed goes from 0 to 1)
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

};

#endif