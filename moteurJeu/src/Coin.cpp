#include "moteurJeu/Coin.hpp"

Coin::Coin() : _value(1); _position(0)
{

}

Coin::Coin(const unsigned int value, const unsigned int position) : _value(value), _position(position) 
{

}

Coin::~Coin() 
{

}