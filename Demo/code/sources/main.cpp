// Code released into the public domain
// in January 2021
// by Silvia

#include <Window.hpp>
#include <Scene.h>
#include <AudioManager.h>
#include <Player_Controller.h>
#include "Numbers_Controller.h"

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

    Scene scene(window);

    /** Asignamos el controlador del player a la escena */
    shared_ptr<Player_Controller> player = make_shared<Player_Controller>(scene);
    scene.addController("Player", player);

    shared_ptr<Numbers_Controller> num1 = make_shared<Numbers_Controller>(scene, "myplayer", player, 0, audiomanager, sound);
    scene.addController("Num1", num1);
    shared_ptr<Numbers_Controller> num2 = make_shared<Numbers_Controller>(scene, "myplayer", player, 1, audiomanager, sound);
    scene.addController("Num2", num2);
    shared_ptr<Numbers_Controller> num3 = make_shared<Numbers_Controller>(scene, "myplayer", player, 2, audiomanager, sound);
    scene.addController("Num3", num3);
    shared_ptr<Numbers_Controller> num4 = make_shared<Numbers_Controller>(scene, "myplayer", player, 3, audiomanager, sound);
    scene.addController("Num4", num4);
    shared_ptr<Numbers_Controller> num5 = make_shared<Numbers_Controller>(scene, "myplayer", player, 4, audiomanager, sound);
    scene.addController("Num5", num5);

    scene.run();

    return 0;
}
