#pragma once
#ifndef __Menu_HPP__
#define __Menu_HPP__

#define WIN_WIDTH 800
#define WIN_HEIGHT 800

#include <vector>
#include <string>
#include <GL/glew.h>
#include "moteurJeu/Button.hpp"


/// \class Menu
/// \brief Game interface
class Menu
{

private:
	std::vector<Button> _buttons;
	void drawButtons();

	// si plusieurs menus (debut ou pause par exemple)
	// suffit de faire plusieurs vecteurs et de passer le bon en parametre de draw et des check

public:
	Menu();
	~Menu();

	void addButton(const std::string &text, const unsigned int x, const unsigned int y, const unsigned int fontSize);
	void draw();
	void checkButtonHovering(const int x, const int y);    
	bool checkButtonClick(const int x, const int y) const;    
};

#endif