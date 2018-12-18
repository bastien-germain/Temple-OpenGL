#ifndef __TEXURES_HPP__
#define __TEXURES_HPP__

#include <vector>
#include <cstdlib>

class Textures 
{
public:
    static Textures* instance();
    //void addTexture(const Texture &text) ;

private:
	//std::vector<ptr_Image<> _usedTextures;
    static Textures* _instance;
    Textures();
    ~Textures();
    
};
#endif