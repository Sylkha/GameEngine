// Drafted by Silvia in January 2021.
// Free use

#pragma once
#include "Window.hpp"
#include "Kernel.h"
#include "Render_System.h"

namespace gameEngine {
	class Scene {
		Window& window;
		Kernel kernel;
		Render_System render_system;

	public:
		Scene(Window& w) : window(w), render_system(*this) {
			run();
		}

	public:
		Window* get_window() { // Pasamos la referencia de la ventana
			return &window;
		}
		void run() {
			kernel.run();
		}
		void stop() {
			kernel.stop();
		}
	};
}