// Code released into the public domain
// in January 2021
// by Silvia

#pragma once

namespace gameEngine {
	class Scene; /** Declaración anticipada porque las task van en Scene */

	class Task {
	public:
		int priority; /** número más pequeño, + prioridad. */

		struct Task_Less_Compare
		{
			bool operator () (const Task* a, const Task* b) const
			{
				return *a < *b;       // Se usa el operador < sobrecargado en la clase Task
			}
		};

	protected:
		Scene & scene;

	public:
		Task(Scene& scene, int priority) : scene(scene), priority(priority){}
		virtual bool consumable () const = 0; /** indicamos al Kernel si nos tiene que ejecutar una vez o hasta que termine el programa. Devuelve true o false */
		virtual void run(float time) = 0;		 /** método virtual puro, por lo que haremos tareas especificas que hereden de Task. */
		virtual void initialize() = 0;
		virtual void finalize() = 0;
		bool operator <(const Task& x)const {		/** Sobrecargamos el operador */
			return this-> priority < x.priority;
		}  
	};
}