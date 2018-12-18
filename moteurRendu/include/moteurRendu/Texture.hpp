#pragma once 
#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__



#include <cstdlib>
#include <glimac/Image.hpp>
#include <GL/glew.h>
//#include "moteurRendu/Textures.hpp"
#include <memory>

#include <iostream>
/// \class Texture
/// \brief Contains the texture on the object
class Texture
{
private:

	unsigned int _id;

public:
	// static Textures _lTextures;
	Texture();
	Texture(unsigned int id );
	//glGenTextures, glBindTexture, glTexImage2D 	

	/// \param copied : the Texture to copy into the current object
	Texture(const Texture &copied);

	~Texture();

	void bind() const;
	void debind() const;


	void paramTexture() const;


};
#endif