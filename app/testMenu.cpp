#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>

#include "moteurJeu/Menu.hpp"

#define WIN_WIDTH 800
#define WIN_HEIGHT 800

using namespace glimac;

int main(int argc, char** argv) {
     // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "test menu");
    

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }


    glEnable(GL_DEPTH_TEST);

    Menu menu;


    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        if(e.key.type == SDL_KEYDOWN) {

            switch(e.key.keysym.sym)
            {
                case SDLK_q:
                    done = true;
                    break;

                default: 
                    break;

            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw here
        menu.draw();

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
