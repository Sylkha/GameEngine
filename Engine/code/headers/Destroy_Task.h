// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Task.h"
#include "Entity.h"

#include <list>

using namespace std;
namespace gameEngine {
	/** Esta clase es una task consumible que necesitamos para retirar aquellos objetos
	*   que, en tiempo de ejecución, queremos que dejen de ser renderizados (que desaparezcan).
	*/
	class Scene;
	class Destroy_Task : public Task {
	public:
		list <Entity> entities;
		Destroy_Task(Scene& scene, int priority);

		void initialize()override;
		void finalize()override;
		bool consumable()const override { return true; }
		void run(float time)override;

		/** Añadimos a nuestra lista de entities, aquellos entities que queremos dejar de renderizar */
		void addEntities(Entity entity);
	};
	
}