#include "moteurRendu/Texture.hpp"

Texture::Texture()
{

}

Texture::Texture(unsigned int id, ListTextures &lText) :_id(id)
{
	_lText = &lText;
}

Texture::Texture(const Texture &copied) 
{

}

Texture::~Texture()
{
	delete _lText;
}

void Texture::bind() const
{
	//glBindTexture(GL_TEXTURE_2D, texturesArray[_id]);
}

void Texture::debind() const
{
	glBindTexture(GL_TEXTURE_2D,0);
}

void Texture::paramTexture() const 
{
	bind();

	debind();	
}



