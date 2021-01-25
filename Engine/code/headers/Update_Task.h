#pragma once
#include "Task.h"

namespace gameEngine {
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