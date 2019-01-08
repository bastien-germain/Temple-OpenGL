#include "moteurJeu/Obstacle.hpp"

Obstacle::Obstacle(
	const Model *model, 
	PositionObserver *observer, 
	const int posX, 
	const float posZ, 
	const unsigned int size) 
	: _model(model), _posX(posX), _posZ(posZ), _size(size)
{
	addPositionObserver(observer);
}

Obstacle::Obstacle(const Obstacle &copied) 
	: PositionObservable(copied), _model(copied._model), 
	_posX(copied._posX), _posZ(copied._posZ), _size(copied._size)
{

}

Obstacle::~Obstacle() 
{

}
