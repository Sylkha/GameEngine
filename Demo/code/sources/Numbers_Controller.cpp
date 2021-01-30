// Code released into the public domain
// in January 2021
// by Silvia

#include "Numbers_Controller.h"
#include "Math.hpp"

using namespace gameEngine;
using namespace glt;
void Numbers_Controller::update(Entity& entity, float deltatime) {

	Vector3 playerPosition = extract_translation(player_Entity->get_transform());
	Vector3 myPosition = extract_translation(entity.get_transform());
	if (playerPosition.x - 2 < myPosition.x && playerPosition.x + 2 > myPosition.x && playerPosition.y - 2 < myPosition.y && playerPosition.y + 2 > myPosition.y) {
		/** Si ha tocado el número y su Id es 0 vamos bien, y si el anterior número a este ha sido marcado 
		entonces el jugador va también bien. Si no, quiere decir que el jugador no ha cogido el número anterior a este. */
		if (player_Controller.getNumbers() == ID) {
			scene.destroy(entity);
			player_Controller.takeNumber();
		}
		else if(sound_control == false) {
			audio.PlaySound(sound);
			sound_control = true;
		}
	}
	else {
		sound_control = false;
	}
	
}