#pragma once
#ifndef __SECTION_HPP__
#define __SECTION_HPP__

#include <glimac/glm.hpp>
#include <moteurJeu/Obstacle.hpp>
#include <moteurJeu/Model.hpp>

/// \class Section
/// \brief Class defining a Section : 
///  - A Section is an area that can be crossed by the player ;
///  - Each Section contains only one Obstacle ;
class Section 
{

private:
	glm::vec2 _position; /*! Position of the Section in the Section matrix */
	const float _size; /*! Size of the Section (const) */
	Model _model; /*! Model used for the Section */
	Obstacle _obstacle; /*! The Obstacle present in the Section */

public:
	/// \brief Constructor from a position and size
	/// \param position : the position of the Section
	/// \param position : the size of the Section
	Section(const glm::vec2 &position = glm::vec2(0.0), const float &size = 0.0, const Model &model, const Obstacle &obstacle);

	/// \brief Copy constructor using another Section
	/// \param copied : the copied Section
	Section(const Section &copied);

	/// \brief Destructor
	//~Section();

};

#endif