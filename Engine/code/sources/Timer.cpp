// Code released into the public domain
// in January 2021
// by Silvia

#include <SDL.h>
#include <cstdint>
#include <iostream>
#include "Timer.h"

typedef std::chrono::high_resolution_clock Clock;
namespace gameEngine
{
    Timer::Timer() {
       
    }

    void Timer::start()
    {
        start_now = Clock::now();
    }
    
    uint32_t Timer::elapsed_seconds() const
    {
        return (Clock::now() - start_now).count();
    }
    
}