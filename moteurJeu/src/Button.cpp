#include "moteurJeu/Button.hpp"


// Default text color black, font size 50
Button::Button(std::string text, unsigned int x, unsigned int y) 
: _posX(x), _posY(y), _text(text), _textColor({0, 0, 0}), _fontSize(50)
{

}

Button::Button(std::string text, unsigned int x, unsigned int y, SDL_Color textColor) 
: _posX(x), _posY(y), _text(text), _textColor(textColor), _fontSize(50)
{

}

Button::Button(std::string text, unsigned int x, unsigned int y, SDL_Color textColor, unsigned int fontSize) 
: _posX(x), _posY(y), _text(text), _textColor(textColor), _fontSize(fontSize)
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
 
        // Transparency
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 
        // Texture handling
        GLuint textTexture;
        glGenTextures( 1, &textTexture );
        glBindTexture( GL_TEXTURE_2D, textTexture ); 
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, 4, text->w, text->h, 0,
                      GL_RGBA, GL_UNSIGNED_BYTE, text->pixels );
 
        // Text dimensions
        uint32_t textWidth = text->w;
        uint32_t textHeight = text->h;
 
        // Free text image
        SDL_FreeSurface(text);
 
        glBindTexture(GL_TEXTURE_2D, textTexture);
 
        // Draw the quad with texture containing text
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
            glTexCoord2d(0, 1); glVertex2f( _posX - (textWidth/2),
                                WIN_HEIGHT - _posY + (textHeight/2));
            glTexCoord2d(0, 0); glVertex2f( _posX - (textWidth/2),
                                WIN_HEIGHT - _posY - (textHeight/2));
            glTexCoord2d(1, 0); glVertex2f( _posX + (textWidth/2),
                                WIN_HEIGHT - _posY - (textHeight/2));
            glTexCoord2d(1, 1); glVertex2f( _posX + (textWidth/2),
                                WIN_HEIGHT - _posY + (textHeight/2));
        glEnd();
        glDisable(GL_TEXTURE_2D);
 
        glDeleteTextures(1, &textTexture);
    }
 
    TTF_Quit();
}