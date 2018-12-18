#pragma once
#ifndef __OBSTACLE_HPP__
#define __OBSTACLE_HPP__

#include <glimac/glm.hpp>
#include <moteurJeu/Observable.hpp>

/// \class Obstacle
/// \brief Class defining an Obstacle
class Obstacle : public Observable
{

private:
	unsigned int _posX; /* X position of the Obstacle */
	float _posZ; /* Z position of the Obstacle */
	unsigned int _size; /*! Size of the Obstacle */
	
public:
	/// \brief Constructor from a position and a size
	/// \param position : the position of the Obstacle
	/// \param size : the size of the Obstacle
	Obstacle(const unsigned int posX = 0, const float posZ = 0, const unsigned int size = 0);

	/// \brief Copy constructor using another Obstacle
	/// \param copied : the copied Obstacle
	Obstacle(const Obstacle &copied);

	/// \brief Destructor
	~Obstacle();

	/// \brief Getter : size getter
	inline float size() const 
	{
		return _size;
	}

	/// \brief Getter : posX getter
	inline unsigned int posX() const 
	{
		return _posX;
	}

	/// \brief Getter : posZ getter
	inline unsigned int posZ() const 
	{
		return _posZ;
	}

	void proress(const float &delta) {
		_posZ += delta;
	}

};

#endif