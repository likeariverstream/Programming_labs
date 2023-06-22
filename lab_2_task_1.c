#include <stdio.h>
#include <math.h>
//Численное решение задачи Коши
#define n 20

float f(float, float);
float ya(float);

int main(void)
{
    float a = M_PI / 4, b = M_PI / 3, h = (b - a) / (n - 1), x, y[n];
    int k;

    y[0] = 0.5; // начальное условие
    for (k = 1; k < n; k++) // метод Эйлера
    {
        x = a + k * h;
        y[k] = y[k - 1] + h * f(x, y[k - 1]);
    }

    // сравнение с аналитическим решением
    for (k = 0; k < n; k++)
    {
        x = a + k * h;
        printf("numerical = %5.2f \t\t analytical = %5.2f\n", y[k], ya(x));
    }

    return 0;
}

float f(float x, float y) // правая часть
{
    return cos(x) * cos(x) - y * tan(x);
}

float ya(float x) // аналитическое решение
{
    return sin(x / 2) * sin(x / 2);
}
