#pragma once
#ifndef __ROCK_HPP__
#define __ROCK_HPP__

#include "Obstacle.hpp"

/// \class Rock
/// \brief Class defining a Rock (specific type of Obstacle) - inherits Obstacle
class Rock : public Obstacle
{

private:

public:
	/// \brief Constructor from a position and a size
	/// \param position : the position of the Rock
	/// \param size : the size of the Rock
	Rock(const glm::vec3 &position = glm::vec3(0.0), const float &size = 0.0);

	/// \brief Destructor
	~Rock();

};

#endif