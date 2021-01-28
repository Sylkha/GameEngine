// Code released into the public domain
// in January 2021
// by Silvia

#pragma once

namespace gameEngine {
	/** Declaración anticipada porque las task van en Scene */
	class Scene; 

	class Task {
	public:
		/** número más pequeño, + prioridad. */
		int priority; 

		struct Task_Less_Compare
		{
			bool operator () (const Task* a, const Task* b) const
			{
				/** Se usa el operador < sobrecargado en la clase Task */
				return *a < *b;       
			}
		};

	protected:
		Scene & scene;

	public:
		Task(Scene& scene, int priority) : scene(scene), priority(priority){}
		/** indicamos al Kernel si nos tiene que ejecutar una vez o hasta que termine el programa. Devuelve true o false */
		virtual bool consumable () const = 0; 
		/** método virtual puro, por lo que haremos tareas especificas que hereden de Task. */
		virtual void run(float time) = 0;		 
		virtual void initialize() = 0;
		virtual void finalize() = 0;
		/** Sobrecargamos el operador < para que el set ponga en orden de prioridad las Tasks */
		bool operator <(const Task& x)const {		
			return this-> priority < x.priority;
		}  
	};
}