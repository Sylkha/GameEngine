// Code released into the public domain
// in January 2021
// by Silvia

#pragma once

#include <set>
#include "Task.h"
#include <Timer.h>
#include <Window.hpp>

using namespace std; 

namespace gameEngine {
	/** Ejecuta las tareas */
	class Kernel {

		set <Task*, Task::Task_Less_Compare> task_list; /** Un set en vez de list que necesitará usar el atributo de prioridad de las tareas y así que se vayan ejecutando en ese orden */
		set <Task*, Task::Task_Less_Compare> consumable_task_list; /** Tareas que vamos a llamar una sola vez. */
		bool stopped = false;
		float delta;

	public:
		Kernel();
		void add_task(Task& t);
		void delete_consumable_task();
		/** Para parar la función run */
		void stop() { stopped = true; }

		void run();
	};
}