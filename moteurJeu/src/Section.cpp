#include <moteurJeu/Section.hpp>

Section::Section(const Model &model, const glm::vec2 &position, const float &size) 
				: _position(position), _size(size), _model(model)
{
}

Section::~Section() 
{
}
