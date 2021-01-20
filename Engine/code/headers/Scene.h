// Drafted by Silvia in January 2021.
// Free use

#pragma once
#include "Window.hpp"
#include "Kernel.h"
#include "Render_System.h"
#include "Entity.h"
#include "Camera_Component.h"
#include "Model_Component.h"
#include "Light_Component.h"

using namespace std;
namespace gameEngine {
	class Scene {
		Window& window;
		Kernel kernel;
		Render_System render_system;
		

		typedef map <string, shared_ptr<Entity>> entityList;
		entityList entities;

	public:
		Scene(Window& w) : window(w), render_system(*this, render_system.priority) { 
			kernel.add_task(render_system);

			run();
		}

	public:
		Window& get_window() { // Pasamos la referencia de la ventana
			return window;
		}
		entityList& getEntities() { return entities; }

		void run() {
			kernel.run();
		}
		void stop() {
			kernel.stop();
		}
	};
}