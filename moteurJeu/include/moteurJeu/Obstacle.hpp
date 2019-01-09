#pragma once
#ifndef __OBSTACLE_HPP__
#define __OBSTACLE_HPP__

#include <glimac/glm.hpp>

#include "moteurJeu/PositionObservable.hpp"

#include "moteurRendu/Model.hpp"

/// \class Obstacle
/// \brief Class defining an Obstacle
class Obstacle : public PositionObservable
{

private:
	int _posX; /* X position of the Obstacle */
	float _posZ; /* Z position of the Obstacle */
	int _sizeY; /* height on Y axis */
	int _sizeX; /* length on X axis Obstacle */ 

	const Model *_model;
	
public:
	/// \brief Constructor from a position and a size
	/// \param position : the position of the Obstacle
	/// \param size : the size of the Obstacle
	Obstacle(const Model *model = NULL, PositionObserver *observer = NULL, const int posX = 0, const float posZ = 0, const int sizeX = 0, const int sizeY = 0);

	/// \brief Copy constructor using another Obstacle
	/// \param copied : the copied Obstacle
	Obstacle(const Obstacle &copied);

	inline Obstacle &operator = (const Obstacle &toAssign) {

		if (&toAssign != 	this) 
		{	
			_posX = toAssign._posX;
			_posZ = toAssign._posZ;
			_sizeX = toAssign._sizeX;
		}

		return *this;
	}

	/// \brief Destructor
	~Obstacle();

	/// \brief Getter : sizeX getter
	inline int sizeX() const
	{
		return _sizeX;
	} 

	/// \brief Getter : sizeY getter
	inline int sizeY() const
	{
		return _sizeY;
	} 

	/// \brief Getter : posX getter
	inline int posX() const
	{
		return _posX;
	}

	/// \brief Getter : posZ getter
	inline float posZ() const
	{
		return _posZ;
	}
	
	inline const Model *model() const 
	{
		return _model;
	}

	/// \brief posZ modifier when the Obstalce progresses along Z axis
	inline void goOnZ(const float &delta)
	{
		if (_sizeX != 0) 
		{
			_posZ += delta;
			notify();
		}
	}
};

#endif