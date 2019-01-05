#include "moteurJeu/Button.hpp"
#include <iostream>


// Default font size 80
Button::Button(std::string text, unsigned int x, unsigned int y) 
: _posX(x), _posY(y), _text(text), _fontSize(80), _textWidth(0), _textHeight(0), _isHovered(false)
{

}


Button::Button(std::string text, unsigned int x, unsigned int y, unsigned int fontSize) 
: _posX(x), _posY(y), _text(text), _fontSize(fontSize), _textWidth(0), _textHeight(0), _isHovered(false)
{

}

Button::~Button()
{
	
}

void Button::draw()
{
	SDL_Color textColor = {0, 0, 0};
	if (_isHovered)
		textColor = {255, 0, 0};

	TTF_Init();
 
    // Font loading
    TTF_Font* font = TTF_OpenFont("app/fonts/Cartonsix.ttf", _fontSize);
 
    if(NULL != font)
    {	
        SDL_Surface* text = TTF_RenderText_Blended(font,
        _text.c_str(), textColor);
 
        // Free font
        TTF_CloseFont(font);

        // Text dimensions
        _textWidth = text->w;
        _textHeight = text->h;
 
        // Transparency
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 
        // Texture handling
        GLuint textTexture;
        glGenTextures( 1, &textTexture );
        glBindTexture( GL_TEXTURE_2D, textTexture ); 
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, 4, _textWidth, _textHeight, 0,
                      GL_RGBA, GL_UNSIGNED_BYTE, text->pixels );
 
        // Free text image
        SDL_FreeSurface(text);
 
        glBindTexture(GL_TEXTURE_2D, textTexture);
 
        // Draw the quad with texture containing text
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
            glTexCoord2d(0, 1); glVertex2f( _posX - (_textWidth/2),
                                WIN_HEIGHT - _posY + (_textHeight/2));
            glTexCoord2d(0, 0); glVertex2f( _posX - (_textWidth/2),
                                WIN_HEIGHT - _posY - (_textHeight/2));
            glTexCoord2d(1, 0); glVertex2f( _posX + (_textWidth/2),
                                WIN_HEIGHT - _posY - (_textHeight/2));
            glTexCoord2d(1, 1); glVertex2f( _posX + (_textWidth/2),
                                WIN_HEIGHT - _posY + (_textHeight/2));
        glEnd();
        glDisable(GL_TEXTURE_2D);
 
        glDeleteTextures(1, &textTexture);
    }
 
    TTF_Quit();
}


void Button::state(int x, int y)
{

    // if( 0 != (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) )
    // {
    //     std::cout << "clicked" << std::endl;
    // }

    // Si la souris est sur le bouton (pour l'instant au clic)
    if(x > _posX - (_textWidth/2) && x < _posX + (_textWidth/2)
       && y > _posY - (_textHeight/2) && y < _posY + (_textHeight/2))
    {
        _isHovered = true;
    }
    else {
    	_isHovered = false;
    }
 
}