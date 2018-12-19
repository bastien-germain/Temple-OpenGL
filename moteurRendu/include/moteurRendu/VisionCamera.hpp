#pragma onc
#ifndef __VISION_CAMERA_HPP__
#define __VISION_CAMERA_HPP__

#include <SDL/SDL.h>
#include "glimac/glm.hpp"

class VisionCamera 
{

private:
    float _fAngleY; // for left and right rotation

public:

	VisionCamera();
    ~VisionCamera();

    void rotateLeft(float degree);  
    glm::mat4 getViewMatrix() const;
};

#endif