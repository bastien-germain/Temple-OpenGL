#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include "moteurRendu/TrackballCamera.hpp"
#include "moteurRendu/VBO.hpp"
#include "moteurRendu/VAO.hpp"
#include "glimac/Sphere.hpp"
#include "glimac/Geometry.hpp"

/* A FAIRE
* intégrer la fabrique, les models pour gérer la mise en place du parcours
* Intégrer la classe Player (voir comment gérer les déplacements)
* Voir comment on gère les virages

*/

using namespace glimac;

int main(int argc, char** argv) {
     // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "GLImac");
    TrackballCamera track;
    

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }


    FilePath applicationPath(argv[0]);

    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                              applicationPath.dirPath() + "shaders/multiLights.fs.glsl");
    program.use();

    GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    GLint uTexture = glGetUniformLocation(program.getGLId(), "uTexture");

    /*
    GLint uKd = glGetUniformLocation(program.getGLId(), "uKd");
    GLint uKs = glGetUniformLocation(program.getGLId(), "uKs");
    GLint uShininess = glGetUniformLocation(program.getGLId(), "uShininess");
    GLint uLightDir_vs = glGetUniformLocation(program.getGLId(), "uLightDir_vs");
    GLint uLightIntensity = glGetUniformLocation(program.getGLId(), "uLightIntensity");   
    */


    glEnable(GL_DEPTH_TEST);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
    glm::mat4 globalMVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -3.f));
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(globalMVMatrix));

    std::vector<Light> lights;

    lights.push_back(Light(true, glm::vec3(2.0, 1.0, -10.0), glm::vec3(1.0, 0.0, 0.0), glm::vec3(1.0), 64, glm::vec3(1.0)));
    lights.push_back(Light(true, glm::vec3(0.0, 1.0, -10.0), glm::vec3(0.0, 1.0, 0.0), glm::vec3(1.0), 64, glm::vec3(1.0)));
    lights.push_back(Light(true, glm::vec3(-2.0, 1.0, -10.0), glm::vec3(0.0, 0.0, 1.0), glm::vec3(1.0), 64, glm::vec3(1.0)));
    lights.push_back(Light(false, glm::vec3(1.0, 0.0, 0.0), glm::vec3(0.0, 0.4, 0.9), glm::vec3(1.0), 8, glm::vec3(1.0)));
    lights.push_back(Light(false, glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.8, 0.1, 0.4), glm::vec3(1.0), 8, glm::vec3(1.0)));

    glm::vec3 ambientLight = glm::vec3(0.2);

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    //Corridor
    Geometry gCorridor;
    gCorridor.loadOBJ(applicationPath.dirPath() + "/assets/models/corridor.obj",
        applicationPath.dirPath() + "/assets/models/corridor.mtl",true);

    //CorridorHole
    Geometry gCorridorHole;
    gCorridorHole.loadOBJ(applicationPath.dirPath() + "/assets/models/corridor_hole.obj",
        applicationPath.dirPath() + "/assets/models/corridor_hole.mtl",true);

    //Corner
    Geometry gCorner;
    gCorner.loadOBJ(applicationPath.dirPath() + "/assets/models/corner.obj",
        applicationPath.dirPath() + "/assets/models/corner.mtl",true);

    //Player
    Geometry gPlayer;
    gPlayer.loadOBJ(applicationPath.dirPath() + "/assets/models/cube2.obj",
        applicationPath.dirPath() + "/assets/models/cube2.mtl",true);


    
    //Chargement des sommets dans l'objet vbo, ibo et vao
    VBO corridor(gCorridor);
    //Envoi à la carte graphique
    corridor.sendData();

    VBO corridorHole(gCorridorHole);
    corridorHole.sendData();

    VBO corner(gCorner);
    corner.sendData();

    VBO player(gPlayer);
    player.sendData();

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
                    track.rotateLeft(0.01f);
                    break;
                case SDLK_d:
                    track.rotateLeft(-0.01f);
                    break;
                case SDLK_z:
                    track.rotateUp(0.01f);
                    break;
                case SDLK_s:
                    track.rotateUp(-0.01f);
                    break;
                case SDLK_a:
                    track.moveFront(0.005f);
                    break;
                case SDLK_e:
                    track.moveFront(-0.005f);
                    break;

                default: 
                    break;

            }
        }
        glm::mat4 trackMat = track.getViewMatrix(); 
        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // LIGHTS

        glUniform3f(glGetUniformLocation(program.getGLId(), "uAmbientLight"), ambientLight.x, ambientLight.y, ambientLight.z); 
        glUniform1i(glGetUniformLocation(program.getGLId(), "uNbLights"), lights.size()); 

        std::string refLight = "uLights";

        lights[0].sendLightShader(program, refLight);
        lights[1].sendLightShader(program, refLight);
        lights[2].sendLightShader(program, refLight);
        lights[3].sendLightShader(program, refLight);
        lights[4].sendLightShader(program, refLight);

        // COULOIR

        glm::mat4 corridorMVMatrix = glm::rotate(trackMat*globalMVMatrix, glm::radians(20.f), glm::vec3(1,0,0));
        //rotate le corridor
        corridorMVMatrix = glm::rotate(corridorMVMatrix, glm::radians(90.f), glm::vec3(0,1,0));
        
        // descend le corridor
        corridorMVMatrix = glm::translate(corridorMVMatrix, glm::vec3(0, -3, 0));

        glm::mat4 tmpMatrix;
        float positionOffSet = 20.f;
        float speed = windowManager.getTime()*10;
        
        corridor.vao().bind();

        for (int i = 0; i < 10; ++i)
        {
            if (((i*positionOffSet - speed) > -5*positionOffSet) && ((i*positionOffSet - speed) < 5*positionOffSet))
            {   
                tmpMatrix = glm::translate(corridorMVMatrix, glm::vec3(i*positionOffSet, 0, 0));

                // fais avancer le corridor (defilement)
                tmpMatrix = glm::translate(tmpMatrix, glm::vec3(std::max(-(i+5)*positionOffSet, -speed), 0, 0));
                
                glUniformMatrix4fv(uMVMatrix , 1, GL_FALSE, glm::value_ptr(tmpMatrix));
                glUniformMatrix4fv(uNormalMatrix , 1, GL_FALSE, glm::value_ptr(NormalMatrix));
                glUniformMatrix4fv(uMVPMatrix , 1, GL_FALSE, glm::value_ptr(ProjMatrix * tmpMatrix));

                if ((i+1)%3 == 0) 
                {
                    corridor.vao().debind();
                    corridorHole.vao().bind();
                    corridorHole.draw();
                    corridorHole.vao().debind();
                    corridor.vao().bind();

                }

                else 
                {
                    if ((i+1)%7 == 0)
                    {   
                        if (speed == i*positionOffSet)
                            globalMVMatrix = glm::rotate(globalMVMatrix, glm::radians(-90.f), glm::vec3(0,1,0));
                        corridor.vao().debind();
                        corner.vao().bind();
                        corner.draw();
                        corner.vao().debind();
                        corridor.vao().bind();

                    }
                    else 
                    {
                        corridor.draw();                  
                    }
                }

            }
        
        }

        corridor.vao().debind();

        //PLAYER

        player.vao().bind();

        // rotate le player
        glm::mat4 playerMVMatrix = glm::rotate(trackMat*globalMVMatrix, glm::radians(20.f), glm::vec3(1,0,0));
        // descend le player
        playerMVMatrix = glm::translate(playerMVMatrix, glm::vec3(0, -1, 0));

        glUniformMatrix4fv(uMVMatrix , 1, GL_FALSE, glm::value_ptr(playerMVMatrix));
        glUniformMatrix4fv(uNormalMatrix , 1, GL_FALSE, glm::value_ptr(NormalMatrix));
        glUniformMatrix4fv(uMVPMatrix , 1, GL_FALSE, glm::value_ptr(ProjMatrix * playerMVMatrix));

        player.draw();

        player.vao().debind();

        // Update the display
        windowManager.swapBuffers();
    }

    corridor.deleteBuf();
    player.deleteBuf();

    return EXIT_SUCCESS;
}
