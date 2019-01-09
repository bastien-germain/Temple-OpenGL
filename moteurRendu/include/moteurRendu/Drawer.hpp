#pragma once
#ifndef __DRAWER_HPP__
#define __DRAWER_HPP__

#include "moteurJeu/Section.hpp"

#include "moteurJeu/Player.hpp"
#include "moteurJeu/Enemy.hpp"
#include "moteurJeu/Skybox.hpp"

#include "glimac/Program.hpp"
#include <glm/glm.hpp>

#define POSITION_OFFSET_Z -20.f
#define CORNER_OFFSET_Z 7.f
#define CORNER_OFFSET_X 7.f
#define DRAW_DISTANCE (6 * POSITION_OFFSET_Z)

#define WORLD_SPEED 0.05f

/// \class Drawer
/// \brief Used to draw the world 

class Drawer 
{
private:
	int _globalRotateIndicator;
	int _localRotateIndicator;
	unsigned int _rotateIndex[4];

	std::vector<Light> _lights;

	glm::mat4  _projMatrix;
	glm::mat4  _globalMVMatrix;
	glm::mat4  _normalMatrix;

	glm::mat4 _playerMatrix;
	glm::mat4 _enemyMatrix;
	glm::mat4 _objectMatrix;
	glm::mat4 _worldMatrix;
	glm::mat4 _tmpMatrix;

	GLint _uMVMatrix;
	GLint _uMVPMatrix;
    GLint _uNormalMatrix;
    GLint _uTexture;
    GLint _uTextureSkybox;
    GLint _uAmbiantLight;
    GLint _uNbLights;
    GLint _uLightOn;

    const std::string _refLight = "uLights";

public:
	/// \brief Default  constructor
	Drawer(const Program &program);

	/// \brief Destructor
	~Drawer();

	inline void rotated(const int &direction, int &indicator) {
		indicator = (indicator + direction) % 4;
	}

	void initializeLights(const Program &program);

	void drawPlayer(Player &player);
	void drawEnemy(Enemy &enemy);
	void drawSkybox(Skybox &skybox);
	void drawSection(const Section &section, const float &posX, const float &posZ);

	void draw(std::vector<Section> &sectionVec, const glm::mat4 &trackMat, Player &player, Enemy &enemy, Skybox &skybox, const Program &program);
	//void draw(std::vector<std::vector<Section*>> &sectionMat, const glm::mat4 &trackMat, Player &player, Enemy &enemy, const Program &program);




};

#endif
