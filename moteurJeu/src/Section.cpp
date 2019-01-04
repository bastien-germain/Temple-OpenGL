#include "moteurJeu/Section.hpp"

Section::Section(
	const Model *model, 
	const unsigned int type,
	const unsigned int cornerDirection,
	const float &posZ, 
	const Obstacle &obstacle) 
	: _model(model), _obstacle(obstacle), _posZ(posZ), 
	_type(type), _cornerDirection(cornerDirection)
{
	if (_type > 2 || type < 0)
		THROW_EXCEPTION("INVALID SECTION INITIALISATION : NO MATCH FOR THAT KIND OF SECTION");
	if (_cornerDirection < - 1 || _cornerDirection > 1)
		THROW_EXCEPTION("INVALID SECTION INITIALISATION : INVALID DIRECTION");
	if (_type != 1 && _cornerDirection != 0)
		THROW_EXCEPTION("INVALID SECTION INITIALISATION : ONLY CORNERS HAVE A DIRECTION");
	if (_type == 1 && _cornerDirection == 0)
		THROW_EXCEPTION("INVALID SECTION INITIALISATION : CORNERS MUST HAVE A DIRECTION");
}

Section::Section(
	const Model *model, 
	const unsigned int type,
	const unsigned int cornerDirection, 
	const Obstacle &obstacle, 
	const float &posZ) 
	: _model(model), _obstacle(obstacle), 
	_posZ(posZ), _type(type), 
	_cornerDirection(cornerDirection)
{
	if (_type > 2 || type < 0)
		THROW_EXCEPTION("INVALID SECTION INITIALISATION : NO MATCH FOR THAT KIND OF SECTION");
	if (_cornerDirection < - 1 || _cornerDirection > 1)
		THROW_EXCEPTION("INVALID SECTION INITIALISATION : INVALID DIRECTION");
	if (_type != 1 && _cornerDirection != 0)
		THROW_EXCEPTION("INVALID SECTION INITIALISATION : ONLY CORNERS HAVE A DIRECTION");
	if (_type == 1 && _cornerDirection == 0)
		THROW_EXCEPTION("INVALID SECTION INITIALISATION : CORNERS MUST HAVE A DIRECTION");
}

Section::Section(const Section &copied) 
	: _model(copied._model), _obstacle(copied._obstacle), _posZ(copied._posZ),
	_type(copied._type), _cornerDirection(copied._cornerDirection)
{
}

Section::~Section() 
{
}