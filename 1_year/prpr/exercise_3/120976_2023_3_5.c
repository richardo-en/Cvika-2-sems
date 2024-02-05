#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number_one, number_two, cycles, lower_number;
    scanf(" %d %d", &number_one, &number_two);
    if (number_one > number_two)
    {
        lower_number = number_two;
        cycles = number_one - number_two;
    }
    else
    {
        lower_number = number_one;
        cycles = number_two - number_one;
    }

    for (int i = 0; i < cycles; i++)
    {
        if ((lower_number + i) % 3 == 0)
        {
            printf("%d\n", (lower_number + i));
        }
    }
    printf("\n\n");
    return 0;
}