#pragma once
#ifndef __DRAWER_HPP__
#define __DRAWER_HPP__

#include "moteurJeu/Section.hpp"

#include "moteurJeu/Player.hpp"

#include "glimac/Program.hpp"
#include <glm/glm.hpp>

#define POSITION_OFFSET_Z 20.f
#define DRAW_DISTANCE (6 * POSITION_OFFSET_Z)

#define WORLD_SPEED 0.005f

/// \class Drawer
/// \brief Used to draw the world 

class Drawer 
{
private:
	int _rotateIndicator;
	unsigned int _lastRotateIndex;

	std::vector<Light> _lights;

	glm::mat4  _projMatrix;
	glm::mat4  _globalMVMatrix;
	glm::mat4  _normalMatrix;
	glm::mat4 _playerMatrix;
	glm::mat4 _worldMatrix;
	glm::mat4 _tmpMatrix;

	GLint _uMVMatrix;
	GLint _uMVPMatrix;
    GLint _uNormalMatrix;
    GLint _uTexture;
    GLint _uAmbiantLight;
    GLint _uNbLights;

    const std::string _refLight = "uLights";

public:
	/// \brief Default  constructor
	Drawer(const Program &program);

	/// \brief Destructor
	~Drawer();

	inline int rotateIndicator() {
		return _rotateIndicator;
	}

	inline void rotated(const int &direction) {
		_rotateIndicator = (_rotateIndicator + direction) % 4;
	}

	void initializeLights(const Program &program);

	void draw(std::vector<std::vector<Section*>> &sectionMat, const glm::mat4 &trackMat, Player &player, const Program &program);




};

#endif