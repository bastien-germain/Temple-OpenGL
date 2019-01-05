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

	void addButton(std::string text, unsigned int x, unsigned int y, unsigned int fontSize);
	void draw();
	void checkButtonHovering(int x, int y);    
	bool checkButtonClick(int x, int y) const;    
};

#endif