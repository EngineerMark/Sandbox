#include "Simulation.h"

Simulation::Simulation(UIScreenContainer* simulation_container)
{
	this->simulation_container = simulation_container;
}

void Simulation::Update(olc::PixelGameEngine* engine, float fElapsedTime)
{
	olc::vi2d mouse_pos = engine->GetMousePos();
	olc::vi2d screen_pos_start = simulation_container->GetScreenPosition();
	olc::vi2d screen_pos_end = simulation_container->GetScreenPosition() + simulation_container->size;
	if ((mouse_pos.x > screen_pos_start.x) &&
		(mouse_pos.y > screen_pos_start.y) &&
		(mouse_pos.x < screen_pos_end.x) &&
		(mouse_pos.y < screen_pos_end.y)) {
		//engine->FillRect(screen_pos_start, simulation_container->size, olc::GREEN);
		if (engine->GetMouse(0).bHeld) {
			InsertParticle(mouse_pos, new SimulationElement());
		}
	}

	if (existing_particles.size() > 0) {
		for (auto current_particle : existing_particles) {
			current_particle->position.y += 0.1;
		}

		switch (border) {
		case SimulationBorder::Solid:
			for (auto p : existing_particles) {
				if (p->GetPosition().x < screen_pos_start.x - 1)
					p->position.x = screen_pos_start.x - 1;
				if (p->GetPosition().y < screen_pos_start.y - 1)
					p->position.y = screen_pos_start.y - 1;
				if (p->GetPosition().x > screen_pos_end.x - 1)
					p->position.x = screen_pos_end.x - 1;
				if (p->GetPosition().y > screen_pos_end.y - 1)
					p->position.y = screen_pos_end.y - 1;
			}
			break;
		case SimulationBorder::Void:
			for (auto p : existing_particles) {
				if (IsParticleOutOfBounds(p))
					p->marked_for_deletion = TRUE;
			}
			break;
		case SimulationBorder::Wrap:
			for (auto p : existing_particles) {
				if (p->GetPosition().x < screen_pos_start.x - 1)
					p->position.x = screen_pos_end.x - 1;
				if (p->GetPosition().y < screen_pos_start.y - 1)
					p->position.y = screen_pos_end.y - 1;
				if (p->GetPosition().x > screen_pos_end.x - 1)
					p->position.x = screen_pos_start.x;
				if (p->GetPosition().y > screen_pos_end.y - 1)
					p->position.y = screen_pos_start.y;
			}
			break;
		}

		existing_particles.erase(std::remove_if(
			existing_particles.begin(), existing_particles.end(),
			[](const SimulationElement* x) {
				if (x->marked_for_deletion) {
					delete x;
					return true;
				}
				return false;
			}
		), existing_particles.end());

		for (auto p : existing_particles) {
			engine->Draw(p->GetPosition(), p->color);
		}
	}
}

void Simulation::InsertParticle(olc::vi2d position, SimulationElement* particle)
{
	for (auto p : existing_particles)
		if (p->GetPosition() == position)
			return;

	existing_particles.push_back(particle);
	particle->position = position;
}

bool Simulation::IsParticleOutOfBounds(SimulationElement* particle)
{
	return (particle->GetPosition().x < 0 || particle->GetPosition().y < 0 || particle->GetPosition().x > simulation_container->size.x || particle->GetPosition().y > simulation_container->size.y);
}
