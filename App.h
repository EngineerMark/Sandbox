#pragma once

#define OLC_PGE_APPLICATION
#include "olcPGE.h"

#include "ScreenContainer.h"

class App : public olc::PixelGameEngine
{
public:
	const int S_WIDTH = 1600;
	const int S_HEIGHT = 900;
	const int S_PIXELSIZE = 4;

	App();
private:
	ScreenContainer* sandboxContainer; //contains the pixels/simulator
	ScreenContainer* pixelPickerContainer; //contains list of simulation pixels

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;
	bool OnUserDestroy() override;
};

int main() {
	App a;
	if(a.Construct(a.S_WIDTH / a.S_PIXELSIZE, a.S_HEIGHT / a.S_PIXELSIZE, a.S_PIXELSIZE, a.S_PIXELSIZE))
		a.Start();
	return 0;
}
