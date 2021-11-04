#pragma once

#include "System.h"

#define OLC_PGE_APPLICATION
#include "olcPGE.h"

#include "Simulation.h"
#include "UIScreenContainer.h"
#include "UIButton.h"

class App : public olc::PixelGameEngine
{
public:
	const int S_WIDTH = 800;
	const int S_HEIGHT = 600;
	const int S_PIXELSIZE = 2;

	App();
private:
	UIScreenContainer* windowContainer; //our full window
	UIScreenContainer* sandboxContainer; //contains the pixels/simulator
	UIScreenContainer* pixelPickerContainer; //contains list of simulation pixels

	Simulation* simulator;

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
