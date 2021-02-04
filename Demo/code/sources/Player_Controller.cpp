// Code released into the public domain
// in January 2021
// by Silvia

#include "Player_Controller.h"

using namespace gameEngine;


void Player_Controller::handle(Message& mess) {
	if (mess.id == "KEY_PRESSED") {
		if (mess.data == "Tecla A") {
			movLeft = true;
		}
		if (mess.data == "Tecla W") {
			movUp = true;
		}
		if (mess.data == "Tecla S") {
			movDown = true;
		}
		if (mess.data == "Tecla D") {
			movRight = true;
		}
	}
	if (mess.id == "KEY_RELEASED") {
		if (mess.data == "Tecla A") {
			movLeft = false;
		}
		if (mess.data == "Tecla W") {
			movUp = false;
		}
		if (mess.data == "Tecla S") {
			movDown = false;
		}
		if (mess.data == "Tecla D") {
			movRight = false;
		}
	}
}

void Player_Controller::update(Entity& entity, float deltatime) {

	if (movLeft == true) {
		entity.set_transform(translate(entity.get_transform(), Vector3(-speed, 0, 0)));
	}

	if (movUp == true) {
		entity.set_transform(translate(entity.get_transform(), Vector3(0, speed, 0)));
	}

	if (movDown == true) {
		entity.set_transform(translate(entity.get_transform(), Vector3(0, -speed, 0)));
	}

	if (movRight == true) {
		entity.set_transform(translate(entity.get_transform(), Vector3(speed, 0, 0)));
	}

}