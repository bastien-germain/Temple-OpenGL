#include "moteurJeu/Enemy.hpp"

Enemy::Enemy() : _distanceToPlayer(10)
{
}

Enemy::Enemy(const Enemy &copied) : _model(copied._model), _distanceToPlayer(copied._distanceToPlayer)
{
}

Enemy::~Enemy() 
{

}

void Enemy::bringCloser()
{
	_distanceToPlayer -= 5;
}

