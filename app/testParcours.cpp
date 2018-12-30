#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include "moteurRendu/TrackballCamera.hpp"
#include "moteurJeu/EventManager.hpp"
#include "moteurJeu/Player.hpp"
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

int main (int argc, char** argv) 
{
     // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "GLImac");

    TrackballCamera track;
    EventManager eManager;
    Player player(0.002f, 0.0019f);
    SDL_Event e;
    
    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if (GLEW_OK != glewInitError) 
    {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }


    FilePath applicationPath(argv[0]);

    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/multiLights.fs.glsl");
    program.use();

    GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    GLint uTexture = glGetUniformLocation(program.getGLId(), "uTexture");

    glEnable(GL_DEPTH_TEST);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
    glm::mat4 globalMVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -3.f));
    //globalMVMatrix = glm::rotate(globalMVMatrix, glm::radians(180.f), glm::vec3(0,1,0));
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(globalMVMatrix));

        // LIGHTS

    std::vector<Light> lights;
    std::string refLight = "uLights";

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
    gPlayer.loadOBJ(applicationPath.dirPath() + "/assets/models/fauteuil.obj",
        applicationPath.dirPath() + "/assets/models/pcfusee.mtl",true);

    
    //Chargement des sommets dans l'objet vbo, ibo et vao

    VBO corridorVBO(0,gCorridor);
    corridorVBO.sendData();

    VBO corridorHoleVBO(0, gCorridorHole);
    corridorHoleVBO.sendData();

    VBO cornerVBO(0, gCorner);
    cornerVBO.sendData();

    VBO playerVBO(0,gPlayer);
    playerVBO.sendData();

    // Application loop:
    bool done = false;

    float positionOffSet = -20.f;
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
        eManager.handleEvent(&e, player, track);

        glm::mat4 trackMat = track.getViewMatrix();
        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float speed = windowManager.getTime() * 10;
        //std::cout << "time" << speed << std::endl;
        std::cout << "posX : " << player.posX() << std::endl;
        std::cout << "posY : " << player.posY() << std::endl;
        
        /*if (speed > 95 && turned == false)
        {
            globalMVMatrix = glm::rotate(globalMVMatrix, glm::radians(90.f), glm::vec3(0,1,0));
            turned = true;
        }*/

        tmpMatrix = glm::translate(trackMat * globalMVMatrix, glm::vec3(0,-2,0));
        glm::mat4 matrixPlayer = tmpMatrix;

        if (balancement > 25.f || balancement < -25.f)
            balancementSpeed *= -1;

        balancement += balancementSpeed;

        matrixPlayer = glm::rotate(matrixPlayer, glm::radians(balancement), glm::vec3(1, 0, 0));
        
        matrixPlayer = glm::translate(matrixPlayer, glm::vec3(player.posX(), player.posY(), 0));
        glUniformMatrix4fv(uMVMatrix , 1, GL_FALSE, glm::value_ptr(matrixPlayer));
        glUniformMatrix4fv(uNormalMatrix , 1, GL_FALSE, glm::value_ptr(NormalMatrix));
        glUniformMatrix4fv(uMVPMatrix , 1, GL_FALSE, glm::value_ptr(ProjMatrix * matrixPlayer));
        playerVBO.draw();
        
        tmpMatrix = glm::translate(trackMat * globalMVMatrix, glm::vec3(0,-4,0));
        tmpMatrix = glm::translate(tmpMatrix, glm::vec3(0,0,speed));

        for (int i = 0; i < 5; ++i)
        {

            glUniformMatrix4fv(uMVMatrix , 1, GL_FALSE, glm::value_ptr(tmpMatrix));
            glUniformMatrix4fv(uNormalMatrix , 1, GL_FALSE, glm::value_ptr(NormalMatrix));
            glUniformMatrix4fv(uMVPMatrix , 1, GL_FALSE, glm::value_ptr(ProjMatrix * tmpMatrix));
            
            corridorVBO.draw();

            tmpMatrix =  glm::translate(tmpMatrix  , glm::vec3(0, 0, positionOffSet));
        }
        
        glUniformMatrix4fv(uMVMatrix , 1, GL_FALSE, glm::value_ptr(tmpMatrix));
        glUniformMatrix4fv(uNormalMatrix , 1, GL_FALSE, glm::value_ptr(NormalMatrix));
        glUniformMatrix4fv(uMVPMatrix , 1, GL_FALSE, glm::value_ptr(ProjMatrix * tmpMatrix));

        cornerVBO.draw();

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


////////////////////

        
        tmpMatrix = glm::translate(globalMVMatrix, glm::vec3(0,-4,0));
        tmpMatrix = glm::rotate(tmpMatrix, glm::radians(90.f) , glm::vec3(0,1,0));
        tmpMatrix = glm::translate(tmpMatrix, glm::vec3(0,0,-speed));

        windowManager.swapBuffers();
    }

    corridorVBO.deleteBuf();
    playerVBO.deleteBuf();
    cornerVBO.deleteBuf();

    return EXIT_SUCCESS;
}
