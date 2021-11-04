#pragma once

#include "SimulationElement.h"
#include "UIScreenContainer.h"
#include <vector>


class Simulation
{
public:
	enum SimulationBorder {
		Solid,
		Void,
		Wrap
	};

	std::vector<SimulationElement*> existing_particles;
	UIScreenContainer* simulation_container;

	SimulationBorder border = SimulationBorder::Void;

	Simulation(UIScreenContainer* simulation_container);
	void Update(olc::PixelGameEngine* engine, float fElapsedTime);

	void InsertParticle(olc::vi2d position, SimulationElement* particle);
	bool IsParticleOutOfBounds(SimulationElement* particle);
};

