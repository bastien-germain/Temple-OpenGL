#include "moteurJeu/Obstacle.hpp"

Obstacle::Obstacle(const glm::vec3 &position, const float &size) : _position(position), _size(size)
{

}


Obstacle::Obstacle(const Obstacle &copied) : _position(copied._position), _size(copied._size)
{

}

Obstacle::~Obstacle() 
{

}
