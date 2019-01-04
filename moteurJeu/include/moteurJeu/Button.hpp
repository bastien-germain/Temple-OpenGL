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
	unsigned int _posX, _posY; 
	std::string _text;
	SDL_Color _textColor;
	unsigned int _fontSize;

public:
	Button(std::string text, unsigned int x, unsigned int y);
    Button(std::string text, unsigned int x, unsigned int y, SDL_Color textColor);
    Button(std::string text, unsigned int x, unsigned int y, SDL_Color textColor, unsigned int fontSize);
    ~Button();

    void draw();
};
 
#endif