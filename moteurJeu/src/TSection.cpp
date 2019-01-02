#include "moteurJeu/TSection.hpp"

TSection::TSection(const Model *model, const float &posZ) : Section(model, posZ)
{
	_isT = true;
	_isCorridor = false;
	_isCorner = false;

}

TSection::TSection(const TSection &copied) 
				: Section(copied)
{
}

TSection::~TSection() 
{
}

