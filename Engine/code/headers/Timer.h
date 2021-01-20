#include <chrono>

namespace gameEngine
{
    class Timer
    {
        std::chrono::high_resolution_clock::time_point start_now;

    public:

        Timer();

        void start();

        uint32_t elapsed_seconds() const;
    };
}
