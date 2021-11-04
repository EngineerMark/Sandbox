#include "UIButton.h"

UIButton::UIButton(olc::vi2d position, olc::vi2d size) : UIButton(position, size, NULL) {

}

UIButton::UIButton(olc::vi2d position, olc::vi2d size, UIElement* parent) : UIElement(position, size, parent) {
	btn_container = new UIScreenContainer({ 0,0 }, size, this);
}

void UIButton::Destroy() {

}

void UIButton::Update(olc::PixelGameEngine* engine, float fElapsedTime)
{
	olc::vi2d draw_position = GetScreenPosition();

	for (auto child : child_elements)
		child->Update(engine, fElapsedTime);
}
