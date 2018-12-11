#include "glimac/TrackballCamera.hpp"
namespace glimac{


	TrackballCamera::TrackballCamera(): m_fDistance(5), m_fAngleX(0),m_fAngleY(0)
	{}


	void TrackballCamera::moveFront(const float delta){
		m_fDistance += delta;
	};

	void TrackballCamera::rotateLeft(const float degrees) {
		m_fAngleY += degrees;
	}
		

	void TrackballCamera::rotateUp(const float degrees) {
		m_fAngleY += degrees;
	}

	glm::mat4 TrackballCamera::getViewMatrix() const {
		return glm::translate(glm::rotate(glm::rotate(glm::mat4(0),glm::radians(m_fAngleX),glm::vec3(1,0,0)),glm::radians(m_fAngleY),glm::vec3(0,1,0)),glm::vec3(0,0,-m_fDistance));
	}
}
