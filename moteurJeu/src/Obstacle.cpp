#include "moteurJeu/Obstacle.hpp"

Obstacle::Obstacle(PositionObserver *observer, const unsigned int posX, const float posZ, const unsigned int size) : _posX(posX), _posZ(posZ), _size(size)
{
	addPositionObserver(observer);
}

Obstacle::Obstacle(const Obstacle &copied) : PositionObservable(copied), _posX(copied._posX), _posZ(copied._posZ), _size(copied._size)
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

void Obstacle::progress(const float &delta) 
{
	std::cout << "*** OBSTACLE PROGRESS TRY" << std::endl;
	std::cout << "*** SIZE : " << _size << std::endl;
	if (_size != 0) 
	{
		std::cout << "*** OBSTACLE PROGRESS" << std::endl;
		_posZ += delta;
		std::cout << "*** POSITION CHANGED" << std::endl;
		notify();
	}
}