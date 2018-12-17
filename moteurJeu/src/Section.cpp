#include "moteurJeu/Section.hpp"

Section::Section(const glm::vec2 &position = glm::vec2(0.0), const float &size = 0.0, const Model &model, const Obstacle &obstacle) 
				: _position(position), _size(size), _model(model), _obstacle(obstacle)
{

}

Section::Section(const Section &copied) 
				: _position(copied._position), _size(copied._size), _model(copied._model), _obstacle(copied._obstacle)
{

}

Section::~Section() 
{

}
