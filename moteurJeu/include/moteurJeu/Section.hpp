#pragma once
#ifndef __SECTION_HPP__
#define __SECTION_HPP__

#include <glimac/glm.hpp>
#include <moteurJeu/Obstacle.hpp>
#include <moteurJeu/Model.hpp>

/// \class Section
/// \brief Class defining a Section
///  - A Section is an area that can be crossed by the player ;
///  - Each Section contains only one Obstacle ;
class Section 
{

private:
	glm::vec2 _position; /*! Position of the Section in the Section matrix */
	float _size; /*! Size of the Section (const) */
	Model _model; /*! Model used for the Section */
	Obstacle _obstacle; /*! The Obstacle present in the Section */

public:
	/// \brief Constructor from a position and size
	/// \param position : the position of the Section
	/// \param size : the size of the Section
	/// \param model : the model used for the Section
	/// \param obstacle : the Obstacle present in the Section
	Section(const Model &model, const Obstacle &obstacle, const glm::vec2 &position = glm::vec2(0.0), const float &size = 0.0);

	/// \brief Destructor
	~Section();

	/// \brief Getter : position getter 
	inline glm::vec2 position() const 
	{
		return _position;
	}

	/// \brief Getter : size getter 
	inline float size() const 
	{
		return _size;
	}

	/// \brief Getter : Model getter 
	inline Model model() const 
	{
		return _model;
	}

	/// \brief Getter : Obstacle getter 
	inline Obstacle obstacle() const 
	{
		return _obstacle;
	}



};

#endif