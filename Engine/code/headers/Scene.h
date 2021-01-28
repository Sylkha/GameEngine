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
#include "Messenger.h"
#include "Controller.h"
#include "Controller_Component.h"
#include "Update_Task.h"
#include "Input_Mapper.h"
#include "Input_Task.h"

using namespace std;
namespace gameEngine {
	class Scene {
		Window& window;
		Kernel kernel;
		Render_System render_system;
		Update_Task update_task;
		Input_Mapper input_mapper;
		Input_Task input_task;

		typedef map <string, shared_ptr<Entity>> entityList;
		entityList entities;

		Messenger messenger;
		map <string, shared_ptr<Controller>> controllers;

	public:
		Scene(Window& w) : window(w), render_system(*this, 3), update_task(*this, 2), input_mapper(*this, 1), input_task(*this, 0) { 
			kernel.add_task(input_task);
			kernel.add_task(input_mapper);
			kernel.add_task(update_task);
			kernel.add_task(render_system);
			/** Creamos los entities */
			shared_ptr<Entity> entity_camera = make_shared<Entity>(*this, "camera");
			shared_ptr<Entity> entity_light = make_shared<Entity>(*this, "light");
			shared_ptr<Entity> entity_model = make_shared<Entity>(*this, "mycube"); /** This id must change if we create more models */

			/** Creamos los componentes y se los añadimos a cada entity que tengamos pensado que vaya a tener dicho componente */
			Camera_Component* camera_component = new Camera_Component();
			Model_Component* model_component = new Model_Component();
			Light_Component* light_component = new Light_Component();
			entity_camera->addComponent("camera", camera_component);
			entity_model->addComponent("model", model_component);
			entity_light->addComponent("light", light_component);

			/** Necesitamos crear un modelo para añadirselo al model component. También necesitamos añadir las mallas a los modelos antes de añadirlos a la escena */
			model_component->set_model(make_shared <Model>());
			model_component->get_model()->add(make_shared< Cube >(), Material::default_material());

			/** Colocamos los objetos en el espacio */
			entity_model->set_transform(translate(entity_model->get_transform(), Vector3(0.f, 0.f, -10.f)));
			entity_camera->set_transform(translate(entity_camera->get_transform(), Vector3(0.f, 0.f, 0.f)));
			entity_light->set_transform(translate(entity_light->get_transform(), Vector3(10.f, 10.f, 10.f)));
			
			/** Añadimos los nodos a la escena */
			render_system.addObject(entity_camera->get_IDNombre(), camera_component->get_camera());
			render_system.setActiveCamera(entity_camera->get_IDNombre());
			render_system.addObject(entity_light->get_IDNombre(), light_component->get_light());
			render_system.addObject(entity_model->get_IDNombre(), model_component->get_model());

			/** Guardamos los entities en un map (que los recoge y actualiza su transform) */
			entities[entity_camera->get_IDNombre()] = entity_camera;
			entities[entity_light->get_IDNombre()] = entity_light;
			entities[entity_model->get_IDNombre()] = entity_model;

		}

	public:
		Window& get_window() { return window; }
		entityList& getEntities() { return entities; }

		Messenger& getMessenger() { return messenger; }

		Input_Mapper& getInput_Mapper() { return input_mapper; }

		bool addController(string id, shared_ptr<Controller> controller)
		{ 
			/** Si ese id existe, no lo añadimos */
			if (controllers.count(id) != 0) 
				return false;
			else {
				controllers[id] = controller;
				return true;
			}
		}

		void run() {
			/** Creamos el componente y lo asignamos a la entidad que corresponde. Con un xml no haría falta poner estas cosas en la escena */
			shared_ptr<Controller_Component>  controller_c = make_shared<Controller_Component>();
			controller_c->set_Controller(controllers["Player"]);
			entities["mycube"]->addComponent("controller", controller_c.get());

			kernel.run();
		}
		void stop() {
			kernel.stop();
		}
	};
}