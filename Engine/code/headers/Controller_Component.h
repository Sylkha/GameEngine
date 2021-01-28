// Code released into the public domain
// in January 2021
// by Silvia

#pragma once

#include "Component.h"
#include "Controller.h"

using namespace std;
namespace gameEngine {
	/** Clase a través de la cual accedemos al controlador del entity asignado o accedemos a él */
	class Controller_Component : public Component {
		shared_ptr<Controller> controller;

	public:
		void set_Controller(shared_ptr<Controller> con) { controller = con; }
		Controller& get_Controller() { return *controller; }
	};
}