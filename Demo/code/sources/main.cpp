// Code released into the public domain
// in January 2021
// by Silvia

#include <Window.hpp>
#include <Scene.h>
#include <AudioManager.h>
#include <Player_Controller.h>
#include "Numbers_Controller.h"
#include "Limits_Controller.h"

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

    shared_ptr<Numbers_Controller> num1 = make_shared<Numbers_Controller>(scene, "myplayer", *player.get(), 0, audiomanager, sound);
    scene.addController("Num1", num1);
    shared_ptr<Numbers_Controller> num2 = make_shared<Numbers_Controller>(scene, "myplayer", *player.get(), 1, audiomanager, sound);
    scene.addController("Num2", num2);
    shared_ptr<Numbers_Controller> num3 = make_shared<Numbers_Controller>(scene, "myplayer", *player.get(), 2, audiomanager, sound);
    scene.addController("Num3", num3);
    shared_ptr<Numbers_Controller> num4 = make_shared<Numbers_Controller>(scene, "myplayer", *player.get(), 3, audiomanager, sound);
    scene.addController("Num4", num4);
    shared_ptr<Numbers_Controller> num5 = make_shared<Numbers_Controller>(scene, "myplayer", *player.get(), 4, audiomanager, sound);
    scene.addController("Num5", num5);

    shared_ptr<Limits_Controller> lim1 = make_shared<Limits_Controller>(scene, "myplayer", *player.get(), Left);
    scene.addController("Rec1", lim1);
    shared_ptr<Limits_Controller> lim2 = make_shared<Limits_Controller>(scene, "myplayer", *player.get(), Up);
    scene.addController("Rec2", lim2);
    shared_ptr<Limits_Controller> lim3 = make_shared<Limits_Controller>(scene, "myplayer", *player.get(), Right);
    scene.addController("Rec3", lim3);
    shared_ptr<Limits_Controller> lim4 = make_shared<Limits_Controller>(scene, "myplayer", *player.get(), Down);
    scene.addController("Rec4", lim4);

    scene.run();

    return 0;
}
