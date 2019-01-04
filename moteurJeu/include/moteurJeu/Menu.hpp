#pragma once
#ifndef __Menu_HPP__
#define __Menu_HPP__

#define WIN_WIDTH 800
#define WIN_HEIGHT 800

#include <GL/glew.h>
#include <SDL/SDL.h>
 #include <SDL/SDL_ttf.h>


/// \class Menu
/// \brief Game interface
class Menu
{

private:
	bool _visible;

public:
	Menu();
	~Menu();

	inline bool visible() const
	{
		return _visible;
	}

	void show();
	void hide();

	void draw();
    void drawButtons();
};

#endif