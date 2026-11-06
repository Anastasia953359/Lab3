#ifndef MATRIX_H
#define MATRIX_H

// Выделение памяти под матрицу размера n x n
int** allocateMatrix(int n);

// Освобождение памяти
void freeMatrix(int** matrix, int n);

// Ввод матрицы с клавиатуры
void inputMatrix(int** matrix, int n);

// Вывод матрицы на экран
void printMatrix(int** matrix, int n);

#endif // MATRIX_H
