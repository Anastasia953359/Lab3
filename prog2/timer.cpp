#include "timer.h"

void GuessTimer::start()
{
    begin_ = std::chrono::steady_clock::now();
    running_ = true;
}

void GuessTimer::stop()
{
    if (running_)
    {
        end_ = std::chrono::steady_clock::now();
        running_ = false;
    }
}

double GuessTimer::elapsedSeconds() const
{
    auto finish = running_ ? std::chrono::steady_clock::now() : end_;
    std::chrono::duration<double> diff = finish - begin_;
    return diff.count();
}
