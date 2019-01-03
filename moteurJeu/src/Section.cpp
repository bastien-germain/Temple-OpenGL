#include "moteurJeu/Section.hpp"

Section::Section() 
{
	std::cout << "sec def const" << std::endl;
}

Section::Section(const Model *model, const float &posZ, const Obstacle &obstacle) 
	: _model(model), _obstacle(obstacle), _posZ(posZ)
{
	std::cout << "sec 1 const" << std::endl;
}

Section::Section(const Model *model, const Obstacle &obstacle, const float &posZ) 
	: _model(model), _obstacle(obstacle), _posZ(posZ)
{
	std::cout << "sec 2 const" << std::endl;
}

Section::Section(const Section &copied) 
	: _model(copied._model), _isT(copied._isT), _isCorridor(copied._isCorridor), _obstacle(copied._obstacle), _posZ(copied._posZ)

{
}

Section::~Section() 
{
}

unsigned int Section::cornerDirection() const 
{
}