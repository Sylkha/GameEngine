// Code released into the public domain
// in January 2021
// by Silvia

#include "Numbers_Controller.h"
#include "Math.hpp"

using namespace gameEngine;
using namespace glt;
void Numbers_Controller::update(Entity& entity, float deltatime) {

	Vector3 playerPosition = extract_translation(player_Entity.get_transform());
	Vector3 myPosition = extract_translation(entity.get_transform());
	if (playerPosition.x - 1 < myPosition.x && playerPosition.x + 1 > myPosition.x && playerPosition.y - 1 < myPosition.y && playerPosition.y + 1 > myPosition.y) {
		/** Si ha tocado el número y su Id es 0 vamos bien, y si el anterior número a este ha sido marcado 
		entonces el jugador va también bien. Si no, quiere decir que el jugador no ha cogido el número anterior a este. */
		if ((ID == 0) || (ID != 0 && player_Controller.getNumbers(ID - 1) == true)) {
			scene.getRender_System().removeObject(player_entity_ID);
			scene.getEntities().erase(player_entity_ID);
			player_Controller.takeNumber(ID);
		}
		else {
			audio.PlaySound(sound);
		}
	}
	
}