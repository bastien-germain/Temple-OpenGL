#include "moteurJeu/TSection.hpp"

TSection::TSection(const Model &model, const glm::vec2 &position, const float &size) 
				: Section(model, position, size)
{
}

TSection::TSection(const TSection &copied) 
				: Section(copied.model(), copied.position(), copied.size())
{
}

TSection::~TSection() 
{
}

