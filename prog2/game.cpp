#include "game.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

bool isValidRange(int lo, int hi)
{
    return lo <= hi;
}

int compareGuess(int guess, int secret)
{
    if (guess < secret) return -1;
    if (guess > secret) return  1;
    return 0;
}

const char* proximityHint(int guess, int secret)
{
    int diff = std::abs(guess - secret);
    if (diff == 0)  return "в точку!";
    if (diff <= 2)  return "горячо";
    if (diff <= 5)  return "тепло";
    if (diff <= 10) return "прохладно";
    return "холодно";
}

int humanGuesses(int lo, int hi, int secret)
{
    int attempts = 0;
    std::cout << "\nРежим: вы угадываете\n"
              << "Диапазон: [" << lo << "; " << hi << "]\n";

    while (true)
    {
        std::cout << "Ваш вариант: ";
        int guess = 0;
        if (!(std::cin >> guess))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Введите целое число!\n";
            continue;
        }

        if (guess < lo || guess > hi)
        {
            std::cout << "Число вне диапазона, попробуйте снова.\n";
            continue;
        }

        ++attempts;
        int cmp = compareGuess(guess, secret);

        if (cmp == 0)
        {
            std::cout << "Верно! Вы угадали за " << attempts << " попыток.\n";
            break;
        }

        std::cout << (cmp < 0 ? "Загаданное число БОЛЬШЕ. " : "Загаданное число МЕНЬШЕ. ")
                  << "(" << proximityHint(guess, secret) << ")\n";
    }
    return attempts;
}


int computerGuesses(int lo, int hi)
{
    std::cout << "\n=== Режим: компьютер угадывает ===\n"
              << "Загадайте число в диапазоне [" << lo << "; " << hi << "].\n"
              << "Отвечайте: '<' — ваше число меньше, '>' — больше, '=' — угадал.\n";

    int attempts = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        ++attempts;

        std::cout << "Попытка " << attempts << ": " << mid
                  << " ? (<, >, =): ";

        char ans = '?';
        if (!(std::cin >> ans))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ожидался один из символов < > =.\n";
            --attempts;
            continue;
        }

        if (ans == '=')
        {
            std::cout << "Компьютер угадал число " << mid
                      << " за " << attempts << " попыток.\n";
            return attempts;
        }
        else if (ans == '<')
        {
            hi = mid - 1;
        }
        else if (ans == '>')
        {
            lo = mid + 1;
        }
        else
        {
            std::cout << "Некорректный ответ, попробуйте снова.\n";
            --attempts;
        }
    }

    std::cout << "Ответы противоречивы — число угадать невозможно.\n";
    return attempts;
}
