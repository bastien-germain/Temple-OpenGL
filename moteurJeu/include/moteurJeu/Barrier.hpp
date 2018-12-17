#pragma once
#ifndef __BARRIER_HPP__
#define __BARRIER_HPP__

#include "Obstacle.hpp"

/// \class Barrier
/// \brief Class defining a Barrier (specific type of Obstacle) - inherits Obstacle
class Barrier : public Obstacle
{

private:

public:
	/// \brief Constructor from a position and a size
	/// \param position : the position of the Barrier
	/// \param size : the size of the Barrier
	Barrier(const glm::vec3 &position = glm::vec3(0.0), const float &size = 0.0);

	/// \brief Destructor
	~Barrier();

};

#endif