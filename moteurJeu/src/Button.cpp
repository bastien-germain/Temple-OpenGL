#include "moteurJeu/Button.hpp"
#include <iostream>

Button::Button(const std::string &text, const unsigned int x, const unsigned int y, const unsigned int fontSize) 
: _posX(x), _posY(y), _text(text), _fontSize(fontSize), _textWidth(0), _textHeight(0), _textColor({0, 0, 0})
{

}

Button::~Button()
{
	
}

void Button::draw()
{
	TTF_Init();
 
    // Font loading
    TTF_Font* font = TTF_OpenFont("app/fonts/Cartonsix.ttf", _fontSize);
 
    if(NULL != font)
    {	
        SDL_Surface* text = TTF_RenderText_Blended(font,
        _text.c_str(), _textColor);
 
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
            glTexCoord2d(0, 1); glVertex2f( _posX, WIN_HEIGHT - _posY + _textHeight);
            glTexCoord2d(0, 0); glVertex2f( _posX, WIN_HEIGHT - _posY);
            glTexCoord2d(1, 0); glVertex2f( _posX + _textWidth, WIN_HEIGHT - _posY);
            glTexCoord2d(1, 1); glVertex2f( _posX + _textWidth, WIN_HEIGHT - _posY + _textHeight);
        glEnd();
        glDisable(GL_TEXTURE_2D);
 
        glDeleteTextures(1, &textTexture);
    }
 
    TTF_Quit();
}


void Button::checkHovering(const int x, const int y)
{ 
    if(x > _posX && x < _posX + _textWidth && y < _posY && y > _posY - _textHeight)
    {
        _textColor = {255, 0, 0};
    }
    else 
    {
        _textColor = {0, 0, 0};
    }
 
}

bool Button::checkClick(const int x, const int y) const
{ 
    if(x > _posX && x < _posX + _textWidth && y < _posY && y > _posY - _textHeight)
    {
        return true;
    }
   
    return false; 
}

void Button::updateText(const std::string &newText)
{
	_text = newText;
}