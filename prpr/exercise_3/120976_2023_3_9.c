#include <stdio.h>

int parne(int x[], int pocetx, int y[])
{
    int pocty = 0;
    for (int i = 0; i < pocetx; i++)
    {
        if (x[i] % 2 == 0)
        {
            y[pocty] = x[i];
            pocty++;
        }
    }
    return pocty;
}

int main()
{
    int x[] = {4, 7, 1, 3, 2, 5, 6}, y[100];
    int pocetx = sizeof(x)/sizeof(int);
    int pocty = parne(x, pocetx, y);
    printf("pocty: %d\n\n", pocty);
    return 0;
}
