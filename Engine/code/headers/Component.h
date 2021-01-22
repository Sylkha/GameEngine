// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Math.hpp"

namespace gameEngine {
	class Component {
		// Entity* parent;
	public:
		Component(){}
		virtual ~Component() = 0 {}
	};
}