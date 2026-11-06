#include "bulls.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Генерация числа
std::string generateSecret()
{
    std::string digits = "0123456789";
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::string secret;
    secret.reserve(4);

    int firstIdx = 1 + std::rand() % 9;
    secret.push_back(digits[firstIdx]);
    digits.erase(digits.begin() + firstIdx);

    for (int i = 0; i < 3; ++i)
    {
        int idx = std::rand() % static_cast<int>(digits.size());
        secret.push_back(digits[idx]);
        digits.erase(digits.begin() + idx);
    }

    return secret;
}

// Проверка корректности
bool isValidGuess(const std::string& guess)
{
    if (guess.size() != 4)
        return false;

    for (char c : guess)
        if (c < '0' || c > '9')
            return false;

    // все цифры различны
    std::string sorted = guess;
    std::sort(sorted.begin(), sorted.end());
    return std::adjacent_find(sorted.begin(), sorted.end()) == sorted.end();
}

// Подсчёт быков и коров
void countBullsAndCows(const std::string& secret,
                       const std::string& guess,
                       int& bulls, int& cows)
{
    bulls = 0;
    cows  = 0;

    for (int i = 0; i < 4; ++i)
    {
        if (guess[i] == secret[i])
        {
            ++bulls;
        }
        else if (secret.find(guess[i]) != std::string::npos)
        {
            ++cows;
        }
    }
}

// Основной цикл угадывания
int playGuessing(const std::string& secret)
{
    int attempts = 0;

    std::cout << "\nБыки и коровы\n"
              << "Компьютер загадал 4-значное число с различными цифрами.\n"
              << "Введите догадку (4 различные цифры).\n"
              << "Введите " << SURRENDER_CODE << ", чтобы сдаться.\n";

    while (true)
    {
        std::string guess;
        std::cout << "Попытка " << (attempts + 1) << ": ";
        std::cin >> guess;

        // --- СДАЧА: проверяем ДО валидации ---
        if (guess == SURRENDER_CODE)
        {
            std::cout << "Вы сдались. Загаданное число было: "
                      << secret << "\n"
                      << "Сделано попыток: " << attempts << ".\n";
            break;
        }

        if (!isValidGuess(guess))
        {
            std::cout << "Ошибка: нужно ровно 4 различные цифры "
                      << "(или " << SURRENDER_CODE << " для сдачи).\n";
            continue;
        }

        ++attempts;

        int bulls = 0, cows = 0;
        countBullsAndCows(secret, guess, bulls, cows);

        if (bulls == 4)
        {
            std::cout << "4 быка! Вы угадали число " << secret
                      << " за " << attempts << " попыток.\n";
            break;
        }

        std::cout << bulls << " бык(а/ов) и "
                  << cows  << " коров(а/ы).\n";
    }

    return attempts;
}
