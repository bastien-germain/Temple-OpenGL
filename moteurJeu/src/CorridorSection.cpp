#include <moteurJeu/CorridorSection.hpp>

CorridorSection::CorridorSection(const Model &model, const Obstacle &obstacle, const glm::vec2 &position, const float &size) 
				: Section(model, position, size), _obstacle(obstacle)
{
}

CorridorSection::~CorridorSection() 
{
}
