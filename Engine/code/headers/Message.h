#pragma once

#include <string>

using namespace std;
namespace gameEngine {
	class Message {
	public:
		string id;
		string data;

		/** Para comprobar si dos mensajes son iguales */
		bool operator ==(Message const& message) {
			return this->id == message.id && this->data == message.data;
		}
	};
}