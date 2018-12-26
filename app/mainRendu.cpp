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
#include "moteurRendu/Light.hpp"
#include "moteurRendu/Texture.hpp"
#include "moteurRendu/ListTextures.hpp"
#include "glimac/Sphere.hpp"
#include "glimac/Geometry.hpp"

using namespace glimac;

std::vector<ShapeVertex> transformIntoVector( const ShapeVertex* data, size_t length)
{
    std::vector<ShapeVertex> v;
    for (size_t i =0; i < length; i ++)
    {
        // ShapeVertex s ;

        // s.m_Position.x = data[i];
        // s.m_Position.y = data[i+1];
        // s.m_Position.y = data[i+2];

        // s.m_Normal.x = data[i+3];
        // s.m_Normal.y = data[i+4];
        // s.m_Normal.z = data[i+5];
        v.push_back(data[i]);
    }
   


    return v;
}

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
                              applicationPath.dirPath() + "shaders/multiPointLight.fs.glsl");
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
    GLint uLightPos_vs = glGetUniformLocation(program.getGLId(), "uLightPos_vs");
    GLint uLightIntensity = glGetUniformLocation(program.getGLId(), "uLightIntensity");
*/    

    glEnable(GL_DEPTH_TEST);

    ListTextures textureManager(50);
    // std::unique_ptr<Image> earth = loadImage(applicationPath.dirPath() + "../../GLImac-Template/assets/textures/EarthMap.jpg");
    Image* earth = ImageManager::loadImage(applicationPath.dirPath() + "/assets/textures/EarthMap.jpg");
    if(earth == NULL) {
        std::cerr << "error load image" << std::endl;
    }


    textureManager.addTexture( earth);

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 1.f, 0.1f, 100.f);
    glm::mat4 globalMVMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, -3.f));
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(globalMVMatrix));

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    Texture t(0,textureManager);


    // std::vector<ShapeVertex> v ;

    // ShapeVertex vertex;
    
    // vertex.m_TexCoords.x = 0;
    // vertex.m_TexCoords.y = 0;

    // vertex.m_Normal.x = 0;
    // vertex.m_Normal.y = 0;
    // vertex.m_Normal.z = 0;

    // vertex.m_Position.x = -0.5f;
    // vertex.m_Position.y = -0.5f;
    // v.push_back(vertex);

    // vertex.m_TexCoords.x = 0;
    // vertex.m_TexCoords.y = 1;

    // vertex.m_Normal.x = 0;
    // vertex.m_Normal.y = 0;
    // vertex.m_Normal.z = 0;

    // vertex.m_Position.x = 0.5f;
    // vertex.m_Position.y = -0.5f;
    // v.push_back(vertex);

    // vertex.m_TexCoords.x = 1;
    // vertex.m_TexCoords.y = 1;

    // vertex.m_Normal.x = 0;
    // vertex.m_Normal.y = 0;
    // vertex.m_Normal.z = 0;

    // vertex.m_Position.x = 0.5f;
    // vertex.m_Position.y = 0.5f;
    // v.push_back(vertex);
    

    // vertex.m_TexCoords.x = 1;
    // vertex.m_TexCoords.y = 0;

    // vertex.m_Normal.x = 0;
    // vertex.m_Normal.y = 0;
    // vertex.m_Normal.z = 0;

    // vertex.m_Position.x = -0.5f;
    // vertex.m_Position.y = 0.5f;
    // v.push_back(vertex);

    /*Sphere sphere(1, 50, 25);
    const ShapeVertex* s = sphere.getDataPointer();
    for (int i = 0; i < sphere.getVertexCount() ; i++)
        v.push_back(s[i]);*/

    // uint32_t indices[]  = {
    //     0, 1, 2, 0, 2, 3
    // };

    //Création d'un objet Géométry et chargement du modèle, fichier obj, mtl et activation de la texture
    Geometry g;
    bool loaded = g.loadOBJ(applicationPath.dirPath() + "/assets/models/corner.obj",
        applicationPath.dirPath() + "/assets/models/corner.mtl",true);

    if(!loaded) 
    {
        std::cout << "ERROR LOADING" << std::endl;
        return EXIT_FAILURE;
    }


    
    //Chargement des sommets dans l'objet vbo, ibo et vao
    VBO triangle(0,g);
    //Envoi à la carte graphique
    triangle.sendData();

    //Génération des textures non fonctionnel sur les obj (seulement sur les formes de bases mais il faut changer le shader)
    //textureManager.generateTexture();

    //t.paramTexture();

    std::vector<Light> lights;

    lights.push_back(Light(true, glm::vec3(2.0, 1.0, -10.0), glm::vec3(1.0, 0.0, 0.0), glm::vec3(1.0), 64, glm::vec3(1.0)));
    lights.push_back(Light(true, glm::vec3(0.0, 1.0, -10.0), glm::vec3(0.0, 1.0, 0.0), glm::vec3(1.0), 64, glm::vec3(1.0)));
    lights.push_back(Light(true, glm::vec3(-2.0, 1.0, -10.0), glm::vec3(0.0, 0.0, 1.0), glm::vec3(1.0), 64, glm::vec3(1.0)));
    lights.push_back(Light(false, glm::vec3(10.0, 0.0, 20.0), glm::vec3(1.0, 0.7, 0.4), glm::vec3(1.0), 64, glm::vec3(1.0)));

    glm::vec3 ambientLight = glm::vec3(0.2);


    // Application loop:
    bool done = false;

    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) 
        {
            if(e.type == SDL_QUIT) 
            {
                done = true; // Leave the loop after this iteration
            }
        }
        if(e.key.type == SDL_KEYDOWN) 
        {
            switch(e.key.keysym.sym)
            {
                case SDLK_q:
                    track.rotateLeft(0.05f);
                    break;
                case SDLK_d:
                    track.rotateLeft(-0.05f);
                    break;
                case SDLK_z:
                    track.rotateUp(0.05f);
                    break;
                case SDLK_s:
                    track.rotateUp(-0.05f);
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

        triangle.vao().bind();
        //glUniform1i(uTexture,0); //texture
        //t.bind();

        glUniform3f(glGetUniformLocation(program.getGLId(), "uAmbientLight"), ambientLight.x, ambientLight.y, ambientLight.z); 

        std::string refLight = "uLights";

        

        glUniform1i(glGetUniformLocation(program.getGLId(), "uNbLights"), lights.size()); 

        //glm::mat4 earthMVMatrix = glm::rotate(trackMat*globalMVMatrix, windowManager.getTime(), glm::vec3(0,1,0));
        glm::mat4 earthMVMatrix = glm::rotate(trackMat*globalMVMatrix, 0*windowManager.getTime(), glm::vec3(0,1,0));
        glUniformMatrix4fv(uMVMatrix , 1, GL_FALSE, glm::value_ptr(earthMVMatrix));
        NormalMatrix = glm::transpose(glm::inverse(earthMVMatrix));
        glUniformMatrix4fv(uNormalMatrix , 1, GL_FALSE, glm::value_ptr(NormalMatrix));
        glUniformMatrix4fv(uMVPMatrix , 1, GL_FALSE, glm::value_ptr(ProjMatrix * earthMVMatrix));

        lights[0].sendLightShader(program, refLight, track);
        lights[1].sendLightShader(program, refLight, track);
        lights[2].sendLightShader(program, refLight, track);
        lights[3].sendLightShader(program, refLight, track);

        triangle.draw();


        //t.debind();
        triangle.vao().debind();
        // Update the display
        windowManager.swapBuffers();
    }

    triangle.deleteBuf();

    return EXIT_SUCCESS;
}
