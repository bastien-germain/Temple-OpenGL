#include "moteurJeu/Coin.hpp"

Coin::Coin() : _value(1), _position(0)
{

}

Coin::Coin(const unsigned int value, const unsigned int position, const LightingModel &model) 
	: _value(value), _position(position), _model(model)
{

}

Coin::~Coin() 
{

}