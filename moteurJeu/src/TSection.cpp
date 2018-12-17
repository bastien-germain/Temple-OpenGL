#include "moteurJeu/TSection.hpp"

TSection::TSection(const Model &model, const Obstacle &obstacle, const glm::vec2 &position, const float &size) 
				: Section(model, obstacle, position, size)
{
}

TSection::TSection(const TSection &copied) 
				: Section(copied.model(), copied.obstacle(), copied.position(), copied.size())
{
}

TSection::~TSection() 
{
}

