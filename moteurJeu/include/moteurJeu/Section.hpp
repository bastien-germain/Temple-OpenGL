#pragma once
#ifndef __SECTION_HPP__
#define __SECTION_HPP__

#include "moteurRendu/Model.hpp"
#include "moteurJeu/Obstacle.hpp"
#include "moteurJeu/Coin.hpp"


/// \class Section
/// \brief part of the path crossed by the player 

class Section 
{
private:	
	const Model *_model;
	Obstacle _obstacle; /*! The Obstacle present in the CorridorSection */
	std::vector<Coin> _coins;

	unsigned int _type; /*! 0 : corridor, 1 : corner, 2 : T */
	int _cornerDirection; /*! -1 : left, 0 : not a corner, 1 : right */
	bool _turned;

	float _posZ;
	float _posX;

public:
	/// \brief Default  constructor
	Section();

	/// \brief Constructor from a model, obstacle and position
	/// \param model : the Model used for the Section
	/// \param type : the type used for the Section
	/// \param posZ : the initial position of the Section
	/// \param obstacle : the obstacle of the Section
	Section(
		const Model *model, 
		const unsigned int type, 
		const int cornerDirection, 
		const Obstacle &obstacle = Obstacle()
		);

	/// \brief Copy constructor
	/// \param copied : the Section copied
	Section(const Section &copied);

	/// \brief Destructor
	~Section();

	/// \brief Model getter 
	inline const Model* model() const 
	{
		return _model;
	}

	inline bool isCorridor() const 
	{
		return _type == 0;
	}

	inline bool isCorner() const 
	{
		return _type == 1;
	}

	inline bool isT() const 
	{
		return _type == 2;
	}

	inline Obstacle obstacle() const 
	{
		return _obstacle;
	}

	inline float posZ() const 
	{
		return _posZ;
	}

	inline float posX() const 
	{
		return _posX;
	}

	inline void goOnZ(const float &delta) 
	{
		_posZ += delta;
		_obstacle.goOnZ(delta);
	}

	inline void goOnX(const float &delta)
	{
		_posX += delta;
	}

	inline void setZ(const float &value)
	{
		_posZ = value;
		_obstacle.setZ(value);
	}

	inline void setX(const float &value)
	{
		_posX = value;
	}

	inline int cornerDirection() const 
	{
		return _cornerDirection;
	}

	inline const bool hasTurned() const 
	{
		return _turned;
	}

	inline void turned()
	{
		_turned = true;
	}

	inline Section &operator = (const Section &toAssign) {

		if (&toAssign != this) 
		{
			_model = toAssign._model;
			_obstacle = toAssign._obstacle;
			_type = toAssign._type;
			_coins = toAssign._coins;
			_cornerDirection = toAssign._cornerDirection;
			_turned = toAssign._turned;
			_posZ = toAssign._posZ;
			_posX = toAssign._posX;

		}

		return *this;
	}

};

#endif