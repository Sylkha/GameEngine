#pragma once
#include <SDL_mixer.h>
#include <string>

using namespace std;
/** En esta clase manejaremos todo lo que necesitaremos para reproducir audio */
namespace gameEngine {
    class AudioManager{
        /** En caso de que todo se haya cargado correctamente, podremos reproducir audios */
        bool canPlayMusic;

        Mix_Music* music;
        Mix_Chunk* sound;
    public:
        AudioManager();
        ~AudioManager();

        /** En estas funciones mandaremos las rutas a la música o sonido que queramos reproducir */
        void PlayMusic(const char * routeMusic);
        void PlaySound(const char * routeSound);
    };
}