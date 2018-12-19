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
	std::vector<std::string>::iterator it;

	for (it = sectionDataStrings.begin(); it != sectionDataStrings.end(); ++it)
	{
		_sectionVec.push_back(_factory.create(*it, this));
	}
}

void GameManager::fillSectionMat()
{	
	for (unsigned int i = 0; i < _sectionVec.size(); i++) 
	{
		_sectionMat[0].push_back(_sectionVec[i]);

		if (_sectionVec[i].isT())
		{	
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
		}
	}	
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
	
	this->fillSectionVec(sectionDataStrings);
	this->fillSectionMat();
}

void GameManager::observerUpdate(const PositionObservable *observable) const {
	if (observable->posZ() == _player.posZ()) {
	}
}