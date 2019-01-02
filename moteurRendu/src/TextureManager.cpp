#include "moteurRendu/TextureManager.hpp"

TextureManager::TextureManager(const unsigned int &size) : _length(0)
{	
	
	_texturesArray = new GLuint[ size ];
}

TextureManager::TextureManager()
{

}

// TextureManager::TextureManager(const std::vector<glimac::Image> &map)

// {
// 	for (std::vector<glimac::Image>::iterator it = map.begin(); it != map.end() ; it++)
// 	{
// 		_usedTextures.push_back(*it);
// 	}
// }

TextureManager::~TextureManager()
{
	delete[] _texturesArray;
}

void TextureManager::addTexture(glimac::Image texture)
{

	//_usedTextures.push_back(texture));
	//glimac::Image* t;
	//std::move(texture,t);
	_usedTextures.push_back(texture);

	_length ++;
}

void TextureManager::generateTexture(const unsigned int nbTexturesUsed) const 
{
	glGenTextures(nbTexturesUsed, _texturesArray);
}