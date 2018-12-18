#include "moteurJeu/Obstacle.hpp"

Obstacle::Obstacle(const unsigned int posX, const float posZ, const unsigned int size) : _posX(posX), _posZ(posZ), _size(size)
{

}

Obstacle::Obstacle(const Obstacle &copied) : _posX(copied._posX), _posZ(copied._posZ),  _size(copied._size)
{

}

Obstacle::~Obstacle() 
{

}
