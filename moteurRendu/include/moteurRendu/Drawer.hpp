#pragma once
#ifndef __DRAWER_HPP__
#define __DRAWER_HPP__

#include "moteurJeu/CorridorSection.hpp"
#include "moteurJeu/CornerSection.hpp"
#include "moteurJeu/TSection.hpp"


/// \class Drawer
/// \brief Used to draw the world 

class Drawer 
{
private:
	int _rotateIndicator;
	std::vector<Section*> _sections;

public:
	/// \brief Default  constructor
	Drawer();

	/// \brief Destructor
	~Drawer();

	inline int rotateIndicator() {
		return _rotateIndicator;
	}

	inline void rotated(const int &direction) {
		_rotateIndicator = (_rotateIndicator + direction) % 4;
	}

	void draw(const std::vector<std::vector<Section>> &sectionMat);




};

#endif