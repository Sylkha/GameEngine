// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Message.h"

namespace gameEngine {
/** El objetivo de esta clase padre es que el hijo reciba e interprete los mensajes */
	class Observer {
	public:
		virtual void handle(Message&) = 0;
	};
}