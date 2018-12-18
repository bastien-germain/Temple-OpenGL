#include "moteurJeu/TSection.hpp"

TSection::TSection(const Model &model) : Section(model)
{
	_isT = true;
}

TSection::TSection(const TSection &copied) 
				: Section(copied.model())
{
}

TSection::~TSection() 
{
}

