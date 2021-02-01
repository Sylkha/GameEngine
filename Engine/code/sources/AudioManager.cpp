

#include <SDL.h>
#include <AudioManager.h>

namespace gameEngine {
    AudioManager::AudioManager() {

        // Se inicializa SDL:

        if (SDL_Init(SDL_INIT_AUDIO) < 0)
        {
            SDL_Log("No se ha podido inicializar SDL2.");
            canPlayMusic = false;
        }
        else
        {
            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
            {
                SDL_Log("No se ha podido inicializar el subsistema de audio.");
                canPlayMusic = false;
            }
            else
            {
                canPlayMusic = true;
                music = nullptr;
                sound = nullptr;
            }
        }
    }

    void AudioManager::PlayMusic(const char * routeMusic) {
        if (canPlayMusic == false) return;
        if (!(music = Mix_LoadMUS(routeMusic)))
        {
            SDL_Log("No se ha podido cargar el audio.");
        }
        else
        {
            /** Se inicia la reproducción de la música en bucle con un fundido: */
            Mix_FadeInMusic(music, -1, 4000);
        }
    }
    void AudioManager::PlaySound(const char* routeSound) {
        if (canPlayMusic == false) return;
        if (!(sound = Mix_LoadWAV(routeSound)))
        {
            SDL_Log("No se ha podido cargar el audio.");
        }
        else
        {
            /** se reproduce un sonido en un canal libre */
            Mix_PlayChannel(-1, sound, 0);
        }     
    }
    
    AudioManager::~AudioManager() {
        /** Liberar memoria */
        if (music) Mix_FreeMusic(music); 
        if (sound) Mix_FreeChunk(sound);

        /** Para cerrar */
        Mix_CloseAudio(); 
    }
}
