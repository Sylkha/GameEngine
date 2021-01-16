#pragma once

#include "Task.h"
#include <Render_Node.hpp>

// Encargado de dibujar la escena
namespace gameEngine {
	class Render_System : Task {
		glt::Render_Node renderer; //Lo que nos va a permitir dibujar un conjunto de mallas
		Scene* scene;

	public:
		Render_System(Scene&);

		bool consumable() const override {
			return false;
		}
		void run(float time) override {
			scene->get_window()->clear();
			// actualizar el transform de todos los modelos, según el transform de las entidades(coger el del transform de la entidad del modelo).
			renderer.render();
			scene->get_window()->swap_buffers();
		}
		void initialize() override {

		}
		void finalize() override {

		}
	};
}
