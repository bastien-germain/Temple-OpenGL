#include "moteurJeu/CornerSection.hpp"	

CornerSection::CornerSection(const Model &model, const int &cornerDirection, const glm::vec2 &position, const float &size) 
				: Section(model, position, size)
{
	if((cornerDirection != -1) || (cornerDirection != 1)) 
	{
		THROW_EXCEPTION("INVALID_VALUE_ERROR - CornerSection() in CornerSection.cpp : cornerDirection needs to be set to -1 or 1.");
	}

	_cornerDirection = cornerDirection;
}

CornerSection::CornerSection(const CornerSection &copied) 
				: Section(copied.model(), copied.position(), copied.size())
{
}

CornerSection::~CornerSection() 
{
}
