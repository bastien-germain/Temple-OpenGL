#include "moteurJeu/Game.hpp"
#include <typeinfo>

int main(int argc, char const *argv[])
{	
	std::cout << std::endl;
	Game game;
	game.gameManager().loadSections();

	std::cout << game.gameManager().sectionMat().size() << std::endl;

	std::cout << "0 ---  "<<  game.gameManager().sectionMat()[0].size() << std::endl;
	std::cout <<"1 ---  "<<  game.gameManager().sectionMat()[1].size() << std::endl;
	std::cout <<"2 ---  "<<  game.gameManager().sectionMat()[2].size() << std::endl;

	for (unsigned int i = 0; i < game.gameManager().sectionMat().size(); ++i)
	{
		std::cout << "++++++++" << std::endl;
		std::cout << game.gameManager().sectionMat()[1].size() << std::endl;
		
		for(unsigned int j = 0; j < game.gameManager().sectionMat()[i].size(); ++j)
		{
			std::cout << "*********" << std::endl;
			if(typeid(game.gameManager().sectionMat()[i][j]) == typeid(CorridorSection))
			{	
				std::cout << "CorridorSection in main" << std::endl;
				game.gameManager().sectionMat()[i][j].obstacle().progress(1.2);
			}
		}
	}


	return 0;
}