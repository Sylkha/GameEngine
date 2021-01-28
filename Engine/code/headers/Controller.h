// Code released into the public domain
// in January 2021
// by Silvia

#pragma once

#include "Entity.h"
namespace gameEngine {
	/** Clase padre en la cual se ejecutar�n las acciones del controlador */
	class Controller {
	public:
		/** Aqu� se llevar� a cabo todo el comportamiento del Controlador */
		virtual void update(Entity& entity, float deltatime) = 0 {}

		virtual ~Controller() = 0 {}
	};
}