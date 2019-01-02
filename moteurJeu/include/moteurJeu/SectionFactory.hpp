#pragma once
#ifndef __SECTION_FACTORY_HPP__
#define __SECTION_FACTORY_HPP__

#include <iostream>
#include <string>

#include "moteurRendu/ModelLoader.hpp"

#include "moteurJeu/Exception.hpp"

#include "moteurJeu/CornerSection.hpp"
#include "moteurJeu/CorridorSection.hpp"
#include "moteurJeu/TSection.hpp"

#include "moteurJeu/Hole.hpp"
#include "moteurJeu/Rock.hpp"
#include "moteurJeu/Barrier.hpp"

/// \class SectionFactory
/// \brief Creates Section from input s
class SectionFactory 
{

private:
 	float _sectionInitialPosZ;
 	ModelLoader _modelLoader;
public:
 	Model _corridorModel;
 	Model _cornerModel;
 	Model _playerModel;

	/// \brief Default constructor
	SectionFactory(const float &sectionInitialPosZ = 0.0);

	/// \brief Destructor
	~SectionFactory();

	inline const float sectionInitialPosZ() const {
		return _sectionInitialPosZ;
	}

	Obstacle obstacleBuiler(const std::string &key, PositionObserver *observer) const;

	/// \brief 
	Section create(const std::string &key, PositionObserver *observer) const;

};

#endif