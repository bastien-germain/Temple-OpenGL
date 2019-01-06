#pragma once
#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include <string>

#include "moteurRendu/ModelLoader.hpp"

#include "moteurJeu/Exception.hpp"

#include "moteurJeu/Section.hpp"
#include "moteurJeu/Obstacle.hpp"

/// \class Factory
/// \brief Creates Section from input string
class Factory 
{

private:
 	float _sectionInitialPosZ;
 	ModelLoader _modelLoader;

 	Model _playerModel;
 	Model _enemyModel;

 	Model _corridorModel;
 	Model _cornerLeftModel;
 	Model _cornerRightModel;
 	Model _tModel;

 	Model _deambuleModel;
 	Model _clapTrapModel;
 	Model _chairsStackModel;
 	Model _brancardModel;

 	Model _skyboxModel;

 	Model _bonusModel;

public:

	/// \brief Default constructor
	Factory(const float &sectionInitialPosZ = 0.0);

	/// \brief Destructor
	~Factory();

	inline const float sectionInitialPosZ() const 
	{
		return _sectionInitialPosZ;
	}

	Obstacle obstacleBuiler(const std::string &key, PositionObserver *observer) const;

	/// \brief 
	Section create(const std::string &key, PositionObserver *observer) const;

	void deleteModelBuffers();

	inline Model *playerModel() 
	{
		return &_playerModel;
	}
};

#endif