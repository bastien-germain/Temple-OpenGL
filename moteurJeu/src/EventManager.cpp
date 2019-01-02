#include "moteurJeu/EventManager.hpp"

EventManager::EventManager() 
    : _mouseButtonDown(false), _lastClickPosition(glm::vec2(0)), _mouseMotionDelta(glm::vec2(0))
{
}

EventManager::~EventManager()
{
}

void EventManager::handleEvent(SDL_Event *event, Player &player, TrackballCamera &track)
{
    std::cout << "handleEvent()" << std::endl;

    switch (event->type)
    {
        case SDL_QUIT:
            onExit();
            break;

        case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
            {
            	// JUMP
                case SDLK_z:
                    if (!player._jumping && !player._landing)
                        player._jumping = true;
                    break;
                 case SDLK_UP:
                    if (!player._jumping && !player._landing)
                        player._jumping = true;
                    break;

                // MOVE LEFT
                case SDLK_q:
                    player.goLeft();
                    break;
                case SDLK_LEFT:
                    player.goLeft();
                    break;

                // LOWER
                case SDLK_s:
                    if (!player._bending && !player._landing)
                        player._bending = true;
                    break;
                case SDLK_DOWN:
                    if (!player._bending && !player._landing)
                        player._bending = true;
                    break;

                // MOVE RIGHT
                case SDLK_d:
                    player.goRight();
                    break;
                case SDLK_RIGHT:
                    player.goRight();
                    break;

                // ZOOM
                case SDLK_a:
                    std::cout << "track move front" << std::endl;
                    track.moveFront(track.smoothness());
                    break;
                case SDLK_e: 
                    track.moveFront(-track.smoothness());
                    break;

                default:
                    break;
    	   }
    	   break;

        case SDL_KEYUP:
            player.goCenter();
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
                track.rotateLeft(track.smoothness() * _mouseMotionDelta.x);
                track.rotateUp(track.smoothness() * _mouseMotionDelta.y);
    		}
    		break;
    }

    if (player._jumping)
        player.jump();
    if (player._landing)
        player.land();
    if (player._bending)
        player.bendDown();
}

void EventManager::onExit() {
	exit(0);
}