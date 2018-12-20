#pragma once
#ifndef __GAME_MANAGER_HPP__
#define __GAME_MANAGER_HPP__

#include "moteurJeu/Game.hpp"
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
	const char * _sectionsDataFilePath = "../Temple-OpenGL/moteurJeu/sectionsData/sectionsData.txt";
	Game _game;
	Player _player;
	Enemy _enemy;
	Parser _parser; 
	SectionFactory _factory;
	std::vector<Section> _sectionVec;
	std::vector<std::vector<Section>> _sectionMat;
	
public:
	GameManager(const float &obstacleInitialPosZ = 0.0);
	~GameManager();

	inline Enemy enemy() const {
		return _enemy;
	}

	inline Player player() const {
		return _player;
	}

	inline std::vector<std::vector<Section>> sectionMat() const {
		return _sectionMat;
	}

	inline Game game() const {
		return _game;
	}

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

	/// \brief test end of game
	bool isOver() const;
};

#endif