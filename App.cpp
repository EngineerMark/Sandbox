#include "App.h"

App::App()
{
	sAppName = "Sandbox";
}

bool App::OnUserCreate()
{
	windowContainer = new ScreenContainer({0,0}, {ScreenWidth(), ScreenHeight()});
	windowContainer->draw_border = FALSE;
	windowContainer->draw_background = FALSE;

	sandboxContainer = new ScreenContainer({ 2, 10 }, { ScreenWidth() - 40, ScreenHeight() - 4 - 10 }, windowContainer);

	pixelPickerContainer = new ScreenContainer({ ScreenWidth() - 40 + 6, 2 }, { 32, ScreenHeight() - 4 }, windowContainer);
	pixelPickerContainer->background_color = olc::DARK_GREY;

	return true;
}

bool App::OnUserDestroy() {
	//performs the delete on all child objects for you
	windowContainer->Destroy();

	delete windowContainer;

	return true;
}

bool App::OnUserUpdate(float fElapsedTime)
{
	FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::BLACK);
	DrawString({1,1}, "Sandbox", olc::WHITE);

	if(windowContainer!=NULL)
		windowContainer->Update(this, fElapsedTime);

	return true;
}
