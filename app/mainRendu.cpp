#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/Program.hpp>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include "moteurRendu/VBO.hpp"
#include "moteurRendu/VAO.hpp"

using namespace glimac;

int main(int argc, char** argv) {
     // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    std::vector<ShapeVertex> v ;

    ShapeVertex vertex;
    
    vertex.texCoords.x = 0;
    vertex.texCoords.y = 0;

    vertex.normal.x = 0;
    vertex.normal.y = 0;
    vertex.normal.z = 0;

    vertex.position.x = -0.5f;
    vertex.position.y = -0.5f;
    v.push_back(vertex);

    vertex.texCoords.x = 0;
    vertex.texCoords.y = 0;

    vertex.normal.x = 0;
    vertex.normal.y = 0;
    vertex.normal.z = 0;

    vertex.position.x = 0.5f;
    vertex.position.y = -0.5f;
    v.push_back(vertex);

    vertex.texCoords.x = 0;
    vertex.texCoords.y = 0;

    vertex.normal.x = 0;
    vertex.normal.y = 0;
    vertex.normal.z = 0;

    vertex.position.x = 0.0f;
    vertex.position.y = 0.5f;
    v.push_back(vertex);
      

    VBO triangle(v);
    triangle.sendData();

    
    VAO traingle;
    triangle.bind();
    traingle.bind();
    traingle.specifyAttributes();
    traingle.debind();
    triangle.debind();


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

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT);

        traingle.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3); //Dessin des triangles
        traingle.debind();
        // Update the display
        windowManager.swapBuffers();
    }

    triangle.deleteBuf();
    traingle.deleteBuf();

    return EXIT_SUCCESS;
}
