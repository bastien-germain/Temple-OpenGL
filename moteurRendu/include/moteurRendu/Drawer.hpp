#pragma once
#ifndef __DRAWER_HPP__
#define __DRAWER_HPP__

#include "moteurJeu/Section.hpp"

#include "moteurJeu/Player.hpp"

#include "glimac/Program.hpp"
#include <glm/glm.hpp>

#define POSITION_OFFSET_Z 18.f

/// \class Drawer
/// \brief Used to draw the world 

class Drawer 
{
private:
	int _rotateIndicator;
	float _playerRotateX;
	float _playerRotateXSpeed;
	float _speed;

	std::vector<Section*> _sections;

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

	void draw(const float &time, std::vector<std::vector<Section*>> &sectionMat, const glm::mat4 &trackMat, const Player &player);




};

#endif