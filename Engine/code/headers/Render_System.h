// Code released into the public domain
// in January 2021
// by Silvia

#pragma once

#include "Task.h"
#include <memory>
#include <string>
#include <Model.hpp>
#include <Light.hpp>
#include <Camera.hpp>
#include "Render_Node.hpp"

using namespace std;
using namespace glt;

/** Encargado de dibujar la escena */
namespace gameEngine {
	class Scene;
	class Render_System : public Task {
		/** El renderer node es lo que nos va a permitir dibujar un conjunto de mallas. */
		unique_ptr< Render_Node > renderer; 	

	public:
		Render_System(Scene& scene, int priority);

		bool consumable() const override {
			return false;
		}

		void run(float time) override;
		void initialize() override;
		void finalize() override;

		Render_Node getRenderer() { return *renderer; }

		/** A�adimos componentes de tipo Model */
		void addObject(string ID, shared_ptr<Model>model);
		/** A�adimos componentes de tipo Camera */
		void addObject(string ID, shared_ptr<Camera>camera);
		/** A�adimos componentes de tipo Light */
		void addObject(string ID, shared_ptr<Light>light);
		/** Si tenemos m�s de una c�mara, elegimos c�al va a ser la que est� activa */
		void setActiveCamera(string ID);
		/** Para poner en invisible objetos */
		void removeObject(string ID);
	};
}
