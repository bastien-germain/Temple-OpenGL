#include <GL/glew.h>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>

#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>

#include "moteurJeu/GameManager.hpp"
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

    FilePath applicationPath(argv[0]);

    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/textureTest.fs.glsl");
    program.use();

    glEnable(GL_DEPTH_TEST);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    // GAMEMANAGER

    GameManager gameManager(program);
    std::cout << "gameManager ok" << std::endl;
    gameManager.loadSections();

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

    // MENU
    bool isMenuDisplayed = true;

    Menu menu;

    menu.addButton("Play", WIN_WIDTH/2 - 50, WIN_HEIGHT/2 + 100, 80);
    menu.addButton("Quit", WIN_WIDTH/2 - 50, WIN_HEIGHT/2 - 100, 80);

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
                            std::cout << "clicked" << std::endl;
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
            std::cout << "Menu affiché" << std::endl;
            menu.draw();

            // Score augmente
            score += 1;
            scoreText = "Score : " + std::to_string(score);
            scoreButton.updateText(scoreText);

            scoreButton.draw();
        }
        else 
        {
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
        }        

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
