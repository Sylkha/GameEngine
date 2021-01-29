// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Controller.h"
#include "Scene.h"
#include "Entity.h"
#include "Player_Controller.h"
#include "AudioManager.h"

using namespace gameEngine;
/** Esta clase la llevan los n�meros */
class Numbers_Controller : public Controller {
	size_t ID;
	string player_entity_ID;
	Player_Controller& player_Controller;
	AudioManager& audio;
	const char* sound;

	Entity player_Entity;

public:
	Scene& scene;

	Numbers_Controller(Scene& scene, string player_entity_ID,Player_Controller & player_Controller, size_t ID, AudioManager& audio, const char* sound) 
		: scene(scene), player_entity_ID(player_entity_ID), player_Controller(player_Controller), ID(ID), audio(audio), sound(sound), player_Entity(scene, "id") {
	
		for (auto& entity : scene.getEntities()) {
			if (entity.first == player_entity_ID) {
				player_Entity = entity;
			}
		}
	
	}

	/** Aqu� se llevan a cabo las acciones */
	void update(Entity& entity, float deltatime) override;

};
