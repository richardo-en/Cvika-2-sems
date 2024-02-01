#include <stdio.h>
#include <stdlib.h>
#define N 20

void magicky(int square[N][N], int n)
{
    int *values;
    values = malloc(sizeof(int) * (n + 1));
    values[n] = 0;
    values[n+1] = 0;
    for (int i = 0; i < n; i++)
    {
        values[i] = 0;
        for (int a = 0; a < n; a++)
        {
            values[i] += square[i][a];
        }
        values[n] += square[i][i];
        values[n+1] += square[i][n-i];
    }
    int equal = 0;
    for (int i = 1; i < (n+1); i++)
    {
        if (values[i] != values[0])
        {
            equal = 1;
            break;
        }
        
    }
    equal == 1 ? printf("Square is not magic\n") : printf("Square is magic\n");
    free(values);
}

int main(int argc, char const *argv[])
{
    int square[N][N], n, c;
    scanf("%d", &n);
    if (n <= N)
    {
        for (int i = 0; i < n; i++)
        {
            for (int a = 0; a < n; a++)
            {
                scanf(" %d", &c);
                square[i][a] = c;
            }
        }
        magicky(square, n);
    }
    else
    {
        printf("Square is bigger than defined size.\n");
    }

    return 0;
}