#pragma once
#include "Component.h"

using namespace glt;
namespace gameEngine {
	class Transform_Component: public Component {
	public:
		Matrix44 transform;
	};
}