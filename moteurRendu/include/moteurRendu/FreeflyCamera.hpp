#pragma once

#include "glimac/glm.hpp"

#include "glimac/common.hpp"
#include <cstdlib>
#include <iostream>

#define PI 3.14159



class FreeflyCamera {
	
	private:
		glm::vec3 m_Position;
		float m_fPhi;
		float m_fTheta;
		glm::vec3 m_FrontVector;
		glm::vec3 m_LeftVector;
		glm::vec3 m_UpVector;
		float _smoothness;

		void computeDirectionVectors();


	public:
		FreeflyCamera(const float &smoothness = 0.5f);
		FreeflyCamera(const FreeflyCamera &copied);
		~FreeflyCamera();

		void rotateUp(float degrees);
		void rotateLeft(float degrees);
		void moveTop(float distance);
		glm::mat4 getViewMatrix() const;
		
		inline const float smoothness() const {
			return _smoothness;
		}
};
