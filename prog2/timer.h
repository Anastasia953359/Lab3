#ifndef TIMER_H
#define TIMER_H

#include <chrono>

// Класс-обёртка над std::chrono::steady_clock для замера времени угадывания.
// Использование в процедурном стиле: start() -> stop() -> elapsedSeconds().
class GuessTimer
{
public:
    void start();
    void stop();
    double elapsedSeconds() const;   // секунды с точностью до долей

private:
    std::chrono::steady_clock::time_point begin_{};
    std::chrono::steady_clock::time_point end_{};
    bool running_ = false;
};

#endif // TIMER_H
