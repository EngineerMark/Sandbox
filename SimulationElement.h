#pragma once

#include "olcPGE.h"

class SimulationElement
{
public:
	olc::Pixel color = olc::RED;

	bool draw_element = TRUE;

	/*olc::vi2d GetPosition() {
		return {(int)position.x, (int)position.y};
	};*/

	bool marked_for_deletion = FALSE;

	SimulationElement();
	SimulationElement(bool draw_element);
};

