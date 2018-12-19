#pragma once
#ifndef __CORRIDOR_SECTION_HPP__
#define __CORRIDOR_SECTION_HPP__

#include <moteurJeu/Section.hpp>
#include <moteurJeu/Coin.hpp>
#include <vector>

/// \class CorridorSection
/// \brief Section that can contains an obstacle and coin
class CorridorSection : public Section
{

private:
	Obstacle _obstacle; /*! The Obstacle present in the CorridorSection */
	std::vector<Coin> _coins; 

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