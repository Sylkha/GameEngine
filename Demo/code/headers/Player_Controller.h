// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Controller.h"
#include "Observer.h"
#include "Scene.h"
#include "Entity.h"

using namespace gameEngine;
/** Esta clase lleva el control del jugador */
class Player_Controller : public Controller, public Observer{
	bool movUp;
	bool movDown;
	bool movLeft;
	bool movRight;
	/** En este array dejaremos marcados los n�meros que hemos recogido (ID 0 ser� numero 1, y as�) */
	bool numbers_taken[4] = { false };

public:
	Scene& scene;

	Player_Controller(Scene& scene) : scene(scene){
		scene.getMessenger().add_Observer("KEY_PRESSED", this);
		scene.getMessenger().add_Observer("KEY_RELEASED", this);
	}

	/** Aqu� se traducen los mensajes y definimos cu�les nos interesan */
	void handle(Message& mess)override;

	/** Aqu� se llevan a cabo las acciones */
	void update(Entity& entity, float deltatime) override;

	bool getNumbers(size_t ID) { return numbers_taken[ID]; }
	void takeNumber(size_t num) { numbers_taken[num] = true; }

};