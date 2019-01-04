#pragma once
#ifndef __TEXTURE_MANAGER_HPP__
#define __TEXTURE_MANAGER_HPP__

#include <cstdlib>
#include <vector>
#include <memory>
#include <map>

#include <GL/glew.h>

#include "glimac/Image.hpp"

/// \class TextureManager
/// \brief Class referencing all the textures in a array and their GLuint array
class TextureManager
{
private:
	//Tableau contenant toutes les textures du jeu 
	std::vector<glimac::Image> _usedTextures;
	GLuint* _texturesArray;
	unsigned int _length;

public:
	TextureManager();
	TextureManager(const unsigned int &size);
	// TextureManager(const std::vector<glimac::Image> &map);
	~TextureManager();
	
	inline unsigned int length() const
	{
		return _length;
	};

	inline GLuint* texturesArray() const
	{
		return _texturesArray;
	};

	inline std::vector<glimac::Image> usedTextures() const
	{
		return _usedTextures;
	};
	/// \brief Stocks a texture Image into the array 
	void addTexture(glimac::Image texture);
	/// \brief Generate the texture with opengl code
	void generateTexture(const unsigned int nbTexturesUsed = 0) const; 


};

#endif
