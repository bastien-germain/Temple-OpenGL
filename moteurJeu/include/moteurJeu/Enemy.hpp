#pragma once
#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include <glimac/glm.hpp>

/// \class Enemy
/// \brief Class defining an Enemy
class Enemy 
{

private:
	glm::vec3 _position; /* Position of the Enemy */
	float _size; /*! Size of the Enemy */
	
public:
	/// \brief Constructor from a position and a size
	/// \param position : the position of the Enemy
	/// \param size : the size of the Enemy
	Enemy(const glm::vec3 &position = glm::vec3(0.0), const float &size = 0.0);

	/// \brief Copy constructor using another Enemy
	/// \param copied : the copied Enemy
	Enemy(const Enemy &copied);

	/// \brief Destructor
	~Enemy();

};

#endif