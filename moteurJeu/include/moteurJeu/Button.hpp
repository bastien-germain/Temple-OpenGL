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
	unsigned int _posX, _posY; // position of the left down corner
	std::string _text;
	unsigned int _fontSize;
	SDL_Color _textColor;;
	int _textWidth, _textHeight;

	// à voir pour rajouter un attribut permettant d'identifier le bouton au clic

public:
    Button(const std::string &text, const unsigned int x, const unsigned int y, const unsigned int fontSize);
    ~Button();

    void draw();

    void checkHovering(const int x, const int y);
    bool checkClick(const int x, const int y) const;
    void updateText(const std::string &newText);
 
};
 
#endif