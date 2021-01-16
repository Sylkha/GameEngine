
// Code released into the public domain
// in January 2019
// by Ángel

#include <Window.hpp>
#include <Sample_Renderer.hpp>
#include <AudioManager.h>

using namespace gameEngine;

int main()
{
    // Se crea una ventana:

    Window window("TEST", 1280, 720/*, true*/);

    window.enable_vsync();

    // Se crea un renderer que usa OpenGL Toolkit:

    Sample_Renderer renderer(window);

    AudioManager audiomanager;
    // Se ejecuta el bucle principal:

    bool exit = false;

    while (!exit)
    {
        Window::Event event;

        while (window.poll(event))
        {
            switch (event.type)
            {
            case Window::Event::CLOSE:
            {
                exit = true;
                break;
            }

            case Window::Event::KEY_PRESSED:
            {
                if (event.data.keyboard.key_code == Keyboard::KEY_ESCAPE)
                {
                    exit = true;
                }

                break;
            }
            }
        }

        renderer.render();
    }

    return 0;
}
