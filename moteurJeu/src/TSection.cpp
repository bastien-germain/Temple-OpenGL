#include "moteurJeu/TSection.hpp"

TSection::TSection(const Model &model) : Section(model)
{
	_isT = true;
	_isCorridor = false;

}

TSection::TSection(const TSection &copied) 
				: Section(copied)
{
}

TSection::~TSection() 
{
}

