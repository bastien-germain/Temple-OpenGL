#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <glimac/TrackballCamera.hpp>
#include "moteurRendu/VBO.hpp"
#include "moteurRendu/VAO.hpp"
#include "moteurRendu/Texture.hpp"
#include "moteurRendu/ListTextures.hpp"
#include "glimac/Sphere.hpp"

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
                              applicationPath.dirPath() + "shaders/tex3D.fs.glsl");
    program.use();

    GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    GLint uTexture = glGetUniformLocation(program.getGLId(), "uTexture");
    glEnable(GL_DEPTH_TEST);
    ListTextures c(50);
    // std::unique_ptr<Image> earth = loadImage(applicationPath.dirPath() + "../../GLImac-Template/assets/textures/EarthMap.jpg");
    Image* earth = ImageManager::loadImage(applicationPath.dirPath() + "/assets/EarthMap.jpg");
    if(earth == NULL) {
        std::cerr << "error load image" << std::endl;
    }


    c.addTexture( earth);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
    glm::mat4 globalMVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -3.f));
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(globalMVMatrix));

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    Texture t(0,c);


    std::vector<ShapeVertex> v ;

    ShapeVertex vertex;
    
    // vertex.texCoords.x = 1;
    // vertex.texCoords.y = 0;

    // vertex.normal.x = 0;
    // vertex.normal.y = 0;
    // vertex.normal.z = 0;

    // vertex.position.x = -0.5f;
    // vertex.position.y = -0.5f;
    // v.push_back(vertex);

    // vertex.texCoords.x = 0;
    // vertex.texCoords.y = 0;

    // vertex.normal.x = 0;
    // vertex.normal.y = 0;
    // vertex.normal.z = 0;

    // vertex.position.x = 0.5f;
    // vertex.position.y = -0.5f;
    // v.push_back(vertex);

    // vertex.texCoords.x = 0;
    // vertex.texCoords.y = 1;

    // vertex.normal.x = 0;
    // vertex.normal.y = 0;
    // vertex.normal.z = 0;

    // vertex.position.x = 0.0f;
    // vertex.position.y = 0.5f;
    // v.push_back(vertex);
      
    Sphere sphere(1, 50, 25);
    const ShapeVertex* s = sphere.getDataPointer();
    for (int i = 0; i < sphere.getVertexCount() ; i++)
        v.push_back(s[i]);
    VBO triangle(v);
    triangle.sendData();
    triangle.specifyVAO();


    c.generateTexture();
    t.bind();
    t.paramTexture();
    t.debind();



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
                    track.rotateLeft(0.5f);
                    break;
                case SDLK_d:
                    track.rotateLeft(-0.5f);
                    break;
                case SDLK_z:
                    track.rotateUp(0.5f);
                    break;
                case SDLK_s:
                    track.rotateUp(-0.5f);
                    break;
                case SDLK_a:
                    track.moveFront(0.5f);
                    break;
                case SDLK_e:
                    track.moveFront(-0.5f);
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



        triangle.vao().bind();
        
        glUniform1i(uTexture,0);
        t.bind();

        glm::mat4 earthMVMatrix = glm::rotate(globalMVMatrix, windowManager.getTime(), glm::vec3(0,1,0));
        glUniformMatrix4fv(uMVMatrix , 1, GL_FALSE, glm::value_ptr(earthMVMatrix));
        glUniformMatrix4fv(uNormalMatrix , 1, GL_FALSE, glm::value_ptr(NormalMatrix));
        glUniformMatrix4fv(uMVPMatrix , 1, GL_FALSE, glm::value_ptr(ProjMatrix * earthMVMatrix));

        triangle.draw();


        t.debind();
        triangle.vao().debind();
        // Update the display
        windowManager.swapBuffers();
    }

    triangle.deleteBuf();

    return EXIT_SUCCESS;
}
