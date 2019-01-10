#include "moteurJeu/Factory.hpp"

Factory::Factory() 
	: _modelLoader(11),
	_playerModel(_modelLoader.loadModel("player")),
	_enemyModel(_modelLoader.loadModel("enemy")),
	_corridorModel(_modelLoader.loadModel("corridorWall")),
	_cornerLeftModel(_modelLoader.loadModel("cornerLeftWall")),
	_cornerRightModel(_modelLoader.loadModel("cornerRightWall")),
	_skyboxModel(_modelLoader.loadModel("cubeSkybox")),
	_brancardModel(_modelLoader.loadModel("brancardObs"))

{
	_playerModel.vbo().sendData();
	_enemyModel.vbo().sendData();
	_corridorModel.vbo().sendData();
	_cornerLeftModel.vbo().sendData();
	_cornerRightModel.vbo().sendData();
	_skyboxModel.vbo().sendData();
	_brancardModel.vbo().sendData();

	// _tModel = _modelLoader.loadModel("tsectionWall");
	// _tModel.vbo().sendData();


	// _clapTrapModel = _modelLoader.loadModel("clapTrap");
	// _clapTrapModel.vbo().sendData();


	// _deambuleModel = _modelLoader.loadModel("deambuleObs");
	// _deambuleModel.vbo().sendData();

	// _clapTrapModel = _modelLoader.loadModel("clapTrap");
	// _clapTrapModel.vbo().sendData();

	// _chairsStackModel = _modelLoader.loadModel("chairsStack");
	// _chairsStackModel.vbo().sendData();

	

	// _skyboxModel = _modelLoader.loadModel("skybox");
	// _skyboxModel.vbo().sendData();

	// _bonusModel = _modelLoader.loadModel("bonus");
	// _bonusModel.vbo().sendData();

}

Factory::~Factory() 
{
}

Obstacle Factory::obstacleBuiler(const std::string &key, PositionObserver *observer) const {

	std::cout << "SECTION_FACTORY.OBSTALCE_BUILDER STARTS..." << std::endl;
	int obstaclePosition;

	switch (key[2])
	{
		case '1':
		{
			std::cout << "Gauche" << std::endl;
			obstaclePosition = -1;
			break;
		}
		case '2':
		{
			std::cout << "Milieu" << std::endl;
			obstaclePosition = 0;
			break;
		}

		case '3':
		{
			std::cout << "Droite" << std::endl;
			obstaclePosition = 1;
			break;
		}
		default:
			THROW_EXCEPTION("FILE_READING_ERROR : Parser --> Invalid character for Position describing");
		break;
	}
	
	switch (key[1])
	{
		case 'X':
		{
			std::cout << "No Obstacle" << std::endl;
			return Obstacle();
		}
		// case 'C':
		// {
		// 	return Obstacle(&_chairsStackModel, observer, 0, 3);
		// }
		case 'B':
		{
			return Obstacle(&_brancardModel, observer, 0, 0, 3, 3);
		}
		// case 'D':
		// {
		// 	return Obstacle(&_deambuleModel, observer, obstaclePosition, 1);
		// }
		default:
			THROW_EXCEPTION("FILE_READING_ERROR : Parser --> Invalid character for Obstacle describing");
		break;
	}
	std::cout << "SECTION_FACTORY.OBSTALCE_BUILDER ENDS" << std::endl;

}

Section Factory::create(const std::string &key, PositionObserver *observer) const 
{
	std::cout << "SECTION_FACTORY.CREATE STARTS..." << std::endl;
		
	std::cout << key << std::endl;

	switch (key[0])
	{
		case 'I':
		{
			std::cout << "CorridorSection" << std::endl;
			Obstacle obstacle(obstacleBuiler(key, observer));
			std::cout << "SECTION_FACTORY.CREATE OBSTALCE_SIZE : " << obstacle.sizeX() << "\n\n\n" << std::endl;
			std::cout << "SECTION_FACTORY.CREATE ENDS" << "\n\n\n" << std::endl;
			return Section(&_corridorModel, 0, 0, obstacle);
		}
		case 'J':
		{
			std::cout << "Left CornerSection" << std::endl;
			std::cout << "SECTION_FACTORY.CREATE ENDS" << "\n\n\n" << std::endl;
			return Section(&_cornerRightModel, 1, -1);
		}
		case 'L':
		{
			std::cout << "Right CornerSection" << std::endl;
			std::cout << "SECTION_FACTORY.CREATE ENDS" << "\n\n\n" << std::endl;
			return Section(&_cornerRightModel, 1, 1);
		}
		/*
		case 'T':
		{
			std::cout << "TSection" << std::endl;
			std::cout << "SECTION_FACTORY.CREATE ENDS" << "\n\n\n" << std::endl;
			return TSection(model);
		}
		*/	
		default:
			THROW_EXCEPTION("FILE_READING_ERROR : Parser --> Invalid character for Section describing");
		break;
	}
}

void Factory::deleteModelBuffers() 
{
	_playerModel.vbo().deleteBuf();
	_enemyModel.vbo().deleteBuf();

	_cornerRightModel.vbo().deleteBuf();
	_cornerLeftModel.vbo().deleteBuf();
	_corridorModel.vbo().deleteBuf();
	//_tModel.vbo().deleteBuf();

	// _deambuleModel.vbo().deleteBuf();
	// _clapTrapModel.vbo().deleteBuf();
	// _chairsStackModel.vbo().deleteBuf();
	_brancardModel.vbo().deleteBuf();

	//_skyboxModel.vbo().deleteBuf();

	// _bonusModel.vbo().deleteBuf();

}
