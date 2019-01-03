#include "moteurJeu/GameManager.hpp"

GameManager::GameManager(const Program &program ,const float &sectionInitialPosZ, const float &trackballSmoothness) 
	: _enemy(Enemy()), _parser(Parser()), _game(Game()), 
	_factory(sectionInitialPosZ), _drawer(Drawer(program)),
	_eventManager(EventManager()), _player(Player()),
	_trackball(TrackballCamera(trackballSmoothness))

{
	std::cout << "GM const" << std::endl;
	_player.model(_factory.playerModel());

	for (unsigned int i = 0; i < 3; i++)
 	{	
	 	std::vector<Section*> temp;
	 	_sectionMat.push_back(temp);
	}
}

GameManager::~GameManager() 
{

}

void GameManager::fillSectionVec(std::vector<std::string> &sectionDataStrings)
{	
	std::cout << "SECTION_VEC FILLING STARTS..." << std::endl;

	std::vector<std::string>::iterator it;
	
	for (int i = 0; i < sectionDataStrings.size(); ++i)
	{	
		_sectionVec.push_back(_factory.create(sectionDataStrings[i], this));
		
		if (_sectionVec[i].isCorridor()) 
		{
			std::cout << "FillSection observers size :  " << _sectionVec[i].obstacle().observers().size() << std::endl;	
			std::cout << "FillSection observables size :  " << _observables.size() << std::endl;	
		}
	}

	std::cout << "SECTION_VEC FILLING ENDS" << std::endl;
}

void GameManager::fillSectionMat()
{	
	std::cout << "SECTION_MAT FILLING STARTS..." << std::endl;

	std::cout << "\n SectionVec size " <<_sectionVec.size() << "\n" << std::endl;
	
	for (unsigned int i = 0; i < _sectionVec.size(); i++) 
	{
		_sectionMat[0].push_back(&_sectionVec[i]);
		std::cout << "\n SectionMat 0 size " <<_sectionMat[0].size() << "\n" << std::endl;

		if (_sectionVec[i].isT())
		{	
			std::cout << "TSECTION ADDED" << std::endl;

			// TESTER S'IL RESTE AU MOINS 6 SECTIONS !

			// On passe les 3 d'après à la deuxième ligne (côté gauche)
			for (unsigned int j = i + 1; j < i + 4; j++)
				_sectionMat[1].push_back(&_sectionVec[j]);

			i+=3;

			// On passe les 3 encore d'après à la troisième ligne (côté droit)
			for (unsigned int j = i + 1; j < i + 4; j++)
				_sectionMat[2].push_back(&_sectionVec[j]);

			i+=3;

			std::cout << "\n SectionMat 0 size " <<_sectionMat[0].size() << "\n" << std::endl;
			std::cout << "\n SectionMat 1 size " <<_sectionMat[1].size() << "\n" << std::endl;
			std::cout << "\n SectionMat 2 size " <<_sectionMat[2].size() << "\n" << std::endl;
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
	std::cout << "\n SectionMat 0 size " <<_sectionMat[0].size() << "\n" << std::endl;
	std::cout << "\n SectionMat 1 size " <<_sectionMat[1].size() << "\n" << std::endl;
	std::cout << "\n SectionMat 2 size " <<_sectionMat[2].size() << "\n" << std::endl;	
}

void GameManager::observerUpdate(const PositionObservable *observable) const 
{
	
	std::cout << "*** OBSERVER UPDATE : SIZE : " << observable->posZ() << std::endl;

	if (observable->posZ() == _player.posZ()) 
	{
		std::cout << "*** OBSERVER UPDATE : OBSTACLE REACHED PLAYER POS_Z : " << std::endl;
	}
}

bool GameManager::isOver() const
{
	if(_enemy.distanceToPlayer() == 0)
		return true;
	else
		return false;
}