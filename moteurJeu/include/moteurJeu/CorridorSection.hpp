#pragma once
#ifndef __CORRIDOR_SECTION_HPP__
#define __CORRIDOR_SECTION_HPP__

#include <moteurJeu/Section.hpp>

/// \class CorridorSection
/// \brief Class defining a CorridorSection
///  - A CorridorSection is an area that can be crossed by the player ;
///  - Each CorridorSection contains only one Obstacle ;
class CorridorSection : public Section
{

private:
	Obstacle _obstacle; /*! The Obstacle present in the CorridorSection */

public:
		/// \brief Constructor from a position and size
	/// \param position : the position of the CorridorSection
	/// \param size : the size of the CorridorSection
	/// \param model : the model used for the CorridorSection
	/// \param obstacle : the Obstacle present in the CorridorSection
	CorridorSection(const Model &model, const Obstacle &obstacle, const glm::vec2 &position = glm::vec2(0.0), const float &size = 0.0);

	/// \brief Destructor
	~CorridorSection();

	/// \brief Getter : Obstacle getter 
	inline Obstacle obstacle() const 
	{
		return _obstacle;
	}



};

#endif