#include "moteurRendu/ModelLoader.hpp"

ModelLoader::ModelLoader(const unsigned int nbTexturesUsed) 
	: _nbTexturesUsed(nbTexturesUsed), _textureManager(TextureManager(nbTexturesUsed))
{
	_textureManager.generateTexture(nbTexturesUsed);
}

ModelLoader::~ModelLoader()
{
}

const Model ModelLoader::loadModel(const char* modelName)
{
	return Model(loadVBO(modelName), loadTexture(modelName));
}

const VBO ModelLoader::loadVBO(const char* modelName) const
{
	Geometry geometry;

    if (!geometry.loadOBJ(_modelsPath + modelName + ".obj", _modelsPath + modelName + ".mtl"))
        THROW_EXCEPTION("ERROR WHILE LOADING OBJ : MAKE SURE THE MODEL NAME CORRESPONDS TO OBJ AND MTL FILES NAMES");

    return VBO(0, geometry);
}

const Texture ModelLoader::loadTexture(const char* modelName)
{
	Image *image = ImageManager::loadImage(_texturesPath + modelName + ".png");
    
    if(image == NULL)
        THROW_EXCEPTION("ERROR WHILE LOADING TEXTURE : MAKE SURE THE FORMAT IS .png");

    _textureManager.addTexture(*image);
    Texture texture(_textureManager); 
    texture.paramTexture();

    return texture;  
}