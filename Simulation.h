#pragma once

#include "SimulationElement.h"
#include "UIScreenContainer.h"
#include "Helper.h"

#include <vector>


class Simulation
{
public:
	enum SimulationBorder {
		Solid,
		Void,
		Wrap
	};

	//const SimulationElement* element_air = new SimulationElement(FALSE);

	SimulationElement* GetParticlePrefab() {
		return new SimulationElement();
	}

	//std::vector<SimulationElement*> existing_particles;
	//SimulationElement** existing_particles;
	std::vector<std::vector<SimulationElement*>> existing_particles;
	UIScreenContainer* simulation_container;

	SimulationBorder border = SimulationBorder::Void;

	Simulation(UIScreenContainer* simulation_container);
	void Update(olc::PixelGameEngine* engine, float fElapsedTime);
	void Stop();

	void InsertParticle(olc::vi2d position, SimulationElement* particle);
	bool IsParticleOutOfBounds(SimulationElement* particle);

	int GetParticleCount() {
		int i = 0;
		for (size_t x = 0; x < existing_particles.size(); x++)
			for (size_t y = 0; y < existing_particles[x].size(); y++)
				if(existing_particles[x][y]->draw_element)
					i++;
		return i;
	}
};

