#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number, result = 1;
    scanf(" %d", &number);
    while (number < 0)
    {
        scanf(" %d", &number);
    }

    for (int i = 1; i < number + 1; i++)
    {
        result *= i;
    }
    printf(" %d\n\n", result);
    return 0;
}