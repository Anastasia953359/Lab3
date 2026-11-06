#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "timer.h"

// Процедура выбора режима
int chooseMode()
{
    int mode = 0;
    std::cout << "1) Пользователь угадывает число\n"
              << "2) Компьютер угадывае число\n"
              << "0) Выход\n"
              << "Выбор: ";
    std::cin >> mode;
    return mode;
}

int main()
{
    std::setlocale(LC_ALL, "Russian");
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int lo = 0, hi = 0;
    std::cout << "Введите границы диапазона (lo hi): ";
    if (!(std::cin >> lo >> hi) || !isValidRange(lo, hi))
    {
        std::cout << "Некорректный диапазон.\n";
        return 1;
    }

    bool keepPlaying = true;
    while (keepPlaying)
    {
        int mode = chooseMode();
        GuessTimer timer;

        if (mode == 1)
        {
            int secret = lo + std::rand() % (hi - lo + 1);
            timer.start();
            humanGuesses(lo, hi, secret);
            timer.stop();
            std::cout << "Время угадывания: "
                      << timer.elapsedSeconds() << " с.\n";
        }
        else if (mode == 2)
        {
            timer.start();
            computerGuesses(lo, hi);
            timer.stop();
            std::cout << "Время угадывания компьютером: "
                      << timer.elapsedSeconds() << " с.\n";
        }
        else if (mode == 0)
        {
            keepPlaying = false;
        }
        else
        {
            std::cout << "Неизвестный режим.\n";
        }
    }

    std::cout << "До свидания!\n";
    return 0;
}
