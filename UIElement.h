#pragma once

#include "olcPGE.h"

class UIElement {
public:
	olc::vi2d position;
	olc::vi2d size;
	std::vector<UIElement*> child_elements;
	UIElement* parent_element = NULL;

	olc::vi2d GetScreenPosition() {
		if(parent_element==NULL)
			return position;

		return parent_element->GetScreenPosition()+position;
	}

	UIElement(olc::vi2d position, olc::vi2d size) : UIElement(position, size, NULL) {
		/*this->position = position;
		this->size = size;

		if (parent != NULL)
			parent->child_elements.push_back(this);*/
	};

	UIElement(olc::vi2d position, olc::vi2d size, UIElement* parent) {
		this->position = position;
		this->size = size;

		if (parent != NULL)
			parent->child_elements.push_back(this);

		parent_element = parent;
	};

	virtual void Destroy() {
		for (size_t i = 0; i < child_elements.size(); i++) child_elements[i]->Destroy();
		for (auto child : child_elements) delete child;
	};

	virtual void Update(olc::PixelGameEngine* engine, float fElapsedTime) = 0;
};