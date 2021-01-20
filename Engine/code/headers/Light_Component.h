#pragma once
#include "Component.h"
#include "Light.hpp"

using namespace std;
using namespace glt;
namespace gameEngine {
	class Light_Component : public Component{
	public:
		shared_ptr<Light> light;

		Light_Component() {
			light = make_shared<Light>();
		}

		shared_ptr<Light> get_light() { return light; }
	};
}