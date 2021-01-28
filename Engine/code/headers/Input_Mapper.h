// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Message.h"
#include "Task.h"
#include <list>

using namespace std;
namespace gameEngine {
	/** En esta clase recibimos los eventos del Input Task para pasarselo al Messenger */
	class Scene;
	class Input_Mapper : public Task {
		list<Message> message_list;

	public:
		Input_Mapper(Scene& scene, int priority);

		void initialize()override;
		void finalize()override;
		bool consumable() const override { return false; }
		/** Aquí enviamos los mensajes */
		void run(float time)override;
		/** En esta función dejamos que desde el Input Task nos envíe los eventos/mensajes a nuestra lista de mensajes */
		void addMessages(Message message);
	};
}