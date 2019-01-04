#include "moteurJeu/Enemy.hpp"

Enemy::Enemy() : _distanceToPlayer(2)
{
}

Enemy::Enemy(const Enemy &copied) : _distanceToPlayer(copied._distanceToPlayer)
{
}

Enemy::~Enemy() 
{

}

