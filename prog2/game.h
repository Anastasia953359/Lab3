#ifndef GAME_H
#define GAME_H

// Проверка корректности диапазона
bool isValidRange(int lo, int hi);

// Подсказка «больше/меньше»: возвращает -1, 0, +1
int compareGuess(int guess, int secret);

// Подсказка «холодно/тепло/горячо» по модулю разности.
// Возвращает строку-описание.
const char* proximityHint(int guess, int secret);

// Человек угадывает число, загаданное компьютером.
// Возвращает количество попыток.
int humanGuesses(int lo, int hi, int secret);

// Компьютер угадывает число, загаданное человеком (бинарный поиск).
// Возвращает количество попыток.
int computerGuesses(int lo, int hi);

#endif // GAME_H
