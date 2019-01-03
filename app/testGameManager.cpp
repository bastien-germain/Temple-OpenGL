#include "moteurJeu/GameManager.hpp"
#include <typeinfo>

int main(int argc, char const *argv[])
{	
	/*
	std::cout << std::endl;
	GameManager gameManager;
	gameManager.loadSections();

	std::cout << "SectionMat size : " <<  gameManager.sectionMat().size() << std::endl;

	std::cout << "0 ---  " <<  gameManager.sectionMat()[0].size() << std::endl;
	std::cout << "1 ---  " <<  gameManager.sectionMat()[1].size() << std::endl;
	std::cout << "2 ---  " <<  gameManager.sectionMat()[2].size() << std::endl;


	for (unsigned int i = 0; i < gameManager.sectionMat().size(); ++i)
	{
		std::cout << "++++++++" << std::endl;
		std::cout << gameManager.sectionMat()[1].size() << std::endl;
		
		for(unsigned int j = 0; j < gameManager.sectionMat()[i].size(); ++j)
		{
			std::cout << "*********" << std::endl;
			if(gameManager.sectionMat()[i][j].isCorridor())
			{	
				std::cout << "CorridorSection in main" << std::endl;
				std::cout << "Obstacle observers size : " << gameManager.sectionMat()[i][j].obstacle().observers().size()<< std::endl;
				std::cout << "Obstacle observable size : " << gameManager.observables().size()<< std::endl << std::endl;
				gameManager.sectionMat()[i][j].obstacle().progress(i*j*1.2);
			}
		}
	}

*/
	return 0;
}