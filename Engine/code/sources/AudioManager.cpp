#include <SDL.h>
#include <SDL_mixer.h>
#include <AudioManager.h>

namespace gameEngine {
        AudioManager::AudioManager() {

            // Se inicializa SDL:

            if (SDL_Init(SDL_INIT_AUDIO) < 0)
            {
                SDL_Log("No se ha podido inicializar SDL2.");
            }
            else
            {
                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
                {
                    SDL_Log("No se ha podido inicializar el subsistema de audio.");
                }
                else
                {
                    // Se intenta cargar un sonido y una m�sica:

                    Mix_Music* music = nullptr;
                    Mix_Chunk* sound = nullptr;

                    if(
                            ! (music = Mix_LoadMUS("../../../Demo/assets/rainforest-ambience.ogg")) ||
                            ! (sound = Mix_LoadWAV("../../../Demo/assets/throw-knife.wav"))
                            )
                    {
                        SDL_Log("No se ha podido cargar el audio.");
                    }
                    else
                    {
                        // Se inicia la reproducci�n de la m�sica en bucle con un fundido:

                        Mix_FadeInMusic(music, -1, 4000); // separarlo en m�todos
                        // Mix_PlayChannel(-1, sound, 0);     // se reproduce un sonido en un canal libre                      

                     //   Mix_HaltMusic();
                     //   Mix_HaltChannel(-1);
                    }

                  //  if (music) Mix_FreeMusic(music); // liberar memoria
                  //  if (sound) Mix_FreeChunk(sound);


                   // Mix_CloseAudio(); // Para cerrar
                }
            }
        
    };
}
