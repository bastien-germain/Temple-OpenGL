#include <moteurJeu/CorridorSection.hpp>

CorridorSection::CorridorSection(const Model &model, const Obstacle &obstacle) 
				: Section(model), _obstacle(obstacle)
{
	_isT = false;
}

CorridorSection::~CorridorSection() 
{
}
