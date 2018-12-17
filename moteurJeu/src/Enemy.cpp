#include "moteurJeu/Enemy.hpp"

Enemy::Enemy(const glm::vec3 &position, const float &size) : _position(position), _size(size)
{

}

Enemy::Enemy(const Enemy &copied) : _position(copied._position), _size(copied._size)
{

}

Enemy::~Enemy() 
{

}
