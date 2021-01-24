// Code released into the public domain
// in January 2021
// by Silvia

#include <Render_System.h>

#include <Scene.h>
#include "Model_Component.h"
#include "Camera_Component.h"
#include "Light_Component.h"


namespace gameEngine {
	Render_System::Render_System(Scene& scene, int priority) : Task(scene, priority) { priority = 1; renderer.reset(new Render_Node); }

	void Render_System::initialize() { }
	void Render_System::finalize() { }

	void Render_System::addObject(string ID, shared_ptr<Model>model) {
		renderer->add(ID, model);
	}
	void Render_System::addObject(string ID, shared_ptr<Camera>camera) {
		renderer->add(ID, camera);
	}
	void Render_System::addObject(string ID, shared_ptr<Light>light) {
		renderer->add(ID, light);
	}

	void Render_System::setActiveCamera(string ID) {
		renderer->set_active_camera(ID);
	}

	void Render_System::run(float time) {
		/** Se ajusta el viewport por si el tamaño de la ventana ha cambiado: */
        GLsizei width = GLsizei(scene.get_window().get_width());
        GLsizei height = GLsizei(scene.get_window().get_height());
		
		renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

		auto& entities = scene.getEntities();
		/** Actualizamos los transform */
		for (auto& entity : entities) {
			Model_Component* model = dynamic_cast<Model_Component*>(entity.second->getComponent("model"));
			if (model) model->get_model()->set_transformation(entity.second->get_transform()); 

			Camera_Component* camera = dynamic_cast<Camera_Component*>(entity.second->getComponent("camera"));
			if (camera) camera->get_camera()->set_transformation(entity.second->get_transform()); 
			
			Light_Component* light = dynamic_cast<Light_Component*>(entity.second->getComponent("light"));
			if (light) light->get_light()->set_transformation(entity.second->get_transform()); 

		}

        /** Se renderiza la escena y se intercambian los buffers de la ventana para hacer visible lo que se ha renderizado: */
		scene.get_window().clear();

        renderer->render();

		scene.get_window().swap_buffers();
	}
}