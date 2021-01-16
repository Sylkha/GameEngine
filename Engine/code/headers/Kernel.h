#pragma once

#include <set>
#include "Task.h"

using namespace std; 

namespace gameEngine {
	class Kernel {

		set <Task*> task_list; /** Un set en vez de list que necesitará usar el atributo de prioridad de las tareas y así que se vayan ejecutando en ese orden */
		set <Task*> consumable_task_list; /** Tareas que vamos a llamar una sola vez. */
		bool stopped = false;
		float delta;

	public:
		Kernel();
		void add_task(Task& t);
		void delete_task(Task& t);
		/** Para parar la función run */
		void stop() { stopped = true; }

		void run() {
			stopped = false;
			delta = 1.f / 60.f; /** Para el primer fotograma */
			while (!stopped) {
				// timer.start();
				for (auto task : consumable_task_list) { task->run(delta); delete_task(*task); }
				for (auto task : task_list) { task->run(delta); }
				//delta = timer.get_elapsed(); /** Para calcular cuánto tarda de estimación por las tareas. */
			}
		}
	};
}