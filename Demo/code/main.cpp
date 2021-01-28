// Code released into the public domain
// in January 2021
// by Silvia

#include <Window.hpp>
#include <Scene.h>
#include <AudioManager.h>
#include <Player_Controller.h>

using namespace gameEngine;

int main()
{
    /** Se crea una ventana: */

    Window window("TEST", 1280, 720/*, true*/);

    window.enable_vsync();

    /** Creamos el audio manager y la escena */

    AudioManager audiomanager;
    const char* music = "../../assets/rainforest-ambience.ogg";
    const char* sound = "../../assets/throw-knife.wav";
    //audiomanager.PlaySound(sound);

    Scene scene(window);

    /** Asignamos el controlador del player a la escena */
    shared_ptr<Player_Controller> player = make_shared<Player_Controller>(scene);
    scene.addController("Player", player);

    scene.run();

    return 0;
}
