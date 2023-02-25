#include <stdio.h>
int *maximum(int *fisrt_pointer, int *second_pointer);

int main(int argc, char const *argv[])
{
    int first_number, second_number, *pointer;
    printf("Input 2 numbers\n");
    scanf(" %d", &first_number);
    scanf(" %d", &second_number);
    pointer = maximum(&first_number, &second_number);
    printf("%d", pointer);
    return 0;
}

int *maximum(int *fisrt_pointer, int *second_pointer)
{
    if (*fisrt_pointer > *second_pointer)
    {
        return fisrt_pointer;
    }
    else if (*second_pointer > *fisrt_pointer)
    {
        return second_pointer;
    }
    else
    {
        printf("Hodnota je rovnaka\n");
        return fisrt_pointer;
    }
}