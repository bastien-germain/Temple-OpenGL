#pragma once
#ifndef __MODEL_LOADER_HPP__
#define __MODEL_LOADER_HPP__

#include "glimac/FilePath.hpp"
#include "glimac/Image.hpp"
#include "glimac/Geometry.hpp"

#include "moteurRendu/Model.hpp"
#include "moteurRendu/TextureManager.hpp"

#include "moteurJeu/Exception.hpp"

using namespace glimac;

/// \class ModelLoader
/// \brief Used to load models
class ModelLoader 
{

private: 
	const unsigned int _nbTexturesUsed;
	const FilePath _modelsPath = "../Temple-OpenGL/app/assets/models/";
	const FilePath _texturesPath = "../Temple-OpenGL/app/assets/textures/";
	TextureManager _textureManager;

public:
	/// \brief Default  constructor
	ModelLoader(const unsigned int nbTexturesUsed);

	/// \brief Destructor
	~ModelLoader();

	const Model loadModel(const char* modelName);

	const VBO loadVBO(const char* modelName) const;

	const Texture loadTexture(const char* modelName);

};

#endif