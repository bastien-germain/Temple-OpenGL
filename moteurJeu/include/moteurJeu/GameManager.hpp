#pragma once
#ifndef __GAME_MANAGER_HPP__
#define __GAME_MANAGER_HPP__

#include <vector>
#include <algorithm>
#include <random>

#include "moteurJeu/Player.hpp"
#include "moteurJeu/Skybox.hpp"
#include "moteurJeu/Enemy.hpp"
#include "moteurJeu/Section.hpp"
#include "moteurJeu/PositionObserver.hpp"
#include "moteurJeu/Factory.hpp"
#include "moteurJeu/Parser.hpp"
#include "moteurJeu/EventManager.hpp"
#include "moteurJeu/WorldGenerator.hpp"

#include "moteurRendu/Drawer.hpp"
#include "moteurRendu/TrackballCamera.hpp"
#include "moteurRendu/FreeflyCamera.hpp"



/// \class GameManager
/// \brief One try a the game
class GameManager : public PositionObserver
{

private:	
	Game _game;

	Player _player;
	Enemy _enemy;
	Skybox _skybox;

	const Parser _parser;
	WorldGenerator _worldGenerator;
	Factory _factory;
	Drawer _drawer;
	
	EventManager _eventManager;
	TrackballCamera _trackball;
	FreeflyCamera _fly;
	
public:
	GameManager();
	GameManager(const Program &program, const float &trackballSmoothness = 0.08);
	~GameManager();

	inline Enemy &enemy() 
	{
		return _enemy;
	}

	inline Player &player()
	{
		return _player;
	}
	inline Skybox &skybox()
	{
		return _skybox;
	}

	inline Game game() const 
	{
		return _game;
	}

	inline Drawer &drawer() 
	{
		return _drawer;
	}

	inline EventManager eventManager() const 
	{
		return _eventManager;
	}

	inline TrackballCamera trackball() const 
	{
		return _trackball;
	}

	inline FreeflyCamera fly() const 
	{
		return _fly;
	}

	

	/// \brief fill the section vector with returns from the factory
	void fillSectionVec(std::vector<std::string> &sectionDataStrings);
	inline WorldGenerator &worldGenerator() 
	{
		return _worldGenerator;
	}

	inline const Factory &factory() const 
	{
		return _factory;
	}

	inline const Parser &parser() const 
	{
		return _parser;
	}
	
	/// \brief observer on z position of obstacles, check collision with player
	void observerUpdate(PositionObservable *observable);	

	/// \brief test end of game
	bool isOver() const;

	inline void handleEvent(SDL_Event *event) 
	{
		_eventManager.handleEvent(event, _player, _trackball, _fly);
	}

	inline void deleteModelBuffers() {
		_factory.deleteModelBuffers();
	}
};

#endif