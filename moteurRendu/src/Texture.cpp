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
	glBindTexture(GL_TEXTURE_2D, _lText->texturesArray()[_id]);
}

void Texture::debind() const
{
	glBindTexture(GL_TEXTURE_2D,0);
}

void Texture::paramTexture() const 
{
	bind();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _lText->usedTextures()[_id].getWidth(), _lText->usedTextures()[_id].getHeight(), 0, GL_RGBA, GL_FLOAT, _lText->usedTextures()[_id].getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	debind();	
}

void Texture::activateTexture(GLenum text) const
{
	glActiveTexture(text);
}



