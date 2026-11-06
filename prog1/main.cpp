#include <iostream>
#include "search.h"
#include <locale>

// Процедура ввода массива
void inputArray(int* arr, int n)
{
    std::cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}

// Процедура вывода массива
void printArray(const int* arr, int n)
{
    std::cout << "Массив: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    std::setlocale(LC_ALL, "Russian");
    int n = 0;
    std::cout << "Введите размер таблицы: ";
    std::cin >> n;

    if (n <= 0)
    {
        std::cout << "Некорректный размер массива.\n";
        return 1;
    }

    int* arr = new int[n];

    inputArray(arr, n);
    printArray(arr, n);

    int k = 0;
    std::cout << "Введите k: ";
    std::cin >> k;

    if (hasMultipleOfCube(arr, n, k))
        std::cout << "Да, в таблице есть число, кратное k^3 = "
                  << static_cast<long long>(k) * k * k << ".\n";
    else
        std::cout << "Нет, чисел, кратных k^3 = "
                  << static_cast<long long>(k) * k * k << ", нет.\n";

    delete[] arr;
    return 0;
}
