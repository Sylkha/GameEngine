// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Component.h"

using namespace glt;
namespace gameEngine {
	/** Componente transform en donde manejamos posición, rotación y escala */
	class Transform_Component: public Component {
	public:
		Matrix44 transform;

		Transform_Component() { }

		bool operator ==(Transform_Component const& transform) {
			return this->transform == transform.transform;
		}
	};
}