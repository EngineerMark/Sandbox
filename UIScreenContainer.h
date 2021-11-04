#pragma once

#include "olcPGE.h"
#include "UIElement.h"

class UIScreenContainer : public UIElement
{
public:
	olc::Pixel background_color = olc::BLACK;

	bool draw_border = TRUE;
	bool draw_background = TRUE;

	UIScreenContainer(olc::vi2d position, olc::vi2d size);
	UIScreenContainer(olc::vi2d position, olc::vi2d size, UIElement* parent);


	void Update(olc::PixelGameEngine* engine, float fElapsedTime) override;

	void Destroy() override;
};

