#pragma once

#include "Component.h"
#include "Controller.h"

using namespace std;
namespace gameEngine {
	class Controller_Component : public Component {
		shared_ptr<Controller> controller;

	public:
		void set_Controller(shared_ptr<Controller> con) { controller = con; }
		Controller& get_Controller() { return *controller; }
	};
}