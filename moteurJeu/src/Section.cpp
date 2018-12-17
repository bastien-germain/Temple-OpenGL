#include "moteurJeu/Section.hpp"

Section::Section(const Model &model, const Obstacle &obstacle, const glm::vec2 &position, const float &size) 
				: _position(position), _size(size), _model(model), _obstacle(obstacle)
{

}

Section::~Section() 
{

}
