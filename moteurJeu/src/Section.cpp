#include <moteurJeu/Section.hpp>

Section::Section() 
{
}

Section::Section(const Model &model)  
{
}

Section::Section(const Section &copied) : _model(copied._model), _isT(copied._isT)  
{
}

Section::~Section() 
{
}
