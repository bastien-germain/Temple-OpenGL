#pragma once
#ifndef __Player_HPP__
#define __Player_HPP__

#include <cmath>

#define MAX_X 2.f
#define REGULAR_X 0.f
#define MIN_X -2.f

#define MAX_Y 2.f
#define REGULAR_Y 0.f
#define MIN_Y -2.f

#define REGULAR_Z 0.f

/// \class Player
/// \brief Class defining the main player
class Player
{

private:
	float _posX; // -1 : left; 0 : middle; 1: right
	float _posY; // -1 : down; 0 : regular; 1: up
	float _posZ; // position of the player, to which the obstacle posZ will be compared
	const float _xSmoothness;
	const float _ySmoothness;

public:
	bool _jumping;
	bool _bending;
	bool _landing;

	/// \brief Constructor
	Player(const float &xSmoothness = 0.002f, const float &ySmoothness = 0.002f);

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