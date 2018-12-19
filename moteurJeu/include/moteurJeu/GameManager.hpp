#pragma once
#ifndef __GAME_MANAGER_HPP__
#define __GAME_MANAGER_HPP__

#include "moteurJeu/Player.hpp"
#include "moteurJeu/Enemy.hpp"
#include "moteurJeu/Section.hpp"
#include "moteurJeu/PositionObserver.hpp"
#include "moteurJeu/SectionFactory.hpp"
#include "moteurJeu/Parser.hpp"
#include <vector>
#include <algorithm>


/// \class GameManager
/// \brief One try a the game
class GameManager : public PositionObserver
{

private:
	const char * _sectionsDataFilePath = "../../sectionsData/sectionsData.txt";
	Player _player;
	Enemy _enemy;
	Parser _parser; 
	SectionFactory _factory;
	std::vector<Section> _sectionVec;
	std::vector<std::vector<Section>> _sectionMat;
	
public:
	GameManager();
	~GameManager();

	inline Enemy enemy() const {
		return _enemy;
	}

	inline Player player() const {
		return _player;
	}

	/// \brief test end of game
	bool isOver() const;


	/// \brief fill the section vector with returns from the factory
	void fillSectionVec(std::vector<std::string> &sectionDataStrings);

	/// \brief read section vector and fill the matrix handling T section
	void fillSectionMat();

	/// \brief update section matrix when player has chosen a side
	/// \param isLeft : boolean, test if chosen side is left
	void updateSectionMat(const bool isLeft);

	/// \brief load the sections data from the sectionDataFile
	void loadSections();

	void observerUpdate(const PositionObservable *observable) const;	
};

#endif