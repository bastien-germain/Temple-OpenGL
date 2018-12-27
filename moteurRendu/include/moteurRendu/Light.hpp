#pragma once
#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

#include "VAO.hpp"
#include <vector>
#include <cstdlib>
#include <GL/glew.h>
#include "glimac/glm.hpp"
#include "glimac/common.hpp"
#include <glimac/Program.hpp>
#include "moteurRendu/TrackballCamera.hpp"
#include "../../moteurJeu/include/moteurJeu/Exception.hpp"



using namespace glimac;

static const unsigned int MAX_POINT_LIGHTS  = 5;

class Light 
{

public:

	struct LightProperties 
	{
		bool _isPoint;
		glm::vec3 _posOrDir;
		glm::vec3 _Kd;
		glm::vec3 _Ks;
		float _shininess;
		glm::vec3 _lightIntensity;
	};

	Light(const bool isPoint = true, 
		  const glm::vec3 &posOrDir = glm::vec3(0.0),
		  const glm::vec3 &Kd = glm::vec3(0.0),
		  const glm::vec3 &Ks = glm::vec3(0.0),
		  const float &shininess = 0.0, 
		  const glm::vec3 &lightIntensity = glm::vec3(0.0));

	~Light();

	inline LightProperties properties() const 
	{
		return _properties;
	}

	inline const int id() const 
	{
		return _id;
	}

	inline void position(const glm::vec3 &position) {
		if (_properties._isPoint)
			_properties._posOrDir = position;
		else 
			THROW_EXCEPTION("ERROR : THIS LIGHT IS NOT A POINT LIGHT - CANNOT CHANGE POSITION : TRY USING .direction(aDirection)");
	}

	inline void direction(const glm::vec3 &direction) {
		if (!_properties._isPoint)
			_properties._posOrDir = direction;
		else 
			THROW_EXCEPTION("ERROR : THIS LIGHT IS A POINT LIGHT - CANNOT CHANGE DIRECTION : TRY USING .position(aPosition)");
	}

	inline Light &operator = (const Light &toAssign) 
	{
		if (&toAssign != this) 
		{	
			_properties._isPoint = toAssign._properties._isPoint;
			_properties._posOrDir = toAssign._properties._posOrDir;
			_properties._Ks = toAssign._properties._Ks;
			_properties._Kd = toAssign._properties._Kd;
			_properties._shininess = toAssign._properties._shininess;
			_properties._lightIntensity = toAssign._properties._lightIntensity;
		}
		return *this;
	}

	void sendLightShader(Program &program, const std::string &lightRef) const;

private:
	LightProperties _properties;
	const int _id;
	static int lightsCount;

};

#endif