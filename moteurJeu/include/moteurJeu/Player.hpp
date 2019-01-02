#pragma once
#ifndef __Player_HPP__
#define __Player_HPP__

#include <cmath>

#define REGULAR_X 0.f
#define MAX_X (REGULAR_X + 2)
#define MIN_X (REGULAR_X - 2)
#define X_SMOOTHNESS 0.002

#define REGULAR_Y 1.5f
#define MAX_Y (REGULAR_Y + 2)
#define MIN_Y (REGULAR_Y +- 2)
#define Y_SMOOTHNESS 0.002

#define REGULAR_Z 0.f

/// \class Player
/// \brief Class defining the main player
class Player
{

private:
	float _posX; // -1 : left; 0 : middle; 1: right
	float _posY; // -1 : down; 0 : regular; 1: up
	float _posZ; // position of the player, to which the obstacle posZ will be compared
	
public:
	bool _jumping;
	bool _bending;
	bool _landing;

	/// \brief Constructor
	Player();

	/// \brief Destructor
	~Player();

	void goRight();
	void goCenter();
	void goLeft();

	void jump();
	void land();
	void bendDown();

	inline float posZ() const 
	{
		return _posZ;
	}

	inline float posX() const 
	{
		return _posX;
	}

	inline float posY() const 
	{
		return _posY;
	}

};

#endif