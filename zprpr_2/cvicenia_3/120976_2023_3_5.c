#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    char string[50];
    printf("Input number of how much characters you want to alocate\n");
    scanf(" %d", &n);
    int temporary_n = n - 1;
    char *allocated_string = malloc(n * (sizeof(char)));
    printf("Input string\n");
    scanf(" %s", &string);
    for (int i = 0; i < n; i++)
    {
        allocated_string[i] = string[temporary_n];
        temporary_n--;
    }
    for (int a = 0; a < n; a++)
    {
        printf("%c", allocated_string[a]);
    }

    return 0;
}