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
		/** Que no recoja varias veces el mismo objeto */
		if (entities.end() == find(entities.begin(), entities.end(), entity)) { 
			entities.push_back(entity);
		}
	}

	void Destroy_Task::run(float time) {
		for (auto& entity : entities) {
			/** Hacemos invisible el entity y lo quitamos de la lista de entities de la escena  */
			scene.getRender_System().removeObject(entity.get_IDNombre());
			scene.getEntities().erase(entity.get_IDNombre());
		}
		/** Limpiamos nuestra lista */
		entities.clear();
	}
}