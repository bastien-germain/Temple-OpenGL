#pragma once
#ifndef _EVENT_MANAGER_HPP
#define _EVENT_MANAGER_HPP

#include <iostream>

#include <SDL/SDL.h>

#include "glimac/glm.hpp"

#include "moteurJeu/Player.hpp"

#include "moteurRendu/TrackballCamera.hpp"
#include "moteurRendu/FreeflyCamera.hpp"


class EventManager
{
public:
	EventManager();

	~EventManager();
  
	void handleEvent(SDL_Event *event, Player &player, TrackballCamera &track, FreeflyCamera &fly);
	
	void onExit();

	inline bool camTrack()
	{
		return _camTrack;
	}
private:
	bool _mouseButtonDown;
	bool _camTrack;
	bool _camLocked;
	bool _tempLock;
	bool _changeCam;
	glm::vec2 _lastClickPosition;
	glm::vec2 _mouseMotionDelta;

	
};

#endif