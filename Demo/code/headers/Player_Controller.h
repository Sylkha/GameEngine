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
	/** En este array dejaremos marcados los números que hemos recogido (ID 0 será numero 1, y así) */
	size_t num_taken_count = 0;

public:
	Scene& scene;

	Player_Controller(Scene& scene) : scene(scene){
		scene.getMessenger().add_Observer("KEY_PRESSED", this);
		scene.getMessenger().add_Observer("KEY_RELEASED", this);
	}

	/** Aquí se traducen los mensajes y definimos cuáles nos interesan */
	void handle(Message& mess)override;

	/** Aquí se llevan a cabo las acciones */
	void update(Entity& entity, float deltatime) override;

	size_t getNumbers() { return num_taken_count; }
	void takeNumber() { num_taken_count++; }

};