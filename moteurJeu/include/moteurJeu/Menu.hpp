#pragma once
#ifndef __Menu_HPP__
#define __Menu_HPP__


/// \class Menu
/// \brief Game interface
class Menu
{

private:
	bool visible;

public:
	Menu();
	~Menu();

	void show();

	void hide();
};

#endif