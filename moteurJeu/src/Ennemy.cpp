#include "moteurJeu/Ennemy.hpp"

Ennemy::Ennemy(const glm::vec3 &position, const float &size) : _position(position), _size(size)
{

}


Ennemy::Ennemy(const Ennemy &copied) : _position(copied._position), _size(copied._size)
{

}

Ennemy::~Ennemy() 
{

}
