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
	unsigned int offsetPosZCount = 0, lastRotateIndex = 0;
	int rotateIndicator;
	bool lastCornerRight = false;
	bool penultimateCornerRight = false;
	bool noCorner = true;

	std::cout << "fillSectionVec" << std::endl;
	
	while (offsetPosZCount < sectionDataStrings.size() && noCorner)
	{
		_sectionVec.push_back(_factory.create(sectionDataStrings[offsetPosZCount], this));
		
		_sectionVec[offsetPosZCount].goOnZ(_sectionVec[lastRotateIndex].posX() + offsetPosZCount * POSITION_OFFSET_Z);
		_sectionVec[offsetPosZCount].goOnX(_sectionVec[lastRotateIndex].posZ());

		if (_sectionVec[offsetPosZCount].isCorner())
		{	
			rotateIndicator = _sectionVec[offsetPosZCount].cornerDirection();

			if (rotateIndicator == 1)
				lastCornerRight = penultimateCornerRight = true;
			
			noCorner = false;
		}
		offsetPosZCount++;
	}

	lastRotateIndex = offsetPosZCount - 1 ;
	offsetPosZCount = 0;
	
	for (int i = lastRotateIndex + 1; i < sectionDataStrings.size(); ++i)
	{	
		_sectionVec.push_back(_factory.create(sectionDataStrings[i], this));

		std::cout << "rotateIndicator : " << rotateIndicator << " || lastCornerRight : " << lastCornerRight << " || penultimateCornerRight : " << penultimateCornerRight << std::endl;
		if (rotateIndicator == 0) 
		{

			if (penultimateCornerRight && !lastCornerRight)
			{
				_sectionVec[i].goOnZ(_sectionVec[lastRotateIndex].posX() + offsetPosZCount * POSITION_OFFSET_Z);
				_sectionVec[i].goOnX(-_sectionVec[lastRotateIndex].posZ());
			}
			if (penultimateCornerRight && lastCornerRight)
			{
				_sectionVec[i].goOnZ(_sectionVec[lastRotateIndex].posX() + offsetPosZCount * POSITION_OFFSET_Z);
				_sectionVec[i].goOnX(_sectionVec[lastRotateIndex].posZ());
			}
		}

		else
		{
			if (rotateIndicator > 0)
			{
				if (penultimateCornerRight && !lastCornerRight)
				{
					_sectionVec[i].goOnZ(- _sectionVec[lastRotateIndex].posX() + (offsetPosZCount + 1) * POSITION_OFFSET_Z + CORNER_OFFSET_Z);
					_sectionVec[i].goOnX(-_sectionVec[lastRotateIndex].posZ() + CORNER_OFFSET_Z);
				}
				if (penultimateCornerRight && lastCornerRight)
				{
					_sectionVec[i].goOnZ(- _sectionVec[lastRotateIndex].posX() + (offsetPosZCount + 1) * POSITION_OFFSET_Z + CORNER_OFFSET_Z);
					_sectionVec[i].goOnX(_sectionVec[lastRotateIndex].posZ() - CORNER_OFFSET_Z);
				}
			}
			else
			{	
				if (penultimateCornerRight)
				{	
					_sectionVec[i].goOnZ(_sectionVec[lastRotateIndex].posX() - (offsetPosZCount + 1) * POSITION_OFFSET_Z - CORNER_OFFSET_Z);
					_sectionVec[i].goOnX(-_sectionVec[lastRotateIndex].posZ() - CORNER_OFFSET_Z);
				}
				else 
				{
					_sectionVec[i].goOnZ(_sectionVec[lastRotateIndex].posX() - (offsetPosZCount + 1) * POSITION_OFFSET_Z - CORNER_OFFSET_Z);
					_sectionVec[i].goOnX(_sectionVec[lastRotateIndex].posZ() + CORNER_OFFSET_Z);
				}
			}
		}

		if (!_sectionVec[i].isCorner()) 
			offsetPosZCount++;
		else 
		{	
			lastRotateIndex = i;
			offsetPosZCount = 0;
			penultimateCornerRight = lastCornerRight;

			if (_sectionVec[i].cornerDirection() == 1)
				lastCornerRight = true;
			else 
				lastCornerRight = false;

			rotateIndicator = (rotateIndicator + _sectionVec[i].cornerDirection()) %4;
        }

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