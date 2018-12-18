#pragma once
#ifndef __LIST_TEXTURES_HPP__
#define __LIST_TEXTURES_HPP__

#include <cstdlib>
#include <glimac/Image.hpp>
#include <vector>
#include <memory>
#include <map>
#include <GL/glew.h>

class ListTextures
{
private:
	std::vector<glimac::Image> _usedTextures;
	GLuint* _texturesArray;
	unsigned int _length;

	

public:
	ListTextures();
	ListTextures(unsigned int &size);
	// ListTextures(const std::vector<glimac::Image> &map);
	~ListTextures();
	inline unsigned int length() const
	{
		return _length;
	};
	void addTexture(const glimac::Image &texture);
	void generateTexture() const ; 


};

#endif
