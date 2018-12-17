#pragma once
#ifndef __T_SECTION_HPP__
#define __T_SECTION_HPP__

#include "Section.hpp"

/// \class TSection
/// \brief Class defining a TSection 
///  - A specific type of Section in which the player can choose to turn left or right ;
class TSection : public Section
{

private:

public:
	/// \brief Constructor from a position and size
	/// \param position : the position of the TSection
	/// \param size : the size of the TSection
	/// \param model : the Model used for the TSection
	/// \param obstacle : the Obstacle present in the TSection
	TSection(const Model &model, const Obstacle &obstacle, const glm::vec2 &position = glm::vec2(0.0), const float &size = 0.0);

	/// \brief Copy constructor using another TSection
	/// \param copied : the copied TSection
	TSection(const TSection &copied);

	/// \brief Destructor
	~TSection();

};

#endif