#ifndef BULLS_H
#define BULLS_H

#include <string>

// Специальный ввод-сигнал «сдаюсь»
const std::string SURRENDER_CODE = "0000";

// Генерирует секретное число из 4 различных цифр
std::string generateSecret();

// Проверяет, что строка — корректная догадка: 4 символа, все — цифры, все различны
bool isValidGuess(const std::string& guess);

// Считает быков (на своей позиции) и коров (есть в секрете, но не на своей позиции)
void countBullsAndCows(const std::string& secret,
                       const std::string& guess,
                       int& bulls, int& cows);

// Подпрограмма угадывания: ведёт цикл ввода-подсказок до победы или сдачи
int playGuessing(const std::string& secret);

#endif // BULLS_H
