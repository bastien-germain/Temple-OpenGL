#include "moteurRendu/VisionCamera.hpp"
#include <iostream>

VisionCamera::VisionCamera() :_fAngleY(0)
{
}

VisionCamera::~VisionCamera() 
{
}

void VisionCamera::rotateLeft(float degree) 
{
	// PENSER A LIMITER LA ROTATION
    _fAngleY = degree / 180 * M_PI;
    std::cout << "rotate by" << degree << std::endl;
}

glm::mat4 VisionCamera::getViewMatrix() const
{

    glm::mat4 MatrixId = glm::mat4(1.0);

    glm::mat4 matrixRotateLeft = glm::rotate( MatrixId, _fAngleY, glm::vec3(1, 0, 0) ); // y rotate

    return matrixRotateLeft;
}


