#pragma once
#ifndef __LIST_TEXTURES_HPP__
#define __LIST_TEXTURES_HPP__

#include <cstdlib>
#include <glimac/Image.hpp>
#include <vector>
#include <memory>
#include <map>
#include <GL/glew.h>


/// \class ListTextures
/// \brief Class referencing all the textures in a array and their GLuint array
class ListTextures
{
private:
	//Tableau contenant toutes les textures du jeu 
	std::vector<glimac::Image*> _usedTextures;
	GLuint* _texturesArray;
	unsigned int _length;

	

public:
	ListTextures();
	ListTextures(const unsigned int &size);
	// ListTextures(const std::vector<glimac::Image> &map);
	~ListTextures();
	inline unsigned int length() const
	{
		return _length;
	};

	inline GLuint* texturesArray() const
	{
		return _texturesArray;
	};

	inline std::vector<glimac::Image*> usedTextures() const
	{
		return _usedTextures;
	};
	/// \brief Stocks a texture Image into the array 
	void addTexture(glimac::Image* texture);
	/// \brief Generate the texture with opengl code
	void generateTexture() const ; 


};

#endif
