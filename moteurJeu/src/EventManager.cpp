#include "moteurJeu/EventManager.hpp"

EventManager::EventManager() : _mouseButtonDown(false), _lastClickPosition(glm::vec2(0)), _mouseMotionDelta(glm::vec2(0))
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
    	case SDL_KEYDOWN:
            switch(event->key.keysym.sym){

            	// JUMP
                case SDLK_z:
                    break;
                case SDLK_UP:
                    break;

                // MOVE LEFT
                case SDLK_q:
                    break;
                case SDLK_LEFT:
                    break;

                // LOWER
                case SDLK_s:
                    break;
                case SDLK_DOWN:
                    break;

                // MOVE RIGHT
                case SDLK_d:
                    break;
                case SDLK_RIGHT:
                    break;

                // PAUSE
                case SDLK_ESCAPE:
                    break;
                

                default:
                    break;
    	}
    		break;
    	case SDL_MOUSEBUTTONDOWN:
    		if (event->button.type == SDL_BUTTON_LEFT) 
    		{
	    		_mouseButtonDown = true;
	    		_lastClickPosition = glm::vec2(event->button.x, event->button.y);
    		}
    		break;
    	case SDL_MOUSEBUTTONUP:
    		if (event->button.type == SDL_BUTTON_LEFT) 
    		{
	    		_mouseButtonDown = false;
	    		_mouseMotionDelta = glm::vec2(0);
    		}
    		break;
    	case SDL_MOUSEMOTION:
    		if (_mouseButtonDown) 
    		{
    			_mouseMotionDelta.x = event->button.x - _lastClickPosition.x;
    			_mouseMotionDelta.y = event->button.y - _lastClickPosition.y;
    		}
    		break;
    }	
}

void onExit() {}