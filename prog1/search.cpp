#include "search.h"

bool hasMultipleOfCube(const int* arr, int n, int k)
{
    if (n <= 0 || arr == nullptr)
        return false;

    long long kCube = static_cast<long long>(k) * k * k;

    // Если k == 0, то k^3 == 0, а деление на 0 невозможно.
    // Кратность нулю не определена — считаем, что таких чисел нет.
    if (kCube == 0)
        return false;

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] % kCube == 0)
            return true;
    }
    return false;
}
