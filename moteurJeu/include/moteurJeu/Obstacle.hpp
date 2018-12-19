#pragma once
#ifndef __OBSTACLE_HPP__
#define __OBSTACLE_HPP__

#include <glimac/glm.hpp>
#include <moteurJeu/PositionObservable.hpp>

/// \class Obstacle
/// \brief Class defining an Obstacle
class Obstacle : public PositionObservable
{

private:
	unsigned int _posX; /* X position of the Obstacle */
	float _posZ; /* Z position of the Obstacle */
	unsigned int _size; /*! Size of the Obstacle */
	
public:
	/// \brief Constructor from a position and a size
	/// \param position : the position of the Obstacle
	/// \param size : the size of the Obstacle
	Obstacle(const unsigned int posX = 0, const float posZ = 0, const unsigned int size = 0);

	/// \brief Copy constructor using another Obstacle
	/// \param copied : the copied Obstacle
	Obstacle(const Obstacle &copied);

	/// \brief Destructor
	~Obstacle();

	/// \brief Getter : size getter
	float size() const; 

	/// \brief Getter : posX getter
	unsigned int posX() const;

	/// \brief Getter : posZ getter
	float posZ() const;

	/// \brief posZ modifier when the Obstalce progresses along Z axis
	void progress(const float &delta);

};

#endif