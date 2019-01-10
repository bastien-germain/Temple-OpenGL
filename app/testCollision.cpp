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
    std::cout << "gameManager ok" << std::endl;
    glEnable(GL_DEPTH_TEST);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    // LIGHTS

    std::vector<Light> lights;
    const std::string refLight = "uLights";

    lights.push_back(Light(false, glm::vec3(1.0, .0, 0.0), glm::vec3(1.0), glm::vec3(1.0), 8, glm::vec3(1.0)));
    lights.push_back(Light(false, glm::vec3(0.0, 1.0, 0.0), glm::vec3(1.0), glm::vec3(1.0), 8, glm::vec3(1.0)));

    lights[0].sendLightShader(program, refLight);
    lights[1].sendLightShader(program, refLight);

    glm::vec3 ambientLight = glm::vec3(0.2);

    glUniform3f(glGetUniformLocation(program.getGLId(), "uAmbientLight"), ambientLight.x, ambientLight.y, ambientLight.z); 
    glUniform1i(glGetUniformLocation(program.getGLId(), "uNbLights"), lights.size()); 

    float positionOffSet = 18.f;

    gameManager.loadSections();
    
    // Application loop:
    bool done = false;

    while (!done) 
    {
        // Event loop:
        
        while (windowManager.pollEvent(e)) 
        {
            if (e.type == SDL_QUIT) 
                done = true; // Leave the lsoop after this iteration

            //gameManager.handleEvent(&e);
        }
        gameManager.handleEvent(&e);

        glm::mat4 trackMat = gameManager.trackball().getViewMatrix();

        gameManager.drawer().draw(
            gameManager.sectionVec(), 
            gameManager.trackball().getViewMatrix(), 
            gameManager.player(),
            gameManager.enemy(),
            gameManager.skybox(),
            program);

        if (gameManager.isOver())
        {
            std::cout << "game over" << std::endl;
        }

        windowManager.swapBuffers();
    }

    gameManager.deleteModelBuffers();

    return EXIT_SUCCESS;
}