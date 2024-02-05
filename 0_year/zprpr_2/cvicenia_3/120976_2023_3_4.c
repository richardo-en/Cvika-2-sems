#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *cislo1 = malloc(sizeof(int));
    int *cislo2 = malloc(sizeof(int));
    int cislo3;

    printf("Input 3 numbers in one line -> \"1 2 3\"\n");
    scanf(" %d %d %d", cislo1, cislo2, &cislo3);
    printf("%d + %d + %d = %d", *cislo1, *cislo2, cislo3, (*cislo1 + *cislo2 + cislo3));
    return 0;
}