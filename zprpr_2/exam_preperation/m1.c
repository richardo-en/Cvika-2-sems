#include <stdio.h>

#define nas(z) z * z

static int y = 1;

int x;

extern double f;

double fun(void)
{
    return (nas(x + y) + f);
}