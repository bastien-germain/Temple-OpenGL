#include "moteurJeu/Obstacle.hpp"

Obstacle::Obstacle(
	const Model *model, 
	PositionObserver *observer, 
	const int posX, 
	const float posZ, 
	const unsigned int sizeX) 
	: _model(model), _posX(posX), _posZ(posZ), _sizeX(sizeX)
{
	addPositionObserver(observer);
}

Obstacle::Obstacle(const Obstacle &copied) 
	: PositionObservable(copied), _model(copied._model), 
	_posX(copied._posX), _posZ(copied._posZ), _sizeX(copied._sizeX)
{

}

Obstacle::~Obstacle() 
{

}
