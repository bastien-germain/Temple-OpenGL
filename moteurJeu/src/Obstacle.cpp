#include "moteurJeu/Obstacle.hpp"

Obstacle::Obstacle(
	const Model *model, 
	PositionObserver *observer, 
	const int posX, 
	const float posZ, 
	const int sizeX,
	const int sizeY)
	: _model(model), _posX(posX), _posZ(posZ), _sizeX(sizeX), _sizeY(sizeY), _hasCollided(false)
{
	addPositionObserver(observer);
}

Obstacle::Obstacle(const Obstacle &copied) 
	: PositionObservable(copied), _model(copied._model), 
	_posX(copied._posX), _posZ(copied._posZ), _sizeX(copied._sizeX), _sizeY(copied._sizeY), _hasCollided(copied._hasCollided)
{

}

Obstacle::~Obstacle() 
{

}

void Obstacle::collide()
{
	_hasCollided = true;
}
