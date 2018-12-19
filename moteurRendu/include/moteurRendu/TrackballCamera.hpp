#pragma once
#ifndef __TRACKBALL_CAMERA_HPP__
#define __TRACKBALL_CAMERA_HPP__

#include <SDL/SDL.h>
#include "glimac/glm.hpp"

class TrackballCamera 
{

private:
    float _fDistance; // distance to the center of the scene
    float _fAngleX; // for up and down rotation
    float _fAngleY; // for left and right rotation

public:

	TrackballCamera();
    ~TrackballCamera();

    void moveFront(float delta); // delta > 0 --> camera goes forward
    void rotateLeft(float degree); 
    void rotateUp(float degree); 
    glm::mat4 getViewMatrix() const;
};

#endif