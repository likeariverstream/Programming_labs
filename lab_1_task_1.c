#include <stdio.h>
//Решение систем линейных алгебраических уравнений методом Гаусса
#define N 5

int main()
{
    double a[N][N] = {{-1, 4, 5, 3, 3},
                      {-1, 4, 3, -2, 5},
                      {0, 1, -1, 6, 3},
                      {-1, -1, 5, 0, -1},
                      {-1, 6, -3, -2, -3}};
    double b[N] = {9, 4, 30, 17, -6};
    int i, j, k;
    double temp;

    // Приведение матрицы к ступенчатому виду
    for (i = 0; i < N; i++)
    {
        // Поиск максимального элемента в столбце
        temp = a[i][i];
        k = i;
        for (j = i + 1; j < N; j++)
        {
            if (a[j][i] > temp)
            {
                temp = a[j][i];
                k = j;
            }
        }

        // Перестановка строк
        if (k != i)
        {
            for (j = i; j < N; j++)
            {
                temp = a[i][j];
                a[i][j] = a[k][j];
                a[k][j] = temp;
            }
            temp = b[i];
            b[i] = b[k];
            b[k] = temp;
        }

        // Приведение строки к ступенчатому виду
        for (j = i + 1; j < N; j++)
        {
            temp = a[j][i] / a[i][i];
            for (k = i; k < N; k++)
            {
                a[j][k] -= temp * a[i][k];
            }
            b[j] -= temp * b[i];
        }
    }

    // Проверка на совместность и единственность решения
    if (a[N - 1][N - 1] == 0)
    {
        printf("Система не имеет решений.\n");
        return 0;
    }
    for (i = N - 1; i >= 0; i--)
    {
        if (a[i][i] == 0)
        {
            printf("Система имеет бесконечное количество решений.\n");
            return 0;
        }
    }

    // Обратный ход метода Гаусса
    double x[N];
    x[N - 1] = b[N - 1] / a[N - 1][N - 1];
    for (i = N - 2; i >= 0; i--)
    {
        temp = 0;
        for (j = i + 1; j < N; j++)
        {
            temp += a[i][j] * x[j];
        }
        x[i] = (b[i] - temp) / a[i][i];
    }

    // Вывод решения на экран
    for (i = 0; i < N; i++)
    {
        printf("x%d = %f\n", i + 1, x[i]);
    }

    return 0;
}
