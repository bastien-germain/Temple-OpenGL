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
	unsigned int _size; /*! Size of the Obstacle */

	const Model *_model;
	
public:
	/// \brief Constructor from a position and a size
	/// \param position : the position of the Obstacle
	/// \param size : the size of the Obstacle
	Obstacle(const Model *model = NULL, PositionObserver *observer = NULL, const int posX = 0, const float posZ = 0, const unsigned int size = 0);

	/// \brief Copy constructor using another Obstacle
	/// \param copied : the copied Obstacle
	Obstacle(const Obstacle &copied);

	inline Obstacle &operator = (const Obstacle &toAssign) {

		if (&toAssign != 	this) 
		{	
			_posX = toAssign._posX;
			_posZ = toAssign._posZ;
			_size = toAssign._size;
		}

		return *this;
	}

	/// \brief Destructor
	~Obstacle();

	/// \brief Getter : size getter
	inline float size() const
	{
		return _size;
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
		if (_size != 0) 
		{
		//std::cout << "*** OBSTACLE PROGRESS" << std::endl;
		_posZ += delta;
		//notify();
		}
	}
};

#endif