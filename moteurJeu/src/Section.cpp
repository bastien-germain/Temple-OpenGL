#include <moteurJeu/Section.hpp>

Section::Section() 
{
}

Section::Section(const Model &model, const Obstacle &obstacle) : _model(model), _obstacle(obstacle)  
{
}

Section::Section(const Section &copied) 
	: _model(copied._model), _isT(copied._isT), _isCorridor(copied._isCorridor), _obstacle(copied._obstacle) 

{
}

Section::~Section() 
{
}
