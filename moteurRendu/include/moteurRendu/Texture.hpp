#pragma once 
#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__



#include <cstdlib>
#include <glimac/Image.hpp>
#include <GL/glew.h>
#include "moteurRendu/Textures.hpp"
#include <memory>

#include <iostream>
/// \class Texture
/// \brief Contains the texture on the object
class Texture
{
private:

	std::unique_ptr<glimac::Image> _imageTexture;
	unsigned int _id;

public:
	static Textures *_lTextures;
	Texture(unsigned int id );
	//glGenTextures, glBindTexture, glTexImage2D 	

	~Texture();

	void bind() const;
	void debind() const;


	void paramTexture() const;



};
#endif