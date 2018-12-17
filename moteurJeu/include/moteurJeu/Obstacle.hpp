#pragma once
#ifndef __OBSTACLE_HPP__
#define __OBSTACLE_HPP__

#include <glimac/glm.hpp>

/// \class Obstacle
/// \brief Class defining an Obstacle
class Obstacle 
{

private:
	glm::vec3 _position; /* Position of the Obstacle */
	float _size; /*! Size of the Obstacle */
	
public:
	/// \brief Default constructor
	Obstacle();

	/// \brief Constructor from a position and a size
	/// \param position : the position of the Obstacle
	/// \param size : the size of the Obstacle
	Obstacle(const glm::vec3 &position = glm::vec3(0.0), const float &size = 0.0);

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

	/// \brief Getter : position getter
	inline glm::vec3 position() const 
	{
		return _position;
	}

};

#endif