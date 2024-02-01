#include <stdio.h>

extern int x;

extern double fun(void);

static float y = 5.05;

double f;

void main()
{
    x = 2;
    f = 1.5;
    printf("%lf", y + fun());
}