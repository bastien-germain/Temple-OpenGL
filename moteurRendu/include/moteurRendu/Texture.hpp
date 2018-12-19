#pragma once 
#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__



#include <cstdlib>
#include <glimac/Image.hpp>
#include <GL/glew.h>
#include "moteurRendu/ListTextures.hpp"
#include <memory>


#include <iostream>
/// \class Texture
/// \brief Contains the texture of one object, there is one link to the unique object ListTextures which contains all the textures Image
class Texture
{
private:

	unsigned int _id;
	//Lien vers l'object unique de l'application ListTextures
	ListTextures* _lText;


public:
	Texture();
	Texture(unsigned int id, ListTextures &lText );

	/// \param copied : the Texture to copy into the current object
	Texture(const Texture &copied);

	inline unsigned int id() const
	{
		return _id;
	}

	~Texture();


	void bind() const;
	void debind() const;

	/// \brief Gives all the parameters for the texture, how to wrap the object into it
	void paramTexture( ) const;
	/// \brief Activate the texture 
	void activateTexture(GLenum text) const;


};
#endif