#pragma once
#ifndef __CORNER_SECTION_HPP__
#define __CORNER_SECTION_HPP__

#include "Section.hpp"
#include "Exception.hpp"

/// \class CornerSection
/// \brief Class defining a CornerSection 
/// 	- A specific type of Section which looks like a corner/curve ;
class CornerSection : public Section
{

private:
	int _cornerDirection; /*! The direction of the corner (left = -1, right = 1) */

public:
	/// \brief Constructor from a position and size
	/// \param position : the position of the CornerSection
	/// \param size : the size of the CornerSection
	/// \param model : the Model used for the CornerSection
	/// \param obstacle : the Obstacle present in the CornerSection
	/// \param cornerDirection : the direction of the corner in the CornerSection (left = -1, right = 1)
	/// \exceptions INVALID_VALUE_ERROR : the value of _cornerDirection needs to be set to -1 (left) or 1 (right)
	CornerSection(const Model &model, const int &cornerDirection, const glm::vec2 &position = glm::vec2(0.0), const float &size = 0.0);

	/// \brief Copy constructor using another CornerSection
	/// \param copied : the copied CornerSection
	CornerSection(const CornerSection &copied);

	/// \brief Destructor
	~CornerSection();

};

#endif