// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Task.h"

namespace gameEngine {
	/** Ejecuta el run de los Controladores */
	class Scene;
	class Update_Task : public Task {
	public:
		Update_Task(Scene& scene, int priority);

		void initialize() override;
		void finalize() override;
		bool consumable() const override { return false; }
		void run(float time) override;
	};
}