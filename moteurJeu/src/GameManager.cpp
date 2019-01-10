#include "moteurJeu/GameManager.hpp"

GameManager::GameManager(const Program &program, const float &trackballSmoothness) 
	: _enemy(), _parser(), 
	_factory(), _drawer(program),
	_eventManager(), _player(),
	_fly(trackballSmoothness),
	_trackball(trackballSmoothness), _worldGenerator()

{
	_player.model(_factory.playerModel());	
	_skybox.model(_factory.skyboxModel());	
	_enemy.model(_factory.enemyModel());

	_drawer.initializeLights(program);
}

GameManager::~GameManager() 
{
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