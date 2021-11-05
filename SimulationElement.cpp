#include "SimulationElement.h"

SimulationElement::SimulationElement() : SimulationElement(true) {

}

SimulationElement::SimulationElement(bool draw_element) {
	this->draw_element = draw_element;
}