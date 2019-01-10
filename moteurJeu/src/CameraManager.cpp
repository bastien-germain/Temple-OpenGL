#include "moteurJeu/CameraManager.hpp"
#include <iostream>

CameraManager::CameraManager() : _fly(FreeflyCamera()), _track(TrackballCamera()), _vision(VisionCamera()), _isTrackCurrent(true), _isCamLocked(false)
{
}

CameraManager::~CameraManager() 
{
}

void CameraManager::switchCam() 
{
	_isTrackCurrent = !_isTrackCurrent;
	
}

void CameraManager::lockCam()
{
	_isCamLocked = !_isCamLocked;
}

void CameraManager::moveCam(const unsigned int action, const float value)
{
	if(!_isCamLocked)
	{	
		std::cout << "cam pas lock" << std::endl;
		if(_isTrackCurrent)
		{
			switch(action)
			{
				case 0 : 
				{
					_track.moveFront(value);
					break;
				}
				case 1 :
				{
					_track.rotateLeft(value);
					break;
				}
				case 2 :
				{
					_track.rotateUp(value);
					break;
				}
			}
				
		}
		else
		{

			switch(action)
			{
				case 0 : 
				{
					break;
				}
				case 1 :
				{
					_fly.rotateLeft(value);
					break;
				}
				case 2 :
				{
					_fly.rotateUp(value);
					break;
				}
			}
			// Only y rotation on vision cam
			// if(action == 1)
			// {
			// 	_vision.rotateLeft(value);
			// }
		}
	}
}

glm::mat4 CameraManager::getViewMatrix() const
{
	if(_isTrackCurrent)
		return _track.getViewMatrix();
	else
		return _fly.getViewMatrix();
}



