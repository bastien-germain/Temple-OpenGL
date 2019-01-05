#pragma once
#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#define WIN_WIDTH 800
#define WIN_HEIGHT 800

#include <string> 
#include <GL/glew.h>
#include <SDL/SDL_ttf.h>

/// \class Button
/// \brief Button for Menu
class Button
{

private:
	unsigned int _posX, _posY; // position of the button center
	std::string _text;
	unsigned int _fontSize;
	SDL_Color _textColor;;
	int _textWidth, _textHeight;

	// à voir pour rajouter un attribut permettant d'identifier le bouton au clic

public:
    Button(std::string text, unsigned int x, unsigned int y, unsigned int fontSize);
    ~Button();

    void draw();

    void checkHovering(int x, int y);
    bool checkClick(int x, int y) const;
 
};
 
#endif