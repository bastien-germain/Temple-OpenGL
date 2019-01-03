#include "moteurJeu/Factory.hpp"

Factory::Factory(const float &sectionInitialPosZ) : 
	_sectionInitialPosZ(sectionInitialPosZ),
	_modelLoader(3)
{
	_corridorModel = _modelLoader.loadModel("corridor");
	_corridorModel.vbo().sendData();
	_cornerModel = _modelLoader.loadModel("corner");
	_cornerModel.vbo().sendData();
	_playerModel = _modelLoader.loadModel("player");
	_playerModel.vbo().sendData();
}

Factory::~Factory() 
{
}

Obstacle Factory::obstacleBuiler(const std::string &key, PositionObserver *observer) const {

	std::cout << "SECTION_FACTORY.OBSTALCE_BUILDER STARTS..." << std::endl;
	unsigned int obstaclePosition;

	switch (key[2])
	{
		case '1':
		{
			std::cout << "Gauche" << std::endl;
			obstaclePosition = 1;
			break;
		}
		case '2':
		{
			std::cout << "Milieu" << std::endl;
			obstaclePosition = 2;
			break;
		}

		case '3':
		{
			std::cout << "Droite" << std::endl;
			obstaclePosition = 3;
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
		case 'h':
		{
			std::cout << "Simple Hole" << std::endl;
			return Hole(observer, obstaclePosition, _sectionInitialPosZ, 1);
		}
		case 'H':
		{
			std::cout << "Large Hole" << std::endl;
			return Hole(observer, obstaclePosition, _sectionInitialPosZ, 3);
		}
		case 'b':
		{
			std::cout << "Simple Barrier" << std::endl;
			return Barrier(observer, obstaclePosition, _sectionInitialPosZ, 1);
		}
		case 'B':
		{
			std::cout << "Large Barrier" << std::endl;
			return Barrier(observer, obstaclePosition,_sectionInitialPosZ, 3);
		}
		case 'r':
		{
			std::cout << "Simple Rock" << std::endl;
			return Rock(observer, obstaclePosition,_sectionInitialPosZ, 1);
		}
		case 'R':
		{
			std::cout << "Large Rock" << std::endl;
			return Rock(observer, obstaclePosition, _sectionInitialPosZ, 3);
		}
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
			std::cout << "SECTION_FACTORY.CREATE OBSTALCE_SIZE : " << obstacle.size() << "\n\n\n" << std::endl;
			std::cout << "SECTION_FACTORY.CREATE ENDS" << "\n\n\n" << std::endl;
			return CorridorSection(&_corridorModel, obstacle);
		}
		case 'J':
		{
			std::cout << "Left CornerSection" << std::endl;
			std::cout << "SECTION_FACTORY.CREATE ENDS" << "\n\n\n" << std::endl;
			return CornerSection(&_cornerModel, -1);
		}
		case 'L':
		{
			std::cout << "Right CornerSection" << std::endl;
			std::cout << "SECTION_FACTORY.CREATE ENDS" << "\n\n\n" << std::endl;
			return CornerSection(&_cornerModel, 1);
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
	_cornerModel.vbo().deleteBuf();
	_corridorModel.vbo().deleteBuf();
	_playerModel.vbo().deleteBuf();
}
