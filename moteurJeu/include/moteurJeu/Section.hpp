#pragma once
#ifndef __SECTION_HPP__
#define __SECTION_HPP__

#include "moteurRendu/Model.hpp"
#include "moteurJeu/Obstacle.hpp"


/// \class Section
/// \brief part of the path crossed by the player 

class Section 
{
private:
	static int _rotateIndicator;
protected:
	const Model *_model;
	Obstacle _obstacle; /*! The Obstacle present in the CorridorSection */
	bool _isT; /*! Tells wether the Section is a TSection or not */
	bool _isCorridor; /*! Tells wether the Section is a Corridor or not */
	bool _isCorner; /*! Tells wether the Section is a CornerSection or not */
	float _posZ;

public:
	/// \brief Default  constructor
	Section();

	/// \brief Constructor from a model, obstacle and position
	/// \param model : the Model used for the Section
	/// \param onstacle : the obstacle of the Section
	/// \param posZ : the initial position of the Section
	Section(const Model *model, const float &posZ, const Obstacle &obstacle = Obstacle());

	/// \brief Constructor from a model and position
	/// \param model : the model used for the Section
	/// \param posZ : the initial position of the Section
	Section(const Model *model, const Obstacle &obstacle = Obstacle(), const float &posZ = 0.f);

	/// \brief Copy constructor
	/// \param copied : the Section copied
	Section(const Section &copied);

	/// \brief Destructor
	virtual ~Section();

	/// \brief Model getter 
	inline const Model* model() const 
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

	inline bool isCorner() const 
	{
		return _isCorner;
	}

	inline Obstacle obstacle() const 
	{
		return _obstacle;
	}

	inline float posZ() const 
	{
		return _posZ;
	}

	inline void goOn(const float &delta) 
	{
		_posZ += delta;
	}

	virtual unsigned int cornerDirection() const;

};

#endif