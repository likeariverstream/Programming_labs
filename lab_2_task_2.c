#include <stdio.h>
#include <math.h>
//решение нелинейного уравнения методом половинного деления:
float f(float x);
int sign(float x);
float bisec(float a, float b, float e, float e1);

int main(void)
{
    float a = -2.0, b = -1.0, e = 0.0001, e1 = 0.0001;
    printf("x = %f", bisec(a, b, e, e1));
    return 0;
}

float f(float x)
{
    return log(x + 3) + sin(x + 1);
}

int sign(float x)
{
    int res = 0;
    if (x < 0)
        res = -1;
    if (x > 0)
        res = 1;
    return res;
}

float bisec(float a, float b, float e, float e1)
{
    float x;
    while (b - a > e)
    {
        x = (a + b) / 2;
        if (fabs(f(x)) < e1)
            break;
        if (sign(f(a)) == sign(f(x)))
            a = x;
        else
            b = x;
    }
    return x;
}
