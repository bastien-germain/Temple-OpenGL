#pragma once
#ifndef __CORNER_SECTION_HPP__
#define __CORNER_SECTION_HPP__

#include "Section.hpp"
#include "Exception.hpp"

/// \class CornerSection
/// \brief specific type of Section in which the player need to go in a specific side (right or left)
class CornerSection : public Section
{

private:
	int _cornerDirection; /*! The direction of the corner (left = -1, right = 1) */
public:
	/// \brief Constructor from a position and size
	/// \param model : the Model used for the CornerSection
	/// \param cornerDirection : the direction of the corner in the CornerSection (left = -1, right = 1)
	/// \exceptions INVALID_VALUE_ERROR : the value of _cornerDirection needs to be set to -1 (left) or 1 (right)
	CornerSection(const Model &model, const int &cornerDirection);

	/// \brief Copy constructor using another CornerSection
	/// \param copied : the copied CornerSection
	CornerSection(const CornerSection &copied);

	/// \brief Destructor
	~CornerSection();

};

#endif