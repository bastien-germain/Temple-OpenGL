#include "moteurRendu/TrackballCamera.hpp"
#include <iostream>
#include <math.h>

TrackballCamera::TrackballCamera() 
{
     _fDistance = 5;
     _fAngleX = 0;
     _fAngleY = 0;
}

TrackballCamera::~TrackballCamera() 
{
}

void TrackballCamera::moveFront(float delta) 
{
     _fDistance += delta;
}

void TrackballCamera::rotateLeft(float degree) 
{
    _fAngleX = degree / 180 * M_PI;
}

void TrackballCamera::rotateUp(float degree)
{
    _fAngleY = degree / 180 * M_PI;
}

glm::mat4 TrackballCamera::getViewMatrix() const
{

    glm::mat4 MatrixId = glm::mat4(1.0);

    glm::mat4 matrixMoveFront = glm::translate( MatrixId, glm::vec3(0.0f, 0.0f, -_fDistance) ); // z translate
    glm::mat4 matrixRotateLeft = glm::rotate( MatrixId, _fAngleX, glm::vec3(1, 0, 0) ); // x rotate
    glm::mat4 matrixRotateUp = glm::rotate( MatrixId, _fAngleY, glm::vec3(0, 1, 0) ); // y rotate

    return matrixMoveFront * matrixRotateLeft * matrixRotateUp;
}


