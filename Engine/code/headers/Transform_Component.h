// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Component.h"

using namespace glt;
namespace gameEngine {
	class Transform_Component: public Component {
	public:
		Matrix44 transform;

		Transform_Component() {
			/*transform =
			{
				{ 1.0f, 0.0f, 0.0f, 0.0f },
				{ 0.0f, 1.0f, 0.0f, 0.0f },
				{ 0.0f, 0.0f, 1.0f, 0.0f },
				{ 0.0f, 0.0f, 0.0f, 1.0f },
			};*/
		}
	};
}