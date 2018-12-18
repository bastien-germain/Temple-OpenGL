#include "moteurJeu/EventManager.hpp"

EventManager::EventManager() 
{
}

EventManager::~EventManager()
{
}

void EventManager::handleEvent(SDL_Event *event)
{
  switch (event->type)
    {
    	case SDL_QUIT:
    		onExit();
    		break;
    }
}

void onExit() {}