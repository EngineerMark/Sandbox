#pragma once

#include "olcPGE.h"
#include "UIElement.h"

class ScreenContainer : public UIElement
{
public:
	ScreenContainer(olc::vi2d position, olc::vi2d size);
	ScreenContainer(olc::vi2d position, olc::vi2d size, UIElement* parent);

	olc::Pixel background_color = olc::BLACK;

	void Update(olc::PixelGameEngine* engine, float fElapsedTime) override;

	void Destroy() override;
};

