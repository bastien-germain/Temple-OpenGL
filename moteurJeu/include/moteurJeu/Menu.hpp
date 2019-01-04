#pragma once
#ifndef __Menu_HPP__
#define __Menu_HPP__

#define WIN_WIDTH 800
#define WIN_HEIGHT 800

#include <GL/glew.h>
#include "moteurJeu/Button.hpp"


/// \class Menu
/// \brief Game interface
class Menu
{

private:
	void drawButtons();

public:
	Menu();
	~Menu();

	void draw();    
};

#endif