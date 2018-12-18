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
	Barrier(const unsigned int position = 0, const unsigned int size = 0);

	/// \brief Destructor
	~Barrier();

};

#endif