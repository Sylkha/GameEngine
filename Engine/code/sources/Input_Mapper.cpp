#include "Input_Mapper.h"
#include "Scene.h"

namespace gameEngine {

	Input_Mapper::Input_Mapper(Scene& scene, int priority) : Task(scene, priority) { }

	void Input_Mapper::initialize() { }
	void Input_Mapper::finalize() { }

	void Input_Mapper::addMessages(Message message) {
		if (message_list.end() == find(message_list.begin(), message_list.end(), message)) { // Que no haya dos mensajes iguales
			message_list.push_back(message);
		}
	}

	void Input_Mapper::run(float time) {
		for (auto& mess : message_list) {
			scene.getMessenger().send_Messages(mess);
		}
		message_list.clear();
	}
}