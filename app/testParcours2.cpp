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
    SDLWindowManager windowManager(800, 800, "GLImac");
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

    gameManager.loadSections();

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
        
        /*if (speed > 95 && turned == false)
        {
            globalMVMatrix = glm::rotate(globalMVMatrix, glm::radians(90.f), glm::vec3(0,1,0));
            turned = true;
        }*/

        gameManager.drawer().draw(
            gameManager.sectionMat(), 
            gameManager.trackball().getViewMatrix(), 
            gameManager.player(), 
            program);

        windowManager.swapBuffers();
    }

    gameManager.deleteModelBuffers();

    return EXIT_SUCCESS;
}
