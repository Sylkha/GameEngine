// Code released into the public domain
// in January 2021
// by Silvia

#include "Limits_Controller.h"
#include "Math.hpp"

using namespace gameEngine;
using namespace glt;
void Limits_Controller::update(Entity& entity, float deltatime) {

	Vector3 playerPosition = extract_translation(player_Entity->get_transform());
	Vector3 myPosition = extract_translation(entity.get_transform());
	float speed = player_Controller.getSpeed();
	/** Si está queriendo sobrepasar el límite, le desplazamos el equivalente a su velocidad. */
	switch (pos) {
		case Up:
			if (playerPosition.y > myPosition.y - 2) {
				player_Entity->set_transform(translate(player_Entity->get_transform(), Vector3(0.f, -speed, 0.f)));
			}
			break;
		case Down:
			if (playerPosition.y < myPosition.y + 2) {
				player_Entity->set_transform(translate(player_Entity->get_transform(), Vector3(0.f, speed, 0.f)));
			}
			break;
		case Right:
			if (playerPosition.x > myPosition.x - 2) {
				player_Entity->set_transform(translate(player_Entity->get_transform(), Vector3(-speed, 0.f, 0.f)));
			}
			break;
		case Left:
			if (playerPosition.x < myPosition.x + 2) {
				player_Entity->set_transform(translate(player_Entity->get_transform(), Vector3(speed, 0.f, 0.f)));
			}
			break;
	}

	if (player_Controller.getNumbers() > player_Controller.num_max) {
		scene.destroy(entity);
		player_Controller.takeNumber();
	}

}