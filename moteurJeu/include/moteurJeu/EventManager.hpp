#pragma once
#ifndef _EVENT_MANAGER_HPP
#define _EVENT_MANAGER_HPP

#include <iostream>

#include <SDL/SDL.h>

#include "glimac/glm.hpp"

#include "moteurJeu/Player.hpp"

#include "moteurRendu/TrackballCamera.hpp"


class EventManager
{
public:
	EventManager();

	~EventManager();
  
	void handleEvent(SDL_Event *event, Player &player, TrackballCamera &track);
	
	void onExit();
private:
	bool _mouseButtonDown;
	glm::vec2 _lastClickPosition;
	glm::vec2 _mouseMotionDelta;
};

#endif