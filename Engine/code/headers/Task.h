#pragma once

#include "Scene.h"

namespace gameEngine {
	class Task {

		int priority; /** número más pequeño, + prioridad. */
		Scene * scene;
		float time;
	public:
		virtual bool consumable () const = 0; /** indicamos al Kernel si nos tiene que ejecutar una vez o hasta que termine el programa. Devuelve true o false */
		virtual void run(float time) = 0;		 /** método virtual puro, por lo que haremos tareas especificas que hereden de Task. */
		virtual void initialize() = 0;
		virtual void finalize() = 0;
		bool operator <(const Task& x)const {		/** Sobrecargamos el operador */
			return this-> priority > x.priority;
		}  
	};
}