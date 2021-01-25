#pragma once

#include "Entity.h"
namespace gameEngine {
	class Controller {
	public:
		virtual void update(Entity& entity, float deltatime) = 0 {}

		virtual ~Controller() = 0 {}
	};
}