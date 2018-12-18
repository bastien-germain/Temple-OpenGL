#pragma once
#ifndef _EVENT_MANAGER_HPP
#define _EVENT_MANAGER_HPP

#include <SDL/SDL.h>

class EventManager
{
public:
	EventManager();

	~EventManager();
  
	void handleEvent(SDL_Event *);
	
	void onExit();
};

#endif