#include <GL/glew.h>

#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>

#include "moteurJeu/GameManager.hpp"

using namespace glimac;

int main (int argc, char** argv) 
{
     // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "EHPAD RUN : Escape Mamie Jeanne");
    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();

    SDL_Event e;
    
    if (GLEW_OK != glewInitError) 
    {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);

    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/textureTest.fs.glsl");
    program.use();
    


    GameManager gameManager(program);

    glEnable(GL_DEPTH_TEST);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    // Application loop:
    bool done = false;
    /*
    gameManager.worldGenerator().generateSectionsFromFile(
        &gameManager, 
        gameManager.factory(), 
        gameManager.parser().parse("../Temple-OpenGL/app/assets/sectionsData/sectionsData.txt"));
    */

    while (!done) 
    {
        // Event loop:
        
        while (windowManager.pollEvent(e)) 
        {
            if (e.type == SDL_QUIT) 
                done = true; // Leave the lsoop after this iteration

        }
        gameManager.handleEvent(&e);

        glm::mat4 trackMat = gameManager.trackball().getViewMatrix();

        /*gameManager.drawer().draw(
            gameManager.worldGenerator().sectionVec(), 
            gameManager.trackball().getViewMatrix(), 
            gameManager.player(),
            gameManager.enemy(),
            gameManager.skybox(),
            program);

        windowManager.swapBuffers();*/
    }

    gameManager.deleteModelBuffers();

    return EXIT_SUCCESS;
}
