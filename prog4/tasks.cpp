#include "tasks.h"
#include "matrix.h"
#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <vector>

// 1
void task1(int** matrix, int n)
{
    int** lowerMatrix = allocateMatrix(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            lowerMatrix[i][j] = 0; // Инициализация

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j <= i) // На главной диагонали и выше
                matrix[i][j] = 0;
            else        // Ниже главной диагонали
                lowerMatrix[i][j] = matrix[i][j];
        }
    }

    std::cout << "Матрица после замены:\n";
    printMatrix(matrix, n);
    std::cout << "Скопированная нижняя часть:\n";
    printMatrix(lowerMatrix, n);

    freeMatrix(lowerMatrix, n);
}

// 2
void task2(int** matrix, int n)
{
    long long sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j >= n - 1 - i) // Побочная диагональ и выше
            {
                sum += matrix[i][j];
                count++;
            }
        }
    }
    std::cout << "Сумма: " << sum << "\n";
    if (count > 0)
        std::cout << "Среднее арифметическое: " << (double)sum / count << "\n";
}

// 3
void task3(int** matrix, int n)
{
    int maxSide = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        int val = matrix[i][n - 1 - i];
        if (val > maxSide) maxSide = val;
    }
    std::cout << "Максимальный элемент на побочной диагонали: " << maxSide << "\n";
    std::cout << "Разницы с элементами главной диагонали:\n";
    for (int i = 0; i < n; ++i)
        std::cout << "Элемент " << matrix[i][i] << " - " << maxSide << " = " << matrix[i][i] - maxSide << "\n";
}


