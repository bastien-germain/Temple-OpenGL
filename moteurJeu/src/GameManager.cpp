#include "moteurJeu/GameManager.hpp"

GameManager::GameManager(const Program &program, const float &trackballSmoothness) 
	: _enemy(), _parser(), _game(), 
	_factory(), _drawer(program),
	_eventManager(), _player(),
	_trackball(trackballSmoothness)

{
	_player.model(_factory.playerModel());	
	_skybox.model(_factory.skyboxModel());	
	_enemy.model(_factory.enemyModel());

	for (unsigned int i = 0; i < 3; i++)
 	{	
	 	std::vector<Section*> temp;
	 	_sectionMat.push_back(temp);
	}

	_drawer.initializeLights(program);
}

GameManager::~GameManager() 
{
}

void GameManager::fillSectionVec(std::vector<std::string> &sectionDataStrings)
{	
	std::vector<std::string>::iterator it;
	unsigned int offsetPosZCount = 0;
	
	for (int i = 0; i < sectionDataStrings.size(); ++i)
	{	
		_sectionVec.push_back(_factory.create(sectionDataStrings[i], this));
		_sectionVec[i].goOnZ(offsetPosZCount * POSITION_OFFSET_Z);
		
		if (!_sectionVec[i].isCorner()) 
			offsetPosZCount++;
		else 
			offsetPosZCount = 0;

	}

	if (_sectionVec[0].isCorner())
		THROW_EXCEPTION("ERROR : FIRST SECTION CANNOT BE CORNER");
}

void GameManager::fillSectionMat()
{	
	
	for (unsigned int i = 0; i < _sectionVec.size(); i++) 
	{
		_sectionMat[0].push_back(&_sectionVec[i]);

		if (_sectionVec[i].isT())
		{	
			// TESTER S'IL RESTE AU MOINS 6 SECTIONS !

			// On passe les 3 d'après à la deuxième ligne (côté gauche)
			for (unsigned int j = i + 1; j < i + 4; j++)
				_sectionMat[1].push_back(&_sectionVec[j]);

			i+=3;

			// On passe les 3 encore d'après à la troisième ligne (côté droit)
			for (unsigned int j = i + 1; j < i + 4; j++)
				_sectionMat[2].push_back(&_sectionVec[j]);

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
	
	fillSectionVec(sectionDataStrings);
	fillSectionMat();
}

void GameManager::observerUpdate(PositionObservable *observable)
{	
	if (!observable->hasCollided())
	{
		if ((int)observable->posZ() > _player.posZ() - 1 && (int)observable->posZ() < _player.posZ() + 1.5) 
		{	
			if (_player.posX() > (observable->posX() - observable->sizeX()) && _player.posX() < (observable->posX() + observable->sizeX()))
			{
				if(_player.posY() < observable->sizeY())
				{
					std::cout << "collision !" << std::endl;
					observable->collide();
					if (_enemy.distanceToPlayer() > 0)
						_enemy.bringCloser();
				}	
			}			
		}
	}
	
}

bool GameManager::isOver() const
{
	if(_enemy.distanceToPlayer() == 0)
		return true;
	else
		return false;
}