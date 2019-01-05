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
	unsigned int _fontSize;
	int _textWidth, _textHeight;
	bool _isHovered;

public:
	Button(std::string text, unsigned int x, unsigned int y);
    Button(std::string text, unsigned int x, unsigned int y, unsigned int fontSize);
    ~Button();

    void draw();

    void state(int x, int y);
 
};
 
#endif