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

protected:
	Model _model; /*! Model used for the Section */
	bool _isT; /*! Tells wether the Section is a TSection or not */
public:
	/// \brief Default  constructor
	Section();

	/// \brief Constructor from a position and size
	/// \param model : the Model used for the Section
	Section(const Model &model);

	/// \brief Destructor
	virtual ~Section();

	/// \brief Getter : Model getter 
	inline Model model() const 
	{
		return _model;
	}

	/// \brief Getter : isT getter 
	inline bool isT() const 
	{
		return _isT;
	}



};

#endif