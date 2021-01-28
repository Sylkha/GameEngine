// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Controller.h"
#include "Observer.h"
#include "Scene.h"
#include "Entity.h"

using namespace gameEngine;

class Player_Controller : public Controller, public Observer{
	bool movUp;
	bool movDown;
	bool movLeft;
	bool movRight;

public:
	Scene& scene;

	Player_Controller(Scene& scene) : scene(scene){
		scene.getMessenger().add_Observer("KEY_PRESSED", this);
		scene.getMessenger().add_Observer("KEY_RELEASED", this);
	}

	void handle(Message& mess)override;

	void update(Entity& entity, float deltatime) override;

};