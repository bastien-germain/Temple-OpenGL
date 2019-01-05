#include "moteurJeu/Menu.hpp"
#include <iostream>

Menu::Menu()
{

}

Menu::~Menu()
{
	
}

void Menu::draw()
{		
	// 2D
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0f, WIN_WIDTH, WIN_HEIGHT, 0.0f, 0.0f, 1.0f); 
  
    glDisable(GL_DEPTH_TEST);
 
    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.5, 0.5, 0.8, 1);

	drawButtons();

    glFlush();
    SDL_GL_SwapBuffers();	
}


void Menu::drawButtons()
{
	std::vector<Button>::iterator it;

	for(it = _buttons.begin(); it != _buttons.end(); it++ )
	{
        (*it).draw();
	}
}

void Menu::addButton(std::string text, unsigned int x, unsigned int y, unsigned int fontSize)
{	
	Button button(text, x, y, fontSize);
	_buttons.push_back(button);
}


void Menu::checkButtonHovering(int x, int y)
{
	std::vector<Button>::iterator it;

	for(it = _buttons.begin(); it != _buttons.end(); it++ )
	{	
        (*it).checkHovering(x, y);
	}
}

bool Menu::checkButtonClick(int x, int y) const
{
	std::vector<Button>::const_iterator it;

	for(it = _buttons.begin(); it != _buttons.end(); it++ )
	{
        if((*it).checkClick(x, y))
        {
        	return true;
        }
	}
	return false;
}
