#pragma once

#include "olcPGE.h"

class SimulationElement
{
public:
	olc::vf2d position;
	olc::vf2d acceleration;
	olc::vf2d velocity;
	olc::Pixel color = olc::RED;

	olc::vi2d GetPosition() {
		return {(int)position.x, (int)position.y};
	};

	bool marked_for_deletion = FALSE;
};

