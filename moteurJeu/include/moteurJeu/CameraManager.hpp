#pragma once
#ifndef __CAMERA_MANAGER_HPP__
#define __CAMERA_MANAGER_HPP__

#include "moteurRendu/TrackballCamera.hpp"
#include "moteurRendu/VisionCamera.hpp"

class CameraManager
{

private:
	TrackballCamera _track;
	VisionCamera _vision;
	bool _isTrackCurrent; // Keep track of the current used cam
	bool _isCamLocked;

public:

	CameraManager();
	~CameraManager();

	inline bool isTrackCurrent() const
	{
		return _isTrackCurrent;
	}

	inline bool isCamLocked() const
	{
		return _isCamLocked;
	}

	/// \brief When "C" is pressed, switch the view between both cam
	void switchCam();

	/// \brief When "L" is pressed, lock the cam (disable move and zoom)
	void lockCam();

	/// \param action :  0 -> z translate; 1 -> y rotate, -> : x rotate
	/// \param value : delta if translate, degree if rotate
	void moveCam(const unsigned int action, const float value);

    glm::mat4 getViewMatrix() const;

};

#endif