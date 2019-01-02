#include "moteurJeu/CornerSection.hpp"	

CornerSection::CornerSection(const Model *model, const int &cornerDirection, const float &posZ) 
				: Section(model, posZ)
{
	if((cornerDirection != -1) && (cornerDirection != 1)) 
	{
		THROW_EXCEPTION("INVALID_VALUE_ERROR - CornerSection() in CornerSection.cpp : cornerDirection needs to be set to -1 or 1.");
	}

	_cornerDirection = cornerDirection;
	_isT = false;
	_isCorridor = false;
	_isCorner = true;
}

CornerSection::CornerSection(const CornerSection &copied) 
				: Section(copied.model()), _cornerDirection(copied._cornerDirection)
{
}

CornerSection::~CornerSection() 
{
}

