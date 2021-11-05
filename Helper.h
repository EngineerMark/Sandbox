#pragma once

#include "olcPGE.h"

static bool IsOutOfBounds(olc::vi2d point, olc::vi2d start, olc::vi2d end) {
	return (
		point.x<start.x &&
		point.y<start.y &&
		point.x>end.x &&
		point.y>end.y
	);
}
