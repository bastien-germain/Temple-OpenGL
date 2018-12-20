#include <glimac/SDLWindowManager.hpp>
#include <glimac/FilePath.hpp>
#include <GL/glew.h>
#include <cstdlib>
#include <iostream>

#include <ft2build.h>
#include FT_FREETYPE_H

using namespace glimac;


int main(int argc, char** argv) {

    FilePath applicationPath(argv[0]);

    FT_Library ft;

    if(FT_Init_FreeType(&ft)) {
      fprintf(stderr, "Could not init freetype library\n");
      return 1;
    }
    
    FT_Face face;

    if(FT_New_Face(ft,"./app/fonts/helvetica.ttf", 0, &face)) {
      fprintf(stderr, "Could not open font\n");
      return 1;
    }

    FT_Set_Pixel_Sizes(face, 0, 48);

    if(FT_Load_Char(face, 'X', FT_LOAD_RENDER)) {
      fprintf(stderr, "Could not load character 'X'\n");
      return 1;
    }

     // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "GLImac"); 

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    glEnable(GL_DEPTH_TEST);

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update the display
        windowManager.swapBuffers();
    }


    return EXIT_SUCCESS;
}
