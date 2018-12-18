#include "moteurRendu/ListTextures.hpp"

ListTextures::ListTextures() 
{	
	
}

// ListTextures::ListTextures(const std::vector<glimac::Image> &map)

// {
// 	for (std::vector<glimac::Image>::iterator it = map.begin(); it != map.end() ; it++)
// 	{
// 		_usedTextures.push_back(*it);
// 	}
// }

ListTextures::~ListTextures()
{

}

void ListTextures::addTexture(const glimac::Image &texture)
{
	_usedTextures.push_back(texture);
	//_size ++;
}