// Code released into the public domain
// in January 2021
// by Silvia

#include "Destroy_Task.h"
#include "Scene.h"

namespace gameEngine {
	Destroy_Task::Destroy_Task(Scene& scene, int priority) : Task(scene, priority) { }

	void Destroy_Task::initialize() { }
	void Destroy_Task::finalize() { }

	void Destroy_Task::addEntities(Entity entity) {
		if (entities.end() == find(entities.begin(), entities.end(), entity)) { // Que no haya dos entities iguales
			entities.push_back(entity);
		}
	}

	void Destroy_Task::run(float time) {
		for (auto& entity : entities) {
			scene.getRender_System().removeObject(entity.get_IDNombre());
			scene.getEntities().erase(entity.get_IDNombre());
		}
		entities.clear();
	}
}