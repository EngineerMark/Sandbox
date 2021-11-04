#pragma once

#include "UIElement.h"
#include "UIScreenContainer.h"

class UIButton : public UIElement
{
public:
	UIButton(olc::vi2d position, olc::vi2d size);
	UIButton(olc::vi2d position, olc::vi2d size, UIElement* parent);

	UIScreenContainer* btn_container;

	void Update(olc::PixelGameEngine* engine, float fElapsedTime) override;

	void Destroy() override;
};

