#include "matrix.h"
#include <iostream>
#include <limits>

int** allocateMatrix(int n)
{
    int** mat = new int*[n];
    for (int i = 0; i < n; ++i)
        mat[i] = new int[n];
    return mat;
}

void freeMatrix(int** matrix, int n)
{
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

void inputMatrix(int** matrix, int n)
{
    std::cout << "¬ведите элементы матрицы (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << "Ёлемент [" << i << "][" << j << "]: ";
            while (!(std::cin >> matrix[i][j]))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ќшибка! ¬ведите целое число: ";
            }
        }
    }
}

void printMatrix(int** matrix, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }
}
