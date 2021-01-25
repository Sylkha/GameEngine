#pragma once
#include "Message.h"

/** Recibe e interpreta los mensajes */
namespace gameEngine {
	class Observer {
	public:
		virtual void handle(Message&) = 0;
	};
}