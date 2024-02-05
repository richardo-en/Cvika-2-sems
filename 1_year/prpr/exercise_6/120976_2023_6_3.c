#include <stdio.h>
#include <stdlib.h>

void alokuj_2D_pole(int ***x, int *m, int *n)
{
    int c;
    while ((*m) <= 0 || (*n) <= 0)
    {
        scanf(" %d", m);
        scanf(" %d", n);
    }
    (*x) = malloc(sizeof(int *) * (*m));
    for (int i = 0; i < (*m); i++)
    {
        (*x)[i] = malloc(sizeof(int) * (*n));
        for (int a = 0; a < (*n); a++)
        {
            scanf(" %d", &c);
            (*x)[i][a] = c;
        }
    }
}

void vypis_2D_pole(int ***x, int m, int n)
{

    for (int i = 0; i < m; i++)
    {
        for (int a = 0; a < n; a++)
        {
            printf("%d ", (*x)[i][a]);
        }
        printf("\n");
    }
}

void uvolni(int ***x, int m, int n)
{

    for (int i = 0; i < m; i++)
    {
        free((*x)[i]);
    }
    free((*x));
}

int main(int argc, char const *argv[])
{
    int m = -1, n = -1, **x = NULL;
    alokuj_2D_pole(&x, &m, &n);
    vypis_2D_pole(&x, m, n);
    uvolni(&x, m, n);
    return 0;
}