#include "App.h"

App::App()
{
	sAppName = "Sandbox";
}

bool App::OnUserCreate()
{
	sandboxContainer = new ScreenContainer({ 2, 2 }, { ScreenWidth() - 40, ScreenHeight() - 4 });
	pixelPickerContainer = new ScreenContainer({ ScreenWidth() - 40 + 6, 2 }, { 32, ScreenHeight() - 4 });
	pixelPickerContainer->background_color = olc::DARK_GREY;

	return true;
}

bool App::OnUserDestroy() {
	delete sandboxContainer;
	delete pixelPickerContainer;

	return true;
}

bool App::OnUserUpdate(float fElapsedTime)
{
	FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::BLACK);

	sandboxContainer->Update(this, fElapsedTime);
	pixelPickerContainer->Update(this, fElapsedTime);

	return true;
}
