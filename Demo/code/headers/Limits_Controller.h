// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Controller.h"
#include "Scene.h"
#include "Entity.h"
#include "Player_Controller.h"

using namespace gameEngine;
	enum position {Up, Down, Right, Left};
/** Esta clase la llevan los límites de la pantalla para que el jugador no lo sobrepase */
class Limits_Controller : public Controller {
	string player_entity_ID;
	Player_Controller& player_Controller;

	shared_ptr<Entity> player_Entity;

	position pos = Up;

public:
	Scene& scene;

	Limits_Controller(Scene& scene, string player_entity_ID, Player_Controller& player_Controller, position pos)
		: scene(scene), player_entity_ID(player_entity_ID), player_Controller(player_Controller), pos(pos) {
		/** Buscamos al entity player */
		for (auto& entity : scene.getEntities()) {
			if (entity.first == player_entity_ID) {
				player_Entity = entity.second;
			}
		}

	}

	/** Aquí se llevan a cabo las acciones */
	void update(Entity& entity, float deltatime) override;

};
