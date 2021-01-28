// Code released into the public domain
// in January 2021
// by Silvia

#include "Input_Task.h"
#include "Scene.h"
#include "Message.h"

namespace gameEngine {

	Input_Task::Input_Task(Scene& scene, int priority) : Task(scene, priority) { }

	void Input_Task::initialize() { }
	void Input_Task::finalize() { }

	void Input_Task::run(float time) {
		Window::Event event;

		while (scene.get_window().poll(event))
		{
			Message message;
			switch (event.type)
			{
				case Window::Event::CLOSE:
				{
					scene.stop();	//stopped = true;
					break;
				}

				case Window::Event::KEY_PRESSED:
				{
					/** ID al que suscribirse */
					message.id = "KEY_PRESSED";
					switch (event.data.keyboard.key_code) {
					/** Lectura de teclas: */
					case Keyboard::KEY_ESCAPE: message.data = "Tecla Escape"; scene.stop();
						break;
					case Keyboard::KEY_A: message.data = "Tecla A";
						break;

					case Keyboard::KEY_W: message.data = "Tecla W";
						break;

					case Keyboard::KEY_S: message.data = "Tecla S";
						break;

					case Keyboard::KEY_D: message.data = "Tecla D";
						break;

					}
					break;
				}
				case Window::Event::KEY_RELEASED:
				{
					message.id = "KEY_RELEASED";
					switch (event.data.keyboard.key_code) {
						// Lectura de teclas:
					case Keyboard::KEY_ESCAPE: message.data = "Tecla Escape"; scene.stop();
						break;
					case Keyboard::KEY_A: message.data = "Tecla A";
						break;

					case Keyboard::KEY_W: message.data = "Tecla W";
						break;

					case Keyboard::KEY_S: message.data = "Tecla S";
						break;

					case Keyboard::KEY_D: message.data = "Tecla D";
						break;

					}
					break;
				}

			}
			/** Mandamos el mensaje al Input Mapper */
			if (message.data != "") {
				scene.getInput_Mapper().addMessages(message);				
			}
		}
	}
}