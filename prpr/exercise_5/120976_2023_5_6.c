#include <stdio.h>
#include <stdlib.h>

int alokuj_1D_pole(int **x){
    int m = -1, c;;
    while (m <= 0)
    {
        scanf("%d", &m);
    }
    (*x) = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
    {
        scanf(" %d", &c);
        (*x)[i] = c;
    }
    return m;
}

void vypis_1D_pole(int **x, int count){
    for (int i = 0; i < count; i++)
    {
        i == (count-1) ? printf("%d\n", (*x)[i]) : printf("%d,", (*x)[i]);
    }
}

void maximum_poz(int **x, int count){
    int c;
    for (int i = 0; i < count; i++)
    {
        if (i == 0)
        {
            c = (*x)[i];
        }else{
            if ((*x)[i] > c)
            {
                c = (*x)[i];
            }
        }
    }
    printf("max: %d\n", c);
}

void minimum_poz(int **x, int count){
    int c;
    for (int i = 0; i < count; i++)
    {
        if (i == 0)
        {
            c = (*x)[i];
        }else{
            if ((*x)[i] < c)
            {
                c = (*x)[i];
            }
        }
    }
    printf("min: %d\n", c);
}

void uvolni(int **x){
    free((*x));
}

int main(int argc, char const *argv[])
{
    int *x, count;
    count = alokuj_1D_pole(&x);
    vypis_1D_pole(&x, count);
    maximum_poz(&x, count);
    minimum_poz(&x, count);
    uvolni(&x);
    return 0;
}