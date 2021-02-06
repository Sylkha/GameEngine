// Code released into the public domain
// in January 2021
// by Silvia

#pragma once
#include "Controller.h"
#include "Observer.h"
#include "Scene.h"
#include "Entity.h"
#include "AudioManager.h"

using namespace gameEngine;
/** Esta clase lleva el control del jugador */
class Player_Controller : public Controller, public Observer{
	bool movUp;
	bool movDown;
	bool movLeft;
	bool movRight;
	/** Este es el contador de números */
	size_t num_taken_count = 0;
	/** Movimiento del jugador */
	float speed = 0.05f;

	AudioManager& audio;
	const char* sound;

	/** Este bool nos sirve para que solo se reproduzca una vez el sonido. */
	bool sound_control = false;

public:
	/** Este es el número máximo de números que queremos recoger (menos 1 porque usamos el > para compararlo) */
	const size_t num_max = 4;

public:
	Scene& scene;

	Player_Controller(Scene& scene, AudioManager& audio, const char* sound) : scene(scene), audio(audio), sound(sound) {
		scene.getMessenger().add_Observer("KEY_PRESSED", this);
		scene.getMessenger().add_Observer("KEY_RELEASED", this);
	}

	/** Aquí se traducen los mensajes y definimos cuáles nos interesan */
	void handle(Message& mess)override;

	/** Aquí se llevan a cabo las acciones */
	void update(Entity& entity, float deltatime) override;

	size_t getNumbers() { return num_taken_count; }
	void takeNumber() { num_taken_count++; }

	float getSpeed() { return speed; }

};