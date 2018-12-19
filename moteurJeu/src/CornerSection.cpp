#include "moteurJeu/CornerSection.hpp"	

CornerSection::CornerSection(const Model &model, const int &cornerDirection) 
				: Section(model)
{
	std::cout << " *** CORRIDOR VALUE-BASED CONSTRUCTOR" << std::endl;

	if((cornerDirection != -1) && (cornerDirection != 1)) 
	{
		THROW_EXCEPTION("INVALID_VALUE_ERROR - CornerSection() in CornerSection.cpp : cornerDirection needs to be set to -1 or 1.");
	}

	_cornerDirection = cornerDirection;
	_isT = false;
}

CornerSection::CornerSection(const CornerSection &copied) 
				: Section(copied.model())
{
}

CornerSection::~CornerSection() 
{
}
