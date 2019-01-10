#pragma once
#ifndef __WORLD_GENERATOR_HPP__
#define __WORLD_GENERATOR_HPP__

#include <vector>
#include <algorithm>
#include <random>

#include "moteurJeu/Section.hpp"
#include "moteurJeu/PositionObserver.hpp"
#include "moteurJeu/Factory.hpp"
#include "moteurJeu/Parser.hpp"

#include "moteurRendu/Drawer.hpp"

#define SECTIONS_NUMBER 10

/// \class WorldGenerator
/// \brief One try a the game
class WorldGenerator
{

private:
	unsigned int _offsetPosZCount;
	unsigned int _lastRotateIndex;
	int _rotateIndicator;
	bool _lastCornerRight;
	bool _penultimateCornerRight;

	std::vector<Section> _sectionVec;

	const std::string _sectionDataFilePath = "../Temple-OpenGL/app/assets/sectionsData/sectionsData.txt";

public:
	WorldGenerator();
	~WorldGenerator();

	inline std::vector<Section> &sectionVec()
	{
		return _sectionVec;
	}
	void placeSection(const unsigned int i);

	void generateInitialSections(PositionObserver *observer, const Factory &factory);

	void generateSection(PositionObserver *observer, const Factory &factory);

	void generateSectionsFromFile(PositionObserver *observer, const Factory &factory, const Parser &parser);

	std::string generateSectionData() const;

	/// \brief fill the section vector with returns from the factory
	void initSectionVec(std::vector<std::string> &sectionDataStrings);

	/// \brief load the sections data from the sectionDataFile
	void loadSections();

	/// \brief observer on z position of obstacles, check collision with player
	void observerUpdate(PositionObservable *observable);	

};

#endif