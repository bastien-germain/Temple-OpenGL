#pragma once
#ifndef __SECTION_FACTORY_HPP__
#define __SECTION_FACTORY_HPP__

#include <iostream>
#include <string>
#include <moteurJeu/Exception.hpp>
#include <moteurJeu/CornerSection.hpp>
#include <moteurJeu/CorridorSection.hpp>
#include <moteurJeu/TSection.hpp>
#include <moteurJeu/Hole.hpp>
#include <moteurJeu/Rock.hpp>
#include <moteurJeu/Barrier.hpp>

/// \class SectionFactory
/// \brief Creates Section from input s
class SectionFactory 
{

private:
 	float _obstacleInitialPosZ;
public:
	/// \brief Default constructor
	SectionFactory(const float &obstacleInitialPosZ = 0.0);

	/// \brief Destructor
	~SectionFactory();

	inline const float obstacleInitialPosZ() const {
		return _obstacleInitialPosZ;
	}

	Obstacle obstacleBuiler(const std::string &key, PositionObserver *observer) const;

	/// \brief 
	Section create(const std::string &key, PositionObserver *observer) const;

};

#endif