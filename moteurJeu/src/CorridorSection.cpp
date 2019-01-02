#include "moteurJeu/CorridorSection.hpp"

CorridorSection::CorridorSection(const Model *model, const float &posZ, const Obstacle &obstacle) 
				: Section(model, posZ, obstacle)
{
	_isT = false;
	_isCorridor = true;
	_isCorner = false;
}

CorridorSection::CorridorSection(const Model *model, const Obstacle &obstacle, const float &posZ)
				: Section(model, obstacle, posZ)
{
	_isT = false;
	_isCorridor = true;
	_isCorner = false;
}

CorridorSection::CorridorSection(const CorridorSection &copied) : Section(copied)
{
}

CorridorSection::~CorridorSection() 
{
}

