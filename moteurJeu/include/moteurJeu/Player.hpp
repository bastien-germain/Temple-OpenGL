#pragma once
#ifndef __Player_HPP__
#define __Player_HPP__

#include <cmath>

#include "moteurRendu/ModelLoader.hpp"
#include "moteurJeu/Factory.hpp"

#define REGULAR_X 0.f
#define MAX_X (REGULAR_X + 2)
#define MIN_X (REGULAR_X - 2)
#define X_SMOOTHNESS 0.002

#define REGULAR_Y 1.5f
#define MAX_Y (REGULAR_Y + 2)
#define MIN_Y (REGULAR_Y +- 2)
#define Y_SMOOTHNESS 0.002

#define REGULAR_Z 0.f

#define ROTATE_X_SPEED 0.05f
#define MAX_ROTATE_X 20.f

/// \class Player
/// \brief Class defining the main player
class Player
{

private:
	float _posX; // -1 : left; 0 : middle; 1: right
	float _posY; // -1 : down; 0 : regular; 1: up
	float _posZ; // position of the player, to which the obstacle posZ will be compared
	float _rotateX;
	bool _oppositeRotateX;
	Model *_model;
public:
	bool _jumping;
	bool _bending;
	bool _landing;

	/// \brief Constructor
	Player();

	Player(const Player &copied);

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

	inline float rotateX()
	{
		if (_rotateX > MAX_ROTATE_X || _rotateX < -MAX_ROTATE_X)
        	_oppositeRotateX = !_oppositeRotateX;

		if(_oppositeRotateX)
			_rotateX -= ROTATE_X_SPEED;
		else 
			_rotateX += ROTATE_X_SPEED;

		return _rotateX;
	}

	inline Model *model() const 
	{
		return _model;
	}

	inline void model(Model *model) {
		_model = model;
	}

};

#endif