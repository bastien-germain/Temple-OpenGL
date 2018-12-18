#pragma once
#ifndef __SECTION_FACTORY_HPP__
#define __SECTION_FACTORY_HPP__

#include <iostream>
#include <string>
#include <moteurJeu/Exception.hpp>
#include <moteurJeu/Section.hpp>
#include <moteurJeu/CornerSection.hpp>
#include <moteurJeu/CorridorSection.hpp>
#include <moteurJeu/TSection.hpp>
#include <moteurJeu/Obstacle.hpp>
#include <moteurJeu/Hole.hpp>
#include <moteurJeu/Rock.hpp>
#include <moteurJeu/Barrier.hpp>

/// \class SectionFactory
/// \nrief Creates Section from input s
class SectionFactory 
{

private:

public:
	/// \brief Default constructor
	SectionFactory();

	/// \brief Destructor
	~SectionFactory();

	/// \brief 
	Section create(const std::string &key) const;


};

#endif