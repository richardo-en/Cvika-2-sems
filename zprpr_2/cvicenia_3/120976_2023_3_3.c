#include <stdio.h>
int delitele(int x[], int pocetx, int y[], int k);

int main()
{
    int x[10] = {4, 7, 10, 2, 3, 9, 6, 5, 8, 12};
    int y[100];
    int pocetx = 10;
    int pocety = delitele(x, pocetx, y, 24);
    printf("pocety = %d\ny = {", pocety);
    for (int i = 0; i < pocety; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", y[i]);
    }
    printf("}\n");
    return 0;
}

int delitele(int x[], int pocetx, int y[], int k)
{
    int count = 0;
    for (int i = 0; i < pocetx; i++)
    {
        if (k % x[i] == 0)
        {
            y[count] = x[i];
            count++;
        }
    }
    return count;
    return count;
}