#include <moteurJeu/CorridorSection.hpp>

CorridorSection::CorridorSection(const Model &model, const Obstacle &obstacle) 
				: Section(model, obstacle)
{
	_isT = false;
	_isCorridor = true;
}

CorridorSection::CorridorSection(const CorridorSection &copied) : Section(copied)
{
}

CorridorSection::~CorridorSection() 
{
}