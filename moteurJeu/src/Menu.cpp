#include "moteurJeu/Menu.hpp"
#include <iostream>

Menu::Menu() : _visible(true)
{

}

Menu::~Menu()
{
	
}

void Menu::hide()
{
	_visible = false;
	std::cout << "menu hidden" << std::endl;
}

void Menu::show()
{
	_visible = true;
	std::cout << "menu showed" << std::endl;
}

void Menu::draw()
{	
	if (_visible)
	{

		// 2D
	    glLoadIdentity();
	    glMatrixMode(GL_PROJECTION);
	    glOrtho(0.0f, WIN_WIDTH, WIN_HEIGHT, 0.0f, 0.0f, 1.0f);
	 
	  
	    glDisable(GL_DEPTH_TEST);
	 
	    glClear(GL_COLOR_BUFFER_BIT);

	    glClearColor(0.5, 0.5, 0.8, 1);

		this->drawButtons();

	    glFlush();
	    SDL_GL_SwapBuffers();


	}
	
}


void Menu::drawButtons()
{
	TTF_Init();
 
    // Chargement de la police
    TTF_Font* police = TTF_OpenFont("app/fonts/Cartonsix.ttf", 80);
 
    if(NULL != police)
    {	
        // Creation de l'image du texte avec la police associee
        SDL_Color couleurTexte = {180, 180, 180};
        SDL_Surface* texte = TTF_RenderText_Blended(police,
        "HALLELUJAH", couleurTexte);
 
        // Liberation de la police
        TTF_CloseFont(police);
 
        // Activation de la transparence
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 
        // Generation de la texture pour le texte
        GLuint textureTexte;
        glGenTextures( 1, &textureTexte );
 
        // Selection de la texture generee
        glBindTexture( GL_TEXTURE_2D, textureTexte );
 
        // Parametrage
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
 
        // Detection du codage des pixels
        GLenum codagePixel;
        if (texte->format->Rmask == 0x000000ff)
        {
            codagePixel = GL_RGBA;
        }
        else
        {
            #ifndef GL_BGRA
                #define GL_BGRA 0x80E1
            #endif
            codagePixel = GL_BGRA;
        }
 
        // Chargement de la texture du texte precedament creee
        glTexImage2D( GL_TEXTURE_2D, 0, 4, texte->w, texte->h, 0,
                      codagePixel, GL_UNSIGNED_BYTE, texte->pixels );
 
        // Recuperation des dimentions du texte
        uint32_t largeurTexte = texte->w;
        uint32_t hauteurTexte = texte->h;
 
        // Liberation de l'image du texte
        SDL_FreeSurface( texte );
 
        // Selection de la texture du texte
        glBindTexture( GL_TEXTURE_2D, textureTexte );
 
        // Application du texte
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0); // Pas de teinte
            glTexCoord2d(0, 0); glVertex2f( (WIN_WIDTH/2) - (largeurTexte/2),
                                WIN_HEIGHT - (WIN_HEIGHT/2) + (hauteurTexte/2));
            glTexCoord2d(0, 1); glVertex2f( (WIN_WIDTH/2) - (largeurTexte/2),
                                WIN_HEIGHT - (WIN_HEIGHT/2) - (hauteurTexte/2));
            glTexCoord2d(1, 1); glVertex2f( (WIN_WIDTH/2) + (largeurTexte/2),
                                WIN_HEIGHT - (WIN_HEIGHT/2) - (hauteurTexte/2));
            glTexCoord2d(1, 0); glVertex2f( (WIN_WIDTH/2) + (largeurTexte/2),
                                WIN_HEIGHT - (WIN_HEIGHT/2) + (hauteurTexte/2));
        glEnd();
        glDisable(GL_TEXTURE_2D);
 
        glDeleteTextures(1, &textureTexte);
    }
 
    TTF_Quit();
}
