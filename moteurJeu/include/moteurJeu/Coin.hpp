#pragma once
#ifndef __COIN_HPP__
#define __COIN_HPP__

#include "moteurRendu/LightingModel.hpp"

/// \class Coin
/// \brief things the player can collect on the way
class Coin 
{

private:
	unsigned int _value;
	unsigned int _position; // -1 : left; 0 : middle; 1: right
	LightingModel _model;
	
public:
	Coin();
	Coin(const unsigned int value, const unsigned int position, const LightingModel &model); 

	~Coin();	

};

#endif