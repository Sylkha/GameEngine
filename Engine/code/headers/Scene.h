// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Window.hpp"
#include "Kernel.h"
#include "Render_System.h"
#include "Entity.h"
#include "Camera_Component.h"
#include "Model_Component.h"
#include "Light_Component.h"
#include <Cube.hpp>

using namespace std;
namespace gameEngine {
	class Scene {
		Window& window;
		Kernel kernel;
		Render_System render_system;
		

		typedef map <string, shared_ptr<Entity>> entityList;
		entityList entities;

	public:
		Scene(Window& w) : window(w), render_system(*this, render_system.priority) { 
			kernel.add_task(render_system);
			shared_ptr<Entity> entity_camera = make_shared<Entity>(*this, "camera");
			shared_ptr<Entity> entity_light = make_shared<Entity>(*this, "light");
			shared_ptr<Entity> entity_model = make_shared<Entity>(*this, "cube");
			shared_ptr<Entity> entity_model_01 = make_shared<Entity>(*this, "cubee");
			shared_ptr<Entity> entity_model_02 = make_shared<Entity>(*this, "cubeee");
			shared_ptr<Entity> entity_model_03 = make_shared<Entity>(*this, "cubeeee");
			shared_ptr<Entity> entity_model_04 = make_shared<Entity>(*this, "cubeeeee");
			shared_ptr<Entity> entity_model_05 = make_shared<Entity>(*this, "cubeeeeee");

			Camera_Component* camera_component = new Camera_Component();
			Model_Component* model_component = new Model_Component();
			Model_Component* model_component_01 = new Model_Component();
			Model_Component* model_component_02 = new Model_Component();
			Model_Component* model_component_03 = new Model_Component();
			Model_Component* model_component_04 = new Model_Component();
			Model_Component* model_component_05 = new Model_Component();
			Light_Component* light_component = new Light_Component();
			entity_camera->addComponent("camera", camera_component);
			model_component->set_model(make_shared <Model>());
			model_component_01->set_model(make_shared <Model>());
			model_component_02->set_model(make_shared <Model>());
			model_component_03->set_model(make_shared <Model>());
			model_component_04->set_model(make_shared <Model>());
			model_component_05->set_model(make_shared <Model>());


			model_component->get_model()->add(make_shared< Cube >(), Material::default_material());
			model_component_01->get_model()->add(make_shared< Cube >(), Material::default_material());
			model_component_02->get_model()->add(make_shared< Cube >(), Material::default_material());
			model_component_03->get_model()->add(make_shared< Cube >(), Material::default_material());
			model_component_04->get_model()->add(make_shared< Cube >(), Material::default_material());
			model_component_05->get_model()->add(make_shared< Cube >(), Material::default_material());

			entity_model->addComponent("model", model_component);
			entity_model_01->addComponent("model", model_component_01);
			entity_model_02->addComponent("model", model_component_02);
			entity_model_03->addComponent("model", model_component_03);
			entity_model_04->addComponent("model", model_component_04);
			entity_model_05->addComponent("model", model_component_05);
			entity_light->addComponent("light", light_component);


			entity_model->set_transform(translate(entity_model->get_transform(), Vector3(10.f, 0.f, 0.f)));
			entity_model_01->set_transform(translate(entity_model_01->get_transform(), Vector3(-10.f, 0.f, 0.f)));
			entity_model_02->set_transform(translate(entity_model_02->get_transform(), Vector3(0.f, -10.f, 0.f)));
			entity_model_03->set_transform(translate(entity_model_03->get_transform(), Vector3(0.f, 0.f, 0.f)));
			entity_model_04->set_transform(translate(entity_model_04->get_transform(), Vector3(0.f, 0.f, 10.f)));
			entity_model_05->set_transform(translate(entity_model_05->get_transform(), Vector3(0.f, 0.f, -10.f)));
			entity_camera->set_transform(translate(entity_camera->get_transform(), Vector3(0.f, 0.f, 0.f)));
			entity_light->set_transform(translate(entity_light->get_transform(), Vector3(10.f, 10.f, 10.f)));
			
			entity_model->set_transform(scale(entity_model->get_transform(), 1.f));
			entity_model_01->set_transform(scale(entity_model_01->get_transform(), 1.f));
			entity_model_02->set_transform(scale(entity_model_02->get_transform(), 1.f));
			entity_model_03->set_transform(scale(entity_model_03->get_transform(), 1.f));
			entity_model_04->set_transform(scale(entity_model_04->get_transform(), 1.f));
			entity_model_05->set_transform(scale(entity_model_05->get_transform(), 1.f));
			entity_light->set_transform(scale(entity_light->get_transform(), 1.f));
			entity_camera->set_transform(scale(entity_camera->get_transform(), 1.f));
			
			render_system.addObject(entity_camera->get_IDNombre(), camera_component->get_camera());
			render_system.setActiveCamera(entity_camera->get_IDNombre());
			render_system.addObject(entity_light->get_IDNombre(), light_component->get_light());
			//render_system.addObject(entity_model->get_IDNombre(), model_component->get_model());
			//render_system.addObject(entity_model_01->get_IDNombre(), model_component_01->get_model());
			//render_system.addObject(entity_model_02->get_IDNombre(), model_component_02->get_model());
			//render_system.addObject(entity_model_03->get_IDNombre(), model_component_03->get_model());
			render_system.addObject(entity_model_04->get_IDNombre(), model_component_04->get_model());
			//render_system.addObject(entity_model_05->get_IDNombre(), model_component_05->get_model());

			entities[entity_camera->get_IDNombre()] = entity_camera;
			entities[entity_light->get_IDNombre()] = entity_light;
			//entities[entity_model->get_IDNombre()] = entity_model;
			//entities[entity_model_01->get_IDNombre()] = entity_model_01;
			//entities[entity_model_02->get_IDNombre()] = entity_model_02;
			//entities[entity_model_03->get_IDNombre()] = entity_model_03;
			entities[entity_model_04->get_IDNombre()] = entity_model_04;
			//entities[entity_model_05->get_IDNombre()] = entity_model_05;

			run();
		}

	public:
		Window& get_window() { // Pasamos la referencia de la ventana
			return window;
		}
		entityList& getEntities() { return entities; }

		void run() {
			kernel.run(window);
		}
		void stop() {
			kernel.stop();
		}
	};
}