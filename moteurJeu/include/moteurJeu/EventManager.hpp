#pragma once
#ifndef _EVENT_MANAGER_HPP
#define _EVENT_MANAGER_HPP

#include <SDL/SDL.h>
#include <glimac/glm.hpp>

class EventManager
{
public:
	EventManager();

	~EventManager();
  
	void handleEvent(SDL_Event *);
	
	void onExit();
private:
	bool _mouseButtonDown;
	glm::vec2 _lastClickPosition;
	glm::vec2 _mouseMotionDelta;
};

#endif