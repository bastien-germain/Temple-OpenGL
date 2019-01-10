#ifndef FREEFLYCAMERA_HPP__
#define FREEFLYCAMERA_HPP__
#include "moteurRendu/FreeflyCamera.hpp"


FreeflyCamera::FreeflyCamera(const float &smoothness) : 
m_Position(0, 0, -1), m_fPhi(180), m_fTheta(0), _smoothness(smoothness)
{
	computeDirectionVectors();
}

FreeflyCamera::FreeflyCamera(const FreeflyCamera &copied) : 
m_Position(copied.m_Position), m_fPhi(copied.m_fPhi), m_fTheta(copied.m_fTheta), _smoothness(copied._smoothness)
{
	computeDirectionVectors();
}

FreeflyCamera::~FreeflyCamera()
{

}

void FreeflyCamera::computeDirectionVectors()
{
	const float thetaRad = glm::radians(m_fTheta);
	const float phiRad = glm::radians(m_fPhi);
	m_FrontVector = glm::vec3(glm::cos(thetaRad)*glm::sin(phiRad), glm::sin(thetaRad),glm::cos(thetaRad)*glm::cos(phiRad));

	m_LeftVector = glm::vec3(glm::sin(phiRad + 3.14159/2), 0, glm::cos(phiRad + 3.14159/2));

	m_UpVector = glm::cross(m_FrontVector, m_LeftVector);

}



void FreeflyCamera::rotateLeft(float degrees)
{

	if(m_fPhi >= 90 && m_fPhi <= 270)
	{
		m_fPhi += 10*glm::radians(-degrees);
	}
	else if (m_fPhi < 90)
	{
		m_fPhi = 90;
	}
	else
	{
		m_fPhi = 270;
	}
	computeDirectionVectors();
}

void FreeflyCamera::rotateUp(float degrees)
{
	if(m_fTheta >= -90 && m_fTheta <= 90)
	{
		m_fTheta += 10*glm::radians(-degrees);
	}
	else if (m_fTheta < -90)
	{
		m_fTheta = -90;
	}
	else
	{
		m_fTheta = 90;
	}
	computeDirectionVectors();	
}

void FreeflyCamera::moveTop(float distance)
{
	m_Position.y = m_Position.y + distance;

	computeDirectionVectors();
}

glm::mat4 FreeflyCamera::getViewMatrix() const
{
	return glm::lookAt(m_Position, m_Position + m_FrontVector, m_UpVector);
}

#endif