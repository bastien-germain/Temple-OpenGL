#include "moteurRendu/Texture.hpp"

Texture::Texture()
{

}

Texture::Texture(unsigned int id) :_id(id)
{
	//glGenTextures()
}

Texture::Texture(const Texture &copied) 
{

}

Texture::~Texture()
{

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

