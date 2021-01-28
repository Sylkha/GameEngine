// Code released into the public domain
// in January 2021
// by Silvia

#include "Update_Task.h"
#include "Controller_Component.h"
#include "Scene.h"

namespace gameEngine {

	Update_Task::Update_Task(Scene& scene, int priority) : Task(scene, priority) { }

	void Update_Task::initialize() { }
	void Update_Task::finalize() { }

	void Update_Task::run(float time) {
		auto& entities = scene.getEntities();
		for (auto& entity : entities) {
			Controller_Component* controller_Component = dynamic_cast<Controller_Component*>(entity.second->getComponent("controller"));
			if (controller_Component) 
				controller_Component->get_Controller().update(*entity.second, time);
		}
	}

}