#include "moteurJeu/Menu.hpp"

Menu::Menu() : visible(true)
{

}

Menu::~Menu()
{
	
}

void Menu::hide()
{
	visible = false;
}

void Menu::show()
{
	visible = true;
}