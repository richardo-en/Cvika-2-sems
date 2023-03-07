#include <stdio.h>
int nasobky(int x[], int pocetx, int y[], int k);

int main()
{
    int x[10] = {4, 7, 10, 1, 3, 9, 2, 5, 8, 6};
    int y[100];
    int pocetx = 10;
    int pocety = nasobky(x, pocetx, y, 2);
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

int nasobky(int x[], int pocetx, int y[], int k)
{
    int count = 0;
    for (int i = 0; i < pocetx; i++)
    {
        if (x[i] % k == 0)
        {
            y[count] = x[i];
            count++;
        }
    }
    return count;
}