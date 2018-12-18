#include "moteurJeu/EventManager.hpp"

int main(int argc, char const *argv[])
{
	SDL_Event event;
	EventManager manager;
                
        /* Initialise SDL */
        if( SDL_Init( SDL_INIT_VIDEO ) < 0){
            fprintf( stderr, "Could not initialise SDL: %s\n", SDL_GetError() );
            exit( -1 );
        }

        /* Set a video mode */
        if( !SDL_SetVideoMode( 320, 200, 0, 0 ) ){
            fprintf( stderr, "Could not set video mode: %s\n", SDL_GetError() );
            SDL_Quit();
            exit(-1);
        }

        /* Enable Unicode translation */
        SDL_EnableUNICODE( 1 );

        /* Loop until an SDL_QUIT event is found */
        while(true){

            /* Poll for events */
            while( SDL_PollEvent( &event ) ){
            	manager.handleEvent(&event);
            }
        }

	return 0;
}