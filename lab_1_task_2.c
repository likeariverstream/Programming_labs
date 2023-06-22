#include <stdio.h>
#include <math.h>
//Численное интегрирование методами центральных прямоугольников
float f(float x)
{
    return x * x - log(x) + 3;
}

float rect(float a, float b, int n)
{
    float h, x, s;
    int i;
    s = 0.0;
    h = (b - a) / n;
    x = a + h / 2;
    for (i = 1; i <= n; i++)
    {
        s = s + f(x);
        x = x + h;
    }
    return s * h;
}

int main()
{
    float a = 1, b = 4;
    int n1 = 15, n2 = 20, n3 = 150, n4 = 650;
    printf("Integral of f(x) from %f to %f with n=%d: %f\n", a, b, n1, rect(a, b, n1));
    printf("Integral of f(x) from %f to %f with n=%d: %f\n", a, b, n2, rect(a, b, n2));
    printf("Integral of f(x) from %f to %f with n=%d: %f\n", a, b, n3, rect(a, b, n3));
    printf("Integral of f(x) from %f to %f with n=%d: %f\n", a, b, n4, rect(a, b, n4));
    return 0;
}
