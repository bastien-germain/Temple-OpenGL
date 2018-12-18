#include "moteurRendu/ListTextures.hpp"

ListTextures::ListTextures(unsigned int &size) : _length(0)
{	
	
	_texturesArray = new GLuint[ size ];
}

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
	delete[] _texturesArray;
}

void ListTextures::addTexture(const glimac::Image &texture)
{
	_usedTextures.push_back(texture);
	_length ++;
}

void ListTextures::generateTexture() const
{
	glGenTextures(_length, _texturesArray);
}