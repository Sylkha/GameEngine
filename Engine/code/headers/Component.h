#pragma once
#include "Math.hpp"

namespace gameEngine {
	class Component {
		// Entity* parent;
	public:
		Component();
		virtual ~Component() = 0;
	};
}