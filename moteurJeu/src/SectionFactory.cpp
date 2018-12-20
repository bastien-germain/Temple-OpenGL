#include <moteurJeu/SectionFactory.hpp>

SectionFactory::SectionFactory(const float &obstacleInitialPosZ) : _obstacleInitialPosZ(obstacleInitialPosZ) 
{
}

SectionFactory::~SectionFactory() 
{
}

Obstacle SectionFactory::obstacleBuiler(const std::string &key, PositionObserver *observer) const {

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
			return Hole(observer, obstaclePosition, _obstacleInitialPosZ, 1);
		}
		case 'H':
		{
			std::cout << "Large Hole" << std::endl;
			return Hole(observer, obstaclePosition, _obstacleInitialPosZ, 3);
		}
		case 'b':
		{
			std::cout << "Simple Barrier" << std::endl;
			return Barrier(observer, obstaclePosition, _obstacleInitialPosZ, 1);
		}
		case 'B':
		{
			std::cout << "Large Barrier" << std::endl;
			return Barrier(observer, obstaclePosition,_obstacleInitialPosZ, 3);
		}
		case 'r':
		{
			std::cout << "Simple Rock" << std::endl;
			return Rock(observer, obstaclePosition,_obstacleInitialPosZ, 1);
		}
		case 'R':
		{
			std::cout << "Large Rock" << std::endl;
			return Rock(observer, obstaclePosition, _obstacleInitialPosZ, 3);
		}
		default:
			THROW_EXCEPTION("FILE_READING_ERROR : Parser --> Invalid character for Obstacle describing");
		break;
	}
	std::cout << "SECTION_FACTORY.OBSTALCE_BUILDER ENDS" << std::endl;

}

Section SectionFactory::create(const std::string &key, PositionObserver *observer) const 
{
	std::cout << "SECTION_FACTORY.CREATE STARTS..." << std::endl;

	Model model;
		
	std::cout << key << std::endl;

	switch (key[0])
	{
		case 'I':
		{
			std::cout << "CorridorSection" << std::endl;
			Obstacle obstacle(obstacleBuiler(key, observer));
			std::cout << "SECTION_FACTORY.CREATE OBSTALCE_SIZE : " << obstacle.size() << "\n\n\n" << std::endl;
			std::cout << "SECTION_FACTORY.CREATE ENDS" << "\n\n\n" << std::endl;
			return CorridorSection(model, obstacle);
		}
		case 'J':
		{
			std::cout << "Left CornerSection" << std::endl;
			std::cout << "SECTION_FACTORY.CREATE ENDS" << "\n\n\n" << std::endl;
			return CornerSection(model, -1);
		}
		case 'L':
		{
			std::cout << "Right CornerSection" << std::endl;
			std::cout << "SECTION_FACTORY.CREATE ENDS" << "\n\n\n" << std::endl;
			return CornerSection(model, 1);
		}
		case 'T':
		{
			std::cout << "TSection" << std::endl;
			std::cout << "SECTION_FACTORY.CREATE ENDS" << "\n\n\n" << std::endl;
			return TSection(model);
		}	
		default:
			THROW_EXCEPTION("FILE_READING_ERROR : Parser --> Invalid character for Section describing");
		break;
	}
}