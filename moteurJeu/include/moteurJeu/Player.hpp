#pragma once
#ifndef __Player_HPP__
#define __Player_HPP__


/// \class Player
/// \brief Class defining the main player
class Player
{

private:
	unsigned int _posX; // -1 : left; 0 : middle; 1: right
	unsigned int _posY; // -1 : down; 0 : regular; 1: up
	float _posZ; // position of the player, to which the obstacle posZ will be compared

public:
	/// \brief Constructor
	Player();

	/// \brief Destructor
	~Player();

	void goRight();
	void goLeft();
	void jump();
	void bendDown();

	inline float posZ() const {
		return _posZ;
	}
};

#endif