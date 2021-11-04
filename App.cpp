#include "App.h"

App::App()
{
	sAppName = "Sandbox";
}

bool App::OnUserCreate()
{
	windowContainer = new UIScreenContainer({ 0,0 }, { ScreenWidth(), ScreenHeight() });
	windowContainer->draw_border = FALSE;
	windowContainer->draw_background = FALSE;

	sandboxContainer = new UIScreenContainer({ 2, 10 }, { ScreenWidth() - 40, ScreenHeight() - 2 - 10 }, windowContainer);

	pixelPickerContainer = new UIScreenContainer({ ScreenWidth() - 40 + 6, 2 }, { 32, ScreenHeight() - 4 }, windowContainer);
	pixelPickerContainer->background_color = olc::DARK_GREY;

	//test
	UIButton* test_button = new UIButton({ 0,0 }, { pixelPickerContainer->size.x / 2,20 }, pixelPickerContainer);
	test_button->btn_container->background_color = olc::GREEN;

	simulator = new Simulation(sandboxContainer);

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

	std::string debug_str = IsDebugMode() ? "(DEBUG) " : "";
	DrawString({ 1,1 }, debug_str + "Sandbox | " + GetMousePos().str() + " | " + std::to_string(simulator->existing_particles.size()) + " particles", olc::WHITE);

	if (windowContainer != NULL)
		windowContainer->Update(this, fElapsedTime);

	simulator->Update(this, fElapsedTime);

	return true;
}
