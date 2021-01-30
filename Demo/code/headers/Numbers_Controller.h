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
/** Esta clase la llevan los números */
class Numbers_Controller : public Controller {
	size_t ID;
	string player_entity_ID;
	Player_Controller& player_Controller;
	AudioManager& audio;
	const char* sound;

	shared_ptr<Entity> player_Entity;

	bool sound_control = false;

public:
	Scene& scene;

	Numbers_Controller(Scene& scene, string player_entity_ID,Player_Controller & player_Controller, size_t ID, AudioManager& audio, const char* sound) 
		: scene(scene), player_entity_ID(player_entity_ID), player_Controller(player_Controller), ID(ID), audio(audio), sound(sound){
	
		for (auto& entity : scene.getEntities()) {
			if (entity.first == player_entity_ID) {
				player_Entity = entity.second;
			}
		}
	
	}

	/** Aquí se llevan a cabo las acciones */
	void update(Entity& entity, float deltatime) override;

};
