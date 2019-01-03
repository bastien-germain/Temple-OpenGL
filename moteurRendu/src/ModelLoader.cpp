#include "moteurRendu/ModelLoader.hpp"

ModelLoader::ModelLoader(const unsigned int nbTexturesUsed) 
	: _nbTexturesUsed(nbTexturesUsed), _textureManager(TextureManager(nbTexturesUsed))
{
	_textureManager.generateTexture(nbTexturesUsed);
}

ModelLoader::~ModelLoader()
{
}

const Model ModelLoader::loadModel( std::string modelName)
{
	return Model(loadVBO(modelName), loadTexture(modelName));
}

const VBO ModelLoader::loadVBO(std::string modelName) const
{
	Geometry geometry;
    if (!geometry.loadOBJ(_modelsPath + (modelName + ".obj").c_str(), _modelsPath + (modelName + ".mtl" ).c_str() ))
        THROW_EXCEPTION("ERROR WHILE LOADING OBJ : MAKE SURE THE MODEL NAME CORRESPONDS TO OBJ AND MTL FILES NAMES");

    return VBO(geometry);
}

const Texture ModelLoader::loadTexture( std::string modelName)
{    
	Image *image = ImageManager::loadImage(_texturesPath + (modelName + ".png").c_str());
    
    if(image == NULL)
        THROW_EXCEPTION("ERROR WHILE LOADING TEXTURE : MAKE SURE THE FORMAT IS .png" );

    _textureManager.addTexture(*image);
    Texture texture(_textureManager); 
    texture.paramTexture();

    return texture;  
}