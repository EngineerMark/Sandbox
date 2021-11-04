#include "UIScreenContainer.h"

UIScreenContainer::UIScreenContainer(olc::vi2d position, olc::vi2d size) : UIScreenContainer(position, size, NULL) {

}

UIScreenContainer::UIScreenContainer(olc::vi2d position, olc::vi2d size, UIElement* parent) : UIElement(position, size, parent) {

}

void UIScreenContainer::Destroy() {
	
}

void UIScreenContainer::Update(olc::PixelGameEngine* engine, float fElapsedTime)
{
	olc::vi2d draw_position = GetScreenPosition();

	if (draw_border) {
		engine->DrawLine(draw_position.x - 1, draw_position.y - 1, draw_position.x - 1 + size.x + 1, draw_position.y - 1, olc::WHITE);
		engine->DrawLine(draw_position.x - 1, draw_position.y - 1, draw_position.x - 1, draw_position.y - 1 + size.y + 1, olc::WHITE);
		engine->DrawLine(draw_position.x - 1, draw_position.y - 1 + size.y + 1, draw_position.x - 1 + size.x + 1, draw_position.y - 1 + size.y + 1, olc::WHITE);
		engine->DrawLine(draw_position.x - 1 + size.x + 1, draw_position.y - 1, draw_position.x - 1 + size.x + 1, draw_position.y - 1 + size.y + 1, olc::WHITE);
	}

	if(draw_background)
		engine->FillRect(draw_position, size, background_color);

	for(auto child : child_elements)
		child->Update(engine, fElapsedTime);
}
