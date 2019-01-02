#pragma once
#ifndef __T_SECTION_HPP__
#define __T_SECTION_HPP__

#include "moteurJeu/Section.hpp"

/// \class TSection
/// \brief specific type of Section in which the player can choose to turn left or right
class TSection : public Section
{

private:

public:
	/// \brief Constructor from a position and size
	/// \param model : the Model used for the TSection
	TSection(const Model *model, const float &posZ = 0.f);

	/// \brief Copy constructor using another TSection
	/// \param copied : the copied TSection
	TSection(const TSection &copied);

	/// \brief Destructor
	~TSection();

	inline unsigned int cornerDirection() const
	{
		return 0;
	}

};

#endif