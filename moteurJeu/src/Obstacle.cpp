#include "moteurJeu/Obstacle.hpp"

Obstacle::Obstacle(const unsigned int position, const unsigned int size) : _position(position), _size(size)
{

}


Obstacle::Obstacle(const Obstacle &copied) : _position(copied.position()), _size(copied.size())
{

}

Obstacle::~Obstacle() 
{

}
