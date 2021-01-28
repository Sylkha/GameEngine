// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Math.hpp"

namespace gameEngine {
	/** Componente padre */
	class Component {
	public:
		Component(){}
		virtual ~Component() = 0 {}
	};
}