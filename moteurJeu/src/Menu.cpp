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

	this->drawButtons();

    glFlush();
    SDL_GL_SwapBuffers();	
}


void Menu::drawButtons()
{
	Button test("test 1", 80, 100);
	test.draw();

	Button test2("test 2", 200, 500, {200, 0, 60});
	test2.draw();

	Button test3("test 3", WIN_WIDTH/2, WIN_HEIGHT/2, {255, 255, 255}, 100);	
	test3.draw();
}
