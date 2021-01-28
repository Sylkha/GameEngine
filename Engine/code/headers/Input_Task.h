// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Task.h"

namespace gameEngine {
	/** Recogemos los tipos de eventos de teclado y lo mandamos en forma de mensaje al Input Mapper */
	class Scene;
	class Input_Task : public Task {
	public:
		Input_Task(Scene& scene, int priority);

		void initialize()override;
		void finalize()override;
		bool consumable()const override { return false; }		
		void run(float time)override;

	};
}