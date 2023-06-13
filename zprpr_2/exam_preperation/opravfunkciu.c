#include <stdio.h>

static float x = 5;

double pol1(double x)
{
    return (x * x + 3);
}

void vypis(double d, double h, double k, double pol1())
{
    double x;
    for (x = d; x <= h; x += k)
        printf("%4.2lf, %4.2lf\n", x, pol1(x));
}

void main()
{
    vypis(1.0, 2.0, 0.2, &pol1);
}