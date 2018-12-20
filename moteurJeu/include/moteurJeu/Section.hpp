#pragma once
#ifndef __SECTION_HPP__
#define __SECTION_HPP__

#include <moteurJeu/Model.hpp>
#include <moteurJeu/Obstacle.hpp>


/// \class Section
/// \brief part of the path crossed by the player 

class Section 
{

protected:
	Model _model;
	Obstacle _obstacle; /*! The Obstacle present in the CorridorSection */
	bool _isT; /*! Tells wether the Section is a TSection or not */
	bool _isCorridor; /*! Tells wether the Section is a TSection or not */

public:
	/// \brief Default  constructor
	Section();

	/// \brief Constructor from a position and size
	/// \param model : the Model used for the Section
	Section(const Model &model, const Obstacle &obstacle = Obstacle());

	/// \brief Copy constructor
	/// \param copied : the Section copied
	Section(const Section &copied);

	/// \brief Destructor
	virtual ~Section();

	/// \brief Model getter 
	inline Model model() const 
	{
		return _model;
	}

	/// \brief isT getter 
	inline bool isT() const 
	{
		return _isT;
	}

	/// \brief isT getter 
	inline bool isCorridor() const 
	{
		return _isCorridor;
	}

	inline Obstacle obstacle() const 
	{
		return _obstacle;
	}





};

#endif