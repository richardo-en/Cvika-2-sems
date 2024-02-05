#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a, b, c;
    int cycles;
    scanf(" %d", &cycles);
    for (int i = 0; i < cycles; i++)
    {
        scanf(" %f", &c);
        if (i == 0)
        {
            a = c;
            b = c;
        }
        else if (c < a)
        {
            a = c;
        }
        else if (c > b)
        {
            b = c;
        }
    }
    printf("Min: %.2f\n", a);
    printf("Max: %.2f\n", b);
    return 0;
}