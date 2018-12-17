#pragma once
#ifndef __HOLE_HPP__
#define __HOLE_HPP__

#include "Obstacle.hpp"

/// \class Hole
/// \brief Class defining a Hole (specific type of Obstacle) - inherits Obstacle
class Hole : public Obstacle
{

private:

public:
	/// \brief Constructor from a position and a size
	/// \param position : the position of the Hole
	/// \param size : the size of the Hole
	Hole(const glm::vec3 &position = glm::vec3(0.0), const float &size = 0.0);

	/// \brief Destructor
	~Hole();

};

#endif