// Code released into the public domain
// in January 2021
// by Silvia

#include "Kernel.h"


namespace gameEngine {
	Kernel::Kernel(){}

	void Kernel::add_task(Task& t) {
		if (t.consumable() == false) {
			if (task_list.find(&t) == task_list.end())
				task_list.insert(&t);
		}
		else {
			if (consumable_task_list.find(&t) == consumable_task_list.end())
				consumable_task_list.insert(&t);
		}
	}
	void Kernel::delete_consumable_task() {
		consumable_task_list.clear();
	}

	void Kernel::run() {
		stopped = false;
		Timer timer;
		/** Para el primer fotograma */
		delta = 1.f / 60.f; 
		for (auto task : consumable_task_list) task->initialize();
		for (auto task : task_list) task->initialize();
		do {
			timer.start();
			for (auto task : consumable_task_list) { task->run(delta); }
			delete_consumable_task();
			for (auto task : task_list) { task->run(delta); }
			delta = timer.elapsed_seconds(); /** Para calcular cu�nto tarda de estimaci�n por las tareas. */
		} while (!stopped);

		for (auto task : task_list)  task->finalize(); 
	}

}