#pragma once
#ifndef __Skybox_HPP__
#define __Skybox_HPP__

#include <cmath>

#include "moteurRendu/ModelLoader.hpp"
#include "moteurJeu/Factory.hpp"

/// \class Player
/// \brief Class defining the main player
class Skybox
{

private:
	float _posX; // -1 : left; 0 : middle; 1: right
	float _posY; // -1 : down; 0 : regular; 1: up
	float _posZ; // position of the player, to which the obstacle posZ will be compared
	Model *_model;
public:

	/// \brief Constructor
	Skybox();

	Skybox(const Skybox &copied);

	/// \brief Destructor
	~Skybox();


	inline float posZ() const 
	{
		return _posZ;
	}

	inline float posX() const 
	{
		return _posX;
	}

	inline float posY() const 
	{
		return _posY;
	}

	inline const Model *model() const 
	{
		return _model;
	}

	inline void model(Model *model) {
		_model = model;
	}

};

#endif