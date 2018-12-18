
#include "moteurRendu/Textures.hpp"

Textures* Textures::instance()
{
    if (_instance == 0)
    {
        _instance = new Textures();
    }

    return _instance;
}

Textures::Textures()
{}

/*Textures::addTexture(const Texture &text)
{
}*/
