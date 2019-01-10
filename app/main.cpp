#include <GL/glew.h>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>

#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>

#include "moteurJeu/Game.hpp"
#include "moteurJeu/Menu.hpp"

#define WIN_WIDTH 800
#define WIN_HEIGHT 800

using namespace glimac;

int main(int argc, char** argv) {
     // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "Will-chair Run");
    

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);

    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/texture.fs.glsl");
    
    glEnable(GL_DEPTH_TEST);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    program.use(); 

    Game game(program);

    // MENU
    bool isMenuDisplayed = false;

    Menu menu;

    menu.addButton("Game Over", WIN_WIDTH/2 - 120, WIN_HEIGHT/2 + 50, 80);

    // Test affichage score
    int score = 0;
    std::string scoreText = "Score : " + std::to_string(score);

    Button scoreButton(scoreText, 50, 700, 80);

    // Application loop:
    bool done = false;
    while(!done) 
    {   
        // Event loop
        SDL_Event e;
        while(windowManager.pollEvent(e)) 
        {
            if(e.type == SDL_QUIT) 
            {
                done = true; // Leave the loop after this iteration
            }

            if (isMenuDisplayed)
            {
                if(e.type == SDL_MOUSEBUTTONDOWN)
                {
                    if (e.button.button == SDL_BUTTON_LEFT) 
                    {
                        // Inversion du y (0 en haut) !
                        if(menu.checkButtonClick(e.button.x, WIN_HEIGHT - e.button.y))
                        {
                            done = true;
                        }
                    }
                }

                if(e.type == SDL_MOUSEMOTION)
                {
                    // Inversion du y (0 en haut) !
                    menu.checkButtonHovering(e.button.x, WIN_HEIGHT - e.button.y);

                } 
            }                        
          
        }

        /*** Rendering code ***/

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (isMenuDisplayed)
        {   
            glUseProgram(0);

            menu.draw();

            scoreButton.draw();
        }
        else 
        {

            if(game.processGame(&e, program))
                isMenuDisplayed = true;

            score += 1;
            scoreText = "Score : " + std::to_string(score);
            scoreButton.updateText(scoreText);
        }        

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
