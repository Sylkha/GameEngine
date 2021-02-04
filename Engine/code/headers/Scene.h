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
#include "Model_Obj.hpp"
#include "Light_Component.h"
#include <Cube.hpp>
#include "Messenger.h"
#include "Controller.h"
#include "Controller_Component.h"
#include "Update_Task.h"
#include "Input_Mapper.h"
#include "Input_Task.h"
#include "Destroy_Task.h"

using namespace glm;
using namespace std;
namespace gameEngine {
	class Scene {
		Window& window;
		Kernel kernel;
		Render_System render_system;
		Update_Task update_task;
		Input_Mapper input_mapper;
		Input_Task input_task;
		Destroy_Task destroy_task;

		typedef map <string, shared_ptr<Entity>> entityList;
		entityList entities;

		Messenger messenger;
		map <string, shared_ptr<Controller>> controllers;

	public:
		Scene(Window& w) : window(w), render_system(*this, 3), update_task(*this, 2), input_mapper(*this, 1), input_task(*this, 0), destroy_task(*this, 0){ 
			kernel.add_task(input_task);
			kernel.add_task(input_mapper);
			kernel.add_task(update_task);
			kernel.add_task(render_system);

			/** Creamos los entities */
			shared_ptr<Entity> entity_camera = make_shared<Entity>(*this, "camera");
			shared_ptr<Entity> entity_light = make_shared<Entity>(*this, "light");
			shared_ptr<Entity> entity_model = make_shared<Entity>(*this, "myplayer"); 

			shared_ptr<Entity> entity_model_n1 = make_shared<Entity>(*this, "numberOne"); 
			shared_ptr<Entity> entity_model_n2 = make_shared<Entity>(*this, "numberTwo"); 
			shared_ptr<Entity> entity_model_n3 = make_shared<Entity>(*this, "numberThree"); 
			shared_ptr<Entity> entity_model_n4 = make_shared<Entity>(*this, "numberFour"); 
			shared_ptr<Entity> entity_model_n5 = make_shared<Entity>(*this, "numberFive"); 

			shared_ptr<Entity> entity_model_r1 = make_shared<Entity>(*this, "rectangleOne"); 
			shared_ptr<Entity> entity_model_r2 = make_shared<Entity>(*this, "rectangleTwo"); 
			shared_ptr<Entity> entity_model_r3 = make_shared<Entity>(*this, "rectangleThree"); 
			shared_ptr<Entity> entity_model_r4 = make_shared<Entity>(*this, "rectangleFour"); 

			/** Creamos los componentes y se los añadimos a cada entity que tengamos pensado que vaya a tener dicho componente */
			Camera_Component* camera_component = new Camera_Component();
			Light_Component* light_component = new Light_Component();
			Model_Component* model_component = new Model_Component();

			Model_Component* model_component_n1 = new Model_Component();
			Model_Component* model_component_n2 = new Model_Component();
			Model_Component* model_component_n3 = new Model_Component();
			Model_Component* model_component_n4 = new Model_Component();
			Model_Component* model_component_n5 = new Model_Component();

			Model_Component* model_component_r1 = new Model_Component();
			Model_Component* model_component_r2 = new Model_Component();
			Model_Component* model_component_r3 = new Model_Component();
			Model_Component* model_component_r4 = new Model_Component();

			entity_camera->addComponent("camera", camera_component);
			entity_model->addComponent("model", model_component);
			entity_light->addComponent("light", light_component);

			entity_model_n1->addComponent("model", model_component_n1);
			entity_model_n2->addComponent("model", model_component_n2);
			entity_model_n3->addComponent("model", model_component_n3);
			entity_model_n4->addComponent("model", model_component_n4);
			entity_model_n5->addComponent("model", model_component_n5);

			entity_model_r1->addComponent("model", model_component_r1);
			entity_model_r2->addComponent("model", model_component_r2);
			entity_model_r3->addComponent("model", model_component_r3);
			entity_model_r4->addComponent("model", model_component_r4);

			/** Necesitamos crear un modelo para añadirselo al model component. También necesitamos añadir las mallas a los modelos antes de añadirlos a la escena */
			shared_ptr<Model> bunny(new Model_Obj("../../assets/stanford-bunny.obj"));
			model_component->set_model(bunny);

			shared_ptr<Model> num1(new Model_Obj("../../assets/Number1.obj"));
			model_component_n1->set_model(num1);
			shared_ptr<Model> num2(new Model_Obj("../../assets/Number2.obj"));
			model_component_n2->set_model(num2);
			shared_ptr<Model> num3(new Model_Obj("../../assets/Number3.obj"));
			model_component_n3->set_model(num3);
			shared_ptr<Model> num4(new Model_Obj("../../assets/Number4.obj"));
			model_component_n4->set_model(num4);
			shared_ptr<Model> num5(new Model_Obj("../../assets/Number5.obj"));
			model_component_n5->set_model(num5);

			shared_ptr<Model> rec1(new Model_Obj("../../assets/Cube.obj"));
			model_component_r1->set_model(rec1);
			shared_ptr<Model> rec2(new Model_Obj("../../assets/Cube.obj"));
			model_component_r2->set_model(rec2);
			shared_ptr<Model> rec3(new Model_Obj("../../assets/Cube.obj"));
			model_component_r3->set_model(rec3);
			shared_ptr<Model> rec4(new Model_Obj("../../assets/Cube.obj"));
			model_component_r4->set_model(rec4);

			/** Que nos siga la cámara */
			entity_camera->set_parent(entity_model);
			/** Colocamos los objetos en el espacio */
			entity_camera->set_transform(translate(entity_camera->get_transform(), Vector3(0.f, 0.f, 10.f)));
			entity_light->set_transform(translate(entity_light->get_transform(), Vector3(10.f, 10.f, 10.f)));
			entity_model->set_transform(translate(entity_model->get_transform(), Vector3(0.f, 0.f, -10.f)));

			entity_model_n1->set_transform(translate(entity_model_n1->get_transform(), Vector3(-10.f, 4.f, -10.f)));
			entity_model_n2->set_transform(translate(entity_model_n2->get_transform(), Vector3(0.f, 4.f, -10.f)));
			entity_model_n3->set_transform(translate(entity_model_n3->get_transform(), Vector3(10.f, 0.f, -10.f)));
			entity_model_n4->set_transform(translate(entity_model_n4->get_transform(), Vector3(0.f, -5.f, -10.f)));
			entity_model_n5->set_transform(translate(entity_model_n5->get_transform(), Vector3(-10.f, -4.f, -10.f)));

			entity_model_r1->set_transform(translate(entity_model_r1->get_transform(), Vector3(-15.f, 0.f, -12.f)));
			entity_model_r2->set_transform(translate(entity_model_r2->get_transform(), Vector3(0.f, 10.f, -12.f)));
			entity_model_r3->set_transform(translate(entity_model_r3->get_transform(), Vector3(15.f, 0.f, -12.f)));
			entity_model_r4->set_transform(translate(entity_model_r4->get_transform(), Vector3(0.f, -10.f, -12.f)));


			/** Rotamos los objetos */
			entity_model_n1->set_transform(glm::rotate(entity_model_n1->get_transform(), 90.f ,Vector3(-1,0,0)));
			entity_model_n2->set_transform(glm::rotate(entity_model_n2->get_transform(), 90.f ,Vector3(-1,0,0)));
			entity_model_n3->set_transform(glm::rotate(entity_model_n3->get_transform(), 90.f ,Vector3(-1,0,0)));
			entity_model_n4->set_transform(glm::rotate(entity_model_n4->get_transform(), 90.f ,Vector3(-1,0,0)));
			entity_model_n5->set_transform(glm::rotate(entity_model_n5->get_transform(), 90.f ,Vector3(-1,0,0)));


			/** Escalamos los objetos */
			entity_model_n1->set_transform(scale(entity_model_n1->get_transform(), 0.2));
			entity_model_n2->set_transform(scale(entity_model_n2->get_transform(), 0.2));
			entity_model_n3->set_transform(scale(entity_model_n3->get_transform(), 0.2));
			entity_model_n4->set_transform(scale(entity_model_n4->get_transform(), 0.2));
			entity_model_n5->set_transform(scale(entity_model_n5->get_transform(), 0.2));

			entity_model_r1->set_transform(scale(entity_model_r1->get_transform(), Vector3(0.5, 10.5, 0.5))); // derecha
			entity_model_r2->set_transform(scale(entity_model_r2->get_transform(), Vector3(15, 0.5, 0.5))); // el de arriba
			entity_model_r3->set_transform(scale(entity_model_r3->get_transform(), Vector3(0.5, 10.5, 0.5))); // izquierda
			entity_model_r4->set_transform(scale(entity_model_r4->get_transform(), Vector3(15, 0.5, 0.5))); // el de abajo
			
			/** Añadimos los nodos a la escena */
			render_system.addObject(entity_camera->get_IDNombre(), camera_component->get_camera());
			render_system.setActiveCamera(entity_camera->get_IDNombre());
			render_system.addObject(entity_light->get_IDNombre(), light_component->get_light());
			render_system.addObject(entity_model->get_IDNombre(), model_component->get_model());

			render_system.addObject(entity_model_n1->get_IDNombre(), model_component_n1->get_model());
			render_system.addObject(entity_model_n2->get_IDNombre(), model_component_n2->get_model());
			render_system.addObject(entity_model_n3->get_IDNombre(), model_component_n3->get_model());
			render_system.addObject(entity_model_n4->get_IDNombre(), model_component_n4->get_model());
			render_system.addObject(entity_model_n5->get_IDNombre(), model_component_n5->get_model());

			render_system.addObject(entity_model_r1->get_IDNombre(), model_component_r1->get_model());
			render_system.addObject(entity_model_r2->get_IDNombre(), model_component_r2->get_model());
			render_system.addObject(entity_model_r3->get_IDNombre(), model_component_r3->get_model());
			render_system.addObject(entity_model_r4->get_IDNombre(), model_component_r4->get_model());

			/** Guardamos los entities en un map (que los recoge y actualiza su transform) */
			entities[entity_camera->get_IDNombre()] = entity_camera;
			entities[entity_light->get_IDNombre()] = entity_light;
			entities[entity_model->get_IDNombre()] = entity_model;

			entities[entity_model_n1->get_IDNombre()] = entity_model_n1;
			entities[entity_model_n2->get_IDNombre()] = entity_model_n2;
			entities[entity_model_n3->get_IDNombre()] = entity_model_n3;
			entities[entity_model_n4->get_IDNombre()] = entity_model_n4;
			entities[entity_model_n5->get_IDNombre()] = entity_model_n5;

			entities[entity_model_r1->get_IDNombre()] = entity_model_r1;
			entities[entity_model_r2->get_IDNombre()] = entity_model_r2;
			entities[entity_model_r3->get_IDNombre()] = entity_model_r3;
			entities[entity_model_r4->get_IDNombre()] = entity_model_r4;

		}

	public:
		Window& get_window() { return window; }
		entityList& getEntities() { return entities; }

		Messenger& getMessenger() { return messenger; }

		Input_Mapper& getInput_Mapper() { return input_mapper; }

		Render_System& getRender_System() { return render_system; }

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
			entities["myplayer"]->addComponent("controller", controller_c.get());

			shared_ptr<Controller_Component>  controller_num1 = make_shared<Controller_Component>();
			controller_num1->set_Controller(controllers["Num1"]);
			entities["numberOne"]->addComponent("controller", controller_num1.get());

			shared_ptr<Controller_Component>  controller_num2 = make_shared<Controller_Component>();
			controller_num2->set_Controller(controllers["Num2"]);
			entities["numberTwo"]->addComponent("controller", controller_num2.get());

			shared_ptr<Controller_Component>  controller_num3 = make_shared<Controller_Component>();
			controller_num3->set_Controller(controllers["Num3"]);
			entities["numberThree"]->addComponent("controller", controller_num3.get());

			shared_ptr<Controller_Component>  controller_num4 = make_shared<Controller_Component>();
			controller_num4->set_Controller(controllers["Num4"]);
			entities["numberFour"]->addComponent("controller", controller_num4.get());

			shared_ptr<Controller_Component>  controller_num5 = make_shared<Controller_Component>();
			controller_num5->set_Controller(controllers["Num5"]);
			entities["numberFive"]->addComponent("controller", controller_num5.get());

			shared_ptr<Controller_Component>  controller_r1 = make_shared<Controller_Component>();
			controller_r1->set_Controller(controllers["Rec1"]);
			entities["rectangleOne"]->addComponent("controller", controller_r1.get());

			shared_ptr<Controller_Component>  controller_r2 = make_shared<Controller_Component>();
			controller_r2->set_Controller(controllers["Rec2"]);
			entities["rectangleTwo"]->addComponent("controller", controller_r2.get());

			shared_ptr<Controller_Component>  controller_r3 = make_shared<Controller_Component>();
			controller_r3->set_Controller(controllers["Rec3"]);
			entities["rectangleThree"]->addComponent("controller", controller_r3.get());

			shared_ptr<Controller_Component>  controller_r4 = make_shared<Controller_Component>();
			controller_r4->set_Controller(controllers["Rec4"]);
			entities["rectangleFour"]->addComponent("controller", controller_r4.get());

			kernel.run();
		}
		void stop() {
			kernel.stop();
		}
		
		void destroy(Entity entityToDestroy) {
			destroy_task.addEntities(entityToDestroy);
			kernel.add_task(destroy_task);
		}
	};
}