// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Component.h"
#include "Camera.hpp"

using namespace std;
using namespace glt;
namespace gameEngine {
	class Camera_Component : public Component {
	public:
		shared_ptr<Camera> camera;

		Camera_Component() { 
			camera = make_shared<Camera>(); 
			camera->set(20.f, 1.f, 50.f, 1.f);
		}
		
		shared_ptr<Camera> get_camera() { return camera; }
	};
}