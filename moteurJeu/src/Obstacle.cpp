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

float Obstacle::size() const
{
	return _size;
}

unsigned int Obstacle::posX() const
{
	return _posX;
}

float Obstacle::posZ() const
{
	return _posZ;
}

void Obstacle::proress(const float &delta) 
{
	_posZ += delta;
	notify();
}