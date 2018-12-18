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
	/// \param model : the Model used for the CorridorSection
	/// \param obstacle : the Obstacle present in the CorridorSection
	CorridorSection(const Model &model, const Obstacle &obstacle);

	/// \brief Destructor
	~CorridorSection();

	/// \brief Getter : Obstacle getter 
	inline Obstacle obstacle() const 
	{
		return _obstacle;
	}



};

#endif