#pragma once
#ifndef __SECTION_HPP__
#define __SECTION_HPP__

#include <moteurJeu/Model.hpp>

/// \class Section
/// \brief part of the path crossed by the player 

class Section 
{

protected:
	Model _model;
	bool _isT; /*! Tells wether the Section is a TSection or not */

public:
	/// \brief Default  constructor
	Section();

	/// \brief Constructor from a position and size
	/// \param model : the Model used for the Section
	Section(const Model &model);

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



};

#endif