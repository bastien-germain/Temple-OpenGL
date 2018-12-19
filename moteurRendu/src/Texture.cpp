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
	//delete _lText;
}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, _lText->texturesArray()[_id]);
}

void Texture::debind() const
{
	glBindTexture(GL_TEXTURE_2D,0);
}

void Texture::paramTexture( ) const 
{
	// bind();
	std::cout << "id : "<< _id << std::endl;

	//std::unique_ptr<glimac::Image> earth( new glimac::Image( std::move(_lText->usedTextures()[_id]) ) );



	// glimac::Image earth = _lText->usedTextures()[_id];

	// std::cout<< earth.getPixels() << std::endl;
	// std::cout<< img->getPixels() << std::endl;


	// std::cout<< earth.getWidth() << std::endl;
	// std::cout<< img->getWidth() << std::endl;


	// std::cout<< earth.getHeight() << std::endl;
	// std::cout<< img->getHeight() << std::endl;
	bind();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _lText->usedTextures()[_id]->getWidth(), _lText->usedTextures()[_id]->getHeight(), 0, GL_RGBA, GL_FLOAT, _lText->usedTextures()[_id]->getPixels());
    // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, earth->getWidth(), earth->getHeight(), 0, GL_RGBA, GL_FLOAT, earth->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	debind();	
}

void Texture::activateTexture(GLenum text) const
{
	glActiveTexture(text);
}



