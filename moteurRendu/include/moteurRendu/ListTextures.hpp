#pragma once
#ifndef __LIST_TEXTURES_HPP__
#define __LIST_TEXTURES_HPP__

#include <cstdlib>
#include <glimac/Image.hpp>
#include <vector>
#include <memory>
#include "moteurRendu/Texture.hpp"
#include <map>

class ListTextures
{
private:
	std::vector<glimac::Image> _usedTextures;

	

public:
	ListTextures();
	// ListTextures(const std::vector<glimac::Image> &map);
	~ListTextures();
	void addTexture(const glimac::Image &texture);


};

#endif
