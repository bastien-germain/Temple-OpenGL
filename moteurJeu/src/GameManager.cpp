#include "moteurJeu/GameManager.hpp"

GameManager::GameManager() : _player(Player()), _enemy(Enemy()), _parser(Parser()) 
{
	for (unsigned int i = 0; i < 3; i++)
	{	
		std::vector<Section> temp;
		_sectionMat.push_back(temp);
	}
}

GameManager::~GameManager() 
{

}

/*
void GameManager::fillSectionVec(const Section &newSec)
{	
	
	_sectionVec.push_back(newSec);
}
*/

void GameManager::fillSectionVec(std::vector<std::string> &sectionDataStrings)
{	
	std::cout << "SECTION_VEC FILLING STARTS..." << std::endl;

	std::vector<std::string>::iterator it;
	
	for (it = sectionDataStrings.begin(); it != sectionDataStrings.end(); it++)
	{
		_sectionVec.push_back(_factory.create(*it, this));
	}
	std::cout << "SECTION_VEC FILLING ENDS" << std::endl;
}

void GameManager::fillSectionMat()
{	
	std::cout << "SECTION_MAT FILLING STARTS..." << std::endl;

	std::cout << "\n\n\n SectionVec size " <<_sectionVec.size() << "\n\n\n" << std::endl;
	
	for (unsigned int i = 0; i < _sectionVec.size(); i++) 
	{
		_sectionMat[0].push_back(_sectionVec[i]);
		std::cout << "\n\n\n SectionMat 0 size " <<_sectionMat[0].size() << "\n\n\n" << std::endl;

		if (_sectionVec[i].isT())
		{	
			std::cout << "TSECTION ADDED" << std::endl;
			// TESTER S'IL RESTE AU MOINS 6 SECTIONS !

			// On passe les 3 d'après à la deuxième ligne (côté gauche)
			for (unsigned int j = i + 1; j < i + 4; j++)
			{
				_sectionMat[1].push_back(_sectionVec[j]);
			}

			i+=3;

			// On passe les 3 encore d'après à la troisième ligne (côté droit)
			for (unsigned int j = i + 1; j < i + 4; j++)
			{
				_sectionMat[2].push_back(_sectionVec[j]);
			}

			i+=3;

			std::cout << "\n\n\n SectionMat 1 size " <<_sectionMat[1].size() << "\n\n\n" << std::endl;
			std::cout << "\n\n\n SectionMat 2 size " <<_sectionMat[2].size() << "\n\n\n" << std::endl;
		}
	}	
	std::cout << "SECTION_MAT FILLING ENDS" << std::endl;
}

void GameManager::updateSectionMat(const bool isLeft)
{
	if (isLeft) 
		_sectionMat[0] = _sectionMat[1]; // left
	else 
		_sectionMat[0] = _sectionMat[2]; // right

	_sectionMat[1].clear();
	_sectionMat[2].clear();
}

void GameManager::loadSections() 
{
	std::vector<std::string> sectionDataStrings = _parser.parse(_sectionsDataFilePath);
	
	fillSectionVec(sectionDataStrings);
	fillSectionMat();
	std::cout << "\n\n\n SectionMat 1 size " <<_sectionMat[1].size() << "\n\n\n" << std::endl;
	std::cout << "\n\n\n SectionMat 2 size " <<_sectionMat[2].size() << "\n\n\n" << std::endl;
}

void GameManager::observerUpdate(const PositionObservable *observable) const {
	
	std::cout << "observable position : " << observable->posZ() << std::endl;

	if (observable->posZ() == _player.posZ()) {
	}
}