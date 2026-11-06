#include <iostream>
#include <limits>
#include "matrix.h"
#include "tasks.h"

// Функция для безопасного ввода целого числа
int safeInputInt(const std::string& prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> value)
        {
            // Очищаем буфер от лишних символов
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер
            std::cout << "Ошибка! Введите корректное целое число.\n";
        }
    }
}

void printMenu()
{
    std::cout << "\nМЕНЮ\n"
              << "1. Замена нулями (главная диагональ и выше), копирование нижней части\n"
              << "2. Сумма и ср. арифм. (побочная диагональ и выше)\n"
              << "3. Максимум на побочной диагонали и разница с главной\n"
              << "0. Выход\n"
              << "Выбор: ";
}

int main()
{
     std::setlocale(LC_ALL, "Russian");
    int n = 0;
    do {
        n = safeInputInt("Введите размер матрицы N (N > 0): ");
        if (n <= 0)
            std::cout << "Размер матрицы должен быть положительным числом.\n";
    } while (n <= 0);

    int** matrix = allocateMatrix(n);

    std::cout << "\nВвод исходной матрицы\n";
    inputMatrix(matrix, n);

    std::cout << "\nИсходная матрица\n";
    printMatrix(matrix, n);

    int choice = -1;
    while (choice != 0)
    {
        printMenu();
        choice = safeInputInt("");

        switch (choice)
        {
            case 1:
                task1(matrix, n);
                break;
            case 2:
                task2(matrix, n);
                break;
            case 3:
                task3(matrix, n);
                break;
            case 0:
                break;
            default:
                std::cout << "Неверный пункт меню. Попробуйте снова.\n";
        }
    }

    freeMatrix(matrix, n);
    return 0;
}
