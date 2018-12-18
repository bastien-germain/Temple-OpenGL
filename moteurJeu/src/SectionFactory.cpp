#include <moteurJeu/SectionFactory.hpp>

SectionFactory::SectionFactory() 
{
}

SectionFactory::~SectionFactory() 
{
}

Section SectionFactory::create(const std::string &key) const 
{
	// A CHANGER AVEC LES MODELES CORRESPONDANTS
	Model model;
	Obstacle obstacle;
	Section section;
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
			obstacle = Obstacle(0, 0);
			break;
		}
		case 'h':
		{
			std::cout << "Simple Hole" << std::endl;
			obstacle = Hole(obstaclePosition, 1);
			break;
		}
		case 'H':
		{
			std::cout << "Large Hole" << std::endl;
			Hole obstacle(obstaclePosition, 3);
			break;
		}
		case 'b':
		{
			std::cout << "Simple Barrier" << std::endl;
			Barrier obstacle(obstaclePosition, 1);
			break;
		}
		case 'B':
		{
			std::cout << "Large Barrier" << std::endl;
			Barrier obstacle(obstaclePosition, 3);
			break;
		}
		case 'r':
		{
			std::cout << "Simple Rock" << std::endl;
			Rock obstacle(obstaclePosition, 1);
			break;
		}
		case 'R':
		{
			std::cout << "Large Rock" << std::endl;
			Rock obstacle(obstaclePosition, 3);
			break;
		}
		default:
			THROW_EXCEPTION("FILE_READING_ERROR : Parser --> Invalid character for Obstacle describing");
		break;
	}

	switch (key[0])
	{
		case 'I':
		{
			std::cout << "CorridorSection" << std::endl;
			CorridorSection section(model, obstacle);
			return section;
			break;
		}
		case 'J':
		{
			std::cout << "Left CornerSection" << std::endl;
			CornerSection section(model, -1);
			return section;
			break;
		}
		case 'L':
		{
			std::cout << "Right CornerSection" << std::endl;
			CornerSection section(model, 1);
			return section;
			break;
		}
		case 'T':
		{
			std::cout << "TSection" << std::endl;
			TSection section(model);
			return section;
			break;
		}	
		default:
			THROW_EXCEPTION("FILE_READING_ERROR : Parser --> Invalid character for Section describing");
		break;
	}
	std::cout << std::endl;
}