#pragma once
#ifndef __ENNEMY_HPP__
#define __ENNEMY_HPP__

#include <glimac/glm.hpp>

/// \class Ennemy
/// \brief Class defining an Ennemy
class Ennemy 
{

private:
	glm::vec3 _position; /* Position of the Ennemy */
	float _size; /*! Size of the Ennemy */
	
public:
	/// \brief Constructor from a position and a size
	/// \param position : the position of the Ennemy
	/// \param size : the size of the Ennemy
	Ennemy(const glm::vec3 &position = glm::vec3(0.0), const float &size = 0.0);

	/// \brief Copy constructor using another Ennemy
	/// \param copied : the copied Ennemy
	Ennemy(const Ennemy &copied);

	/// \brief Destructor
	~Ennemy();

};

#endif