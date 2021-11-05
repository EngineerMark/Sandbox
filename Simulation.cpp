#include "Simulation.h"

Simulation::Simulation(UIScreenContainer* simulation_container)
{
	this->simulation_container = simulation_container;

	int x = this->simulation_container->size.x;
	int y = this->simulation_container->size.y;

	for (size_t i = 0; i < x; i++)
	{
		std::vector<SimulationElement*> v;
		for (size_t j = 0; j < y; j++)
		{
			//SimulationElement* p = new SimulationElement();
			SimulationElement* p = GetParticlePrefab();
			p->draw_element = false;
			v.push_back(p);
		}
		existing_particles.push_back(v);
	}

	//*existing_particles[20][20] = new SimulationElement();
	existing_particles[20][20]->color = olc::GREEN;
}

void Simulation::Stop() {
	int size_x = existing_particles.size();
	int size_y = existing_particles[0].size();

	for (size_t x = 0; x < size_x; x++)
	{
		for (size_t y = 0; y < size_y; y++)
		{
			delete existing_particles[x][y];
			existing_particles[x][y] = NULL;
		}
	}

	existing_particles.erase(existing_particles.begin(), existing_particles.end());
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
			SimulationElement* p = GetParticlePrefab();
			p->draw_element = true;
			p->color = olc::RED;
			InsertParticle(mouse_pos - screen_pos_start, p);
		}
	}

	if (existing_particles.size() > 0) {
		for (size_t i = 0; i < existing_particles.size(); i++)
		{
			for (size_t j = 0; j < existing_particles[i].size(); j++)
			{
				SimulationElement* p = existing_particles[i][existing_particles[i].size() - j - 1];
			}
		}

		/*for (auto current_particle : existing_particles) {
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
		}*/

		/*existing_particles.erase(std::remove_if(
			existing_particles.begin(), existing_particles.end(),
			[](const SimulationElement* x) {
				if (x->marked_for_deletion) {
					delete x;
					return true;
				}
				return false;
			}
		), existing_particles.end());*/


		/*for (auto p : existing_particles) {
			engine->Draw(p->GetPosition(), p->color);
		}*/
		for (size_t x = 0; x < existing_particles.size(); x++)
		{
			for (size_t y = 0; y < existing_particles[0].size(); y++)
			{
				olc::vi2d pos = { (int)x, (int)y };
				SimulationElement* p = existing_particles[x][y];
				if (p->draw_element)
					engine->Draw(screen_pos_start + pos, p->color);
			}
		}
	}
}

void Simulation::InsertParticle(olc::vi2d position, SimulationElement* particle)
{
	/*for (auto p : existing_particles)
		if (p->GetPosition() == position)
			return;*/
			/*if (existing_particles[position.x][position.y] != element_air)
				return;*/

				//existing_particles.push_back(particle);
	existing_particles[position.x][position.y] = particle;
}

//bool Simulation::IsParticleOutOfBounds(SimulationElement* particle)
//{
//	return IsOutOfBounds(particle->GetPosition(), { 0,0 }, simulation_container->size);
//	//return (particle->GetPosition().x < 0 || particle->GetPosition().y < 0 || particle->GetPosition().x > simulation_container->size.x || particle->GetPosition().y > simulation_container->size.y);
//}
