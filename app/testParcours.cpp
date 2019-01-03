#include <GL/glew.h>

#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>

#include "moteurJeu/GameManager.hpp"

/* A FAIRE
* intégrer la fabrique, les models pour gérer la mise en place du parcours
* Voir comment on gère les virages

*/

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

    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/multiLights.fs.glsl");
    program.use();

    GameManager gameManager(program);
    
    glEnable(GL_DEPTH_TEST);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
    glm::mat4 globalMVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -3.f));
    //globalMVMatrix = glm::rotate(globalMVMatrix, glm::radians(180.f), glm::vec3(0,1,0));
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(globalMVMatrix));

        // LIGHTS

    std::vector<Light> lights;
    const std::string refLight = "uLights";

    lights.push_back(Light(true, glm::vec3(0.0, -3.0, -7.0), glm::vec3(1.0, 0.0, 0.0), glm::vec3(1.0), 64, glm::vec3(1.0)));
    lights.push_back(Light(true, glm::vec3(0.0, 0.0, -5.0), glm::vec3(0.0, 1.0, 0.0), glm::vec3(1.0), 64, glm::vec3(1.0)));
    lights.push_back(Light(true, glm::vec3(0.0, 0.0, -5.0), glm::vec3(0.0, 0.0, 1.0), glm::vec3(1.0), 64, glm::vec3(1.0)));
    lights.push_back(Light(false, glm::vec3(1.0, 0.0, 0.0), glm::vec3(0.0, 0.4, 0.9), glm::vec3(1.0), 8, glm::vec3(1.0)));
    lights.push_back(Light(false, glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.8, 0.1, 0.4), glm::vec3(1.0), 8, glm::vec3(1.0)));

    lights[0].sendLightShader(program, refLight);
    lights[1].sendLightShader(program, refLight);
    lights[2].sendLightShader(program, refLight);
    lights[3].sendLightShader(program, refLight);
    lights[4].sendLightShader(program, refLight);

    glm::vec3 ambientLight = glm::vec3(0.2);

    glUniform3f(glGetUniformLocation(program.getGLId(), "uAmbientLight"), ambientLight.x, ambientLight.y, ambientLight.z); 
    glUniform1i(glGetUniformLocation(program.getGLId(), "uNbLights"), lights.size()); 

    float positionOffSet = 18.f;

    // Application loop:
    bool done = false;

    float speedCamera = 100.0f;
    
    float balancement = 0.f;
    float balancementSpeed = 0.005;

    bool turned = false;

    while (!done) 
    {
        // Event loop:
        
        while (windowManager.pollEvent(e)) 
        {
            if (e.type == SDL_QUIT) 
                done = true; // Leave the lsoop after this iteration

        }
        glm::mat4 tmpMatrix = glm::mat4();
        gameManager.handleEvent(&e);

        glm::mat4 trackMat = gameManager.trackball().getViewMatrix();
        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float speed = windowManager.getTime() * 0.0005;
        //std::cout << "time" << speed << std::endl;
        
        /*if (speed > 95 && turned == false)
        {
            globalMVMatrix = glm::rotate(globalMVMatrix, glm::radians(90.f), glm::vec3(0,1,0));
            turned = true;
        }*/

        tmpMatrix = glm::translate(trackMat * globalMVMatrix, glm::vec3(0,-2,0));
        glm::mat4 matrixPlayer = tmpMatrix;
/*
        if (balancement > 25.f || balancement < -25.f)
            balancementSpeed *= -1;

        balancement += balancementSpeed;

        matrixPlayer = glm::rotate(matrixPlayer, glm::radians(balancement), glm::vec3(1, 0, 0));
        
        matrixPlayer = glm::translate(matrixPlayer, glm::vec3(player.posX(), player.posY(), 0));
        glUniformMatrix4fv(uMVMatrix , 1, GL_FALSE, glm::value_ptr(matrixPlayer));
        glUniformMatrix4fv(uNormalMatrix , 1, GL_FALSE, glm::value_ptr(NormalMatrix));
        glUniformMatrix4fv(uMVPMatrix , 1, GL_FALSE, glm::value_ptr(ProjMatrix * matrixPlayer));
        playerVBO.draw();
        
        for (int i = 0; i < sections.size(); ++i)
        {   
            sections[i]->goOn(-speed);
            if (fabs(sections[i]->posZ()) < 6*positionOffSet)
            {
                std::cout << "rotateIndicator : " << drawer.rotateIndicator() << std::endl;
                switch (drawer.rotateIndicator()) 
                {
                    case 0:
                        tmpMatrix =  glm::translate(tmpMatrix  , glm::vec3(0, 0, -sections[i]->posZ()));
                        break;
                    case 1:
                        tmpMatrix =  glm::translate(tmpMatrix  , glm::vec3(sections[5]->posZ(), 0, (i-5)*positionOffSet));
                        break;
                    default:
                        break;
                }

                glUniformMatrix4fv(uMVMatrix , 1, GL_FALSE, glm::value_ptr(tmpMatrix));
                glUniformMatrix4fv(uNormalMatrix , 1, GL_FALSE, glm::value_ptr(NormalMatrix));
                glUniformMatrix4fv(uMVPMatrix , 1, GL_FALSE, glm::value_ptr(ProjMatrix * tmpMatrix));

                switch (drawer.rotateIndicator()) 
                {
                    case 0:
                        tmpMatrix =  glm::translate(tmpMatrix  , glm::vec3(0, 0, sections[i]->posZ()));
                        break;
                    case 1:
                        tmpMatrix =  glm::translate(tmpMatrix  , glm::vec3(-sections[5]->posZ(), 0, -(i-5)*positionOffSet));
                        break;
                    default:
                        break;
                }
                
                sections[i]->model()->vbo().draw();

                if (sections[i]->isCorner())
                {   
                    std::cout << "cornerDirection : " << sections[i]->cornerDirection() << std::endl;
                    tmpMatrix = glm::rotate(tmpMatrix, glm::radians(sections[i]->cornerDirection() * 90.f), glm::vec3(0,1,0));
                    drawer.rotated(sections[i]->cornerDirection());
                    std::cout << "rotateIndicator : " << drawer.rotateIndicator() << std::endl;
                }
            }
        }
        tmpMatrix = glm::rotate(tmpMatrix, glm::radians(drawer.rotateIndicator() * 90.f), glm::vec3(0,-1,0));
        drawer.rotated(-drawer.rotateIndicator());

*/
        /*

//////// AFTER CORNER 

        tmpMatrix = glm::rotate(tmpMatrix, glm::radians(-90.f), glm::vec3(0,1,0));
        tmpMatrix = glm::translate(tmpMatrix, glm::vec3(0, 0, positionOffSet));

        
        glUniformMatrix4fv(uMVMatrix , 1, GL_FALSE, glm::value_ptr(tmpMatrix));
        glUniformMatrix4fv(uNormalMatrix , 1, GL_FALSE, glm::value_ptr(NormalMatrix));
        glUniformMatrix4fv(uMVPMatrix , 1, GL_FALSE, glm::value_ptr(ProjMatrix * tmpMatrix));
        
        corridorVBO.draw();

        tmpMatrix = glm::translate(tmpMatrix, glm::vec3(0, 0, positionOffSet));

        
        glUniformMatrix4fv(uMVMatrix , 1, GL_FALSE, glm::value_ptr(tmpMatrix));
        glUniformMatrix4fv(uNormalMatrix , 1, GL_FALSE, glm::value_ptr(NormalMatrix));
        glUniformMatrix4fv(uMVPMatrix , 1, GL_FALSE, glm::value_ptr(ProjMatrix * tmpMatrix));
        
        corridorVBO.draw();

        tmpMatrix = glm::translate(tmpMatrix, glm::vec3(0, 0, positionOffSet)) ;
*/

        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
