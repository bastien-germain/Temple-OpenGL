#include <moteurJeu/CameraManager.hpp>
#include <iostream>

int main (int argc, char **argv)
{
	CameraManager cam;

	std::cout << cam.isTrackCurrent() << std::endl;

	std::cout << "track" << std::endl;

	std::cout << cam.getViewMatrix() << std::endl;

	cam.moveCam(0, 5);
	cam.moveCam(1, 10);
	cam.moveCam(2, 15);

	std::cout << cam.getViewMatrix() << std::endl;

	cam.switchCam();

	std::cout << "vision" << std::endl;

	cam.moveCam(0, 5);
	cam.moveCam(1, 10);
	cam.moveCam(2, 15);

	std::cout << cam.isTrackCurrent() << std::endl;

	std::cout << cam.isCamLocked() << std::endl;

	cam.lockCam();

	cam.moveCam(0, 5);
	cam.moveCam(1, 10);
	cam.moveCam(2, 15);

	std::cout << cam.isCamLocked() << std::endl;

	return 0;
}
