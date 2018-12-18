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
                	std::cout << "JUMP" << std::endl;
                    break;
                case SDLK_UP:
                	std::cout << "JUMP" << std::endl;
                    break;

                // MOVE LEFT
                case SDLK_q:
                	std::cout << "MOVE LEFT" << std::endl;
                    break;
                case SDLK_LEFT:
                	std::cout << "MOVE LEFT" << std::endl;
                    break;

                // LOWER
                case SDLK_s:
                	std::cout << "LOWER" << std::endl;
                    break;
                case SDLK_DOWN:
                	std::cout << "LOWER" << std::endl;
                    break;

                // MOVE RIGHT
                case SDLK_d:
                	std::cout << "MOVE RIGHT" << std::endl;
                    break;
                case SDLK_RIGHT:
                	std::cout << "MOVE RIGHT" << std::endl;
                    break;

                // PAUSE
                case SDLK_ESCAPE:
                	std::cout << "ESCAPE" << std::endl;
                    break;
                

                default:
                    break;
    	}
    		break;
    	case SDL_MOUSEBUTTONDOWN:
    		if (event->button.button == SDL_BUTTON_LEFT) 
    		{
	    		_mouseButtonDown = true;
	    		_lastClickPosition = glm::vec2(event->button.x, event->button.y);
    		}
	    	std::cout << _mouseButtonDown << std::endl;
    		break;
    	case SDL_MOUSEBUTTONUP:
    		if (event->button.button == SDL_BUTTON_LEFT) 
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
    			std::cout << "mouseMotionDelta X : " << _mouseMotionDelta.x << " | mouseMotionDelta Y : " << _mouseMotionDelta.y << std::endl;
    		}
    		break;
    }	
}

void EventManager::onExit() {
	exit(0);
}