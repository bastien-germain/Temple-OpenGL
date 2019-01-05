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

public:
	Menu();
	~Menu();

	void addButton(std::string text, unsigned int x, unsigned int y);
	void draw();
	void checkButtonState(int x, int y);    
};

#endif